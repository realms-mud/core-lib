//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";
virtual inherit "/lib/core/prerequisites.c";

private string *lessons = ({});
private mapping lessonRequirements = ([]);
private mapping lessonTrees = ([]);
private int deferredLessonLoading;

/////////////////////////////////////////////////////////////////////////////
protected nomask void deferLessonLoading()
{
    deferredLessonLoading = 1;
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void addLessonTree(string treePath, string *excluded)
{
    if (!getService("research")->researchFileExists(treePath) ||
        !pointerp(excluded) || member(lessonTrees, treePath))
    {
        raise_error("ERROR - researchTeacher: Invalid or duplicate "
            "lesson tree.\n");
    }
    lessonTrees[treePath] = excluded + ({});
}

/////////////////////////////////////////////////////////////////////////////
protected nomask void addLesson(string researchItem, mapping requirements,
    string explanation)
{
    if (!(deferredLessonLoading ?
            getService("research")->researchFileExists(researchItem) :
            getService("research")->validResearch(researchItem)) ||
        !mappingp(requirements) || !stringp(explanation) ||
        (sizeof(requirements) && !sizeof(explanation)) ||
        member(lessons, researchItem) >= 0)
    {
        raise_error("ERROR - researchTeacher: Invalid or duplicate lesson.\n");
    }
    else
    {
        foreach(string key in m_indices(requirements))
        {
            if (!addPrerequisite(key, requirements[key], researchItem))
            {
                raise_error(sprintf("ERROR - researchTeacher: Invalid "
                    "requirement '%s' for %s.\n", key, researchItem));
            }
        }
        lessons += ({ researchItem });
        lessonRequirements[researchItem] = explanation;
    }
}

/////////////////////////////////////////////////////////////////////////////
public nomask string *teachableResearch()
{
    string *ret = lessons + ({});
    foreach(string treePath, string *excluded in lessonTrees)
    {
        ret += (getService("lessons")->lessonPaths(treePath) - excluded) - ret;
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int teachesResearch(string researchItem)
{
    int ret = member(lessons, researchItem) >= 0;
    foreach(string treePath, string *excluded in lessonTrees)
    {
        if (!ret && member(excluded, researchItem) < 0)
        {
            ret = member(getService("lessons")->lessonPaths(treePath),
                researchItem) >= 0;
        }
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public string teachingGuild()
{
    return 0;
}

/////////////////////////////////////////////////////////////////////////////
public nomask string lessonRefusal(object student, string researchItem)
{
    string ret = "";
    object item = 0;
    int present = objectp(student) && student != this_object() &&
        environment(this_object()) &&
        environment(student) == environment(this_object());
    if (present && teachesResearch(researchItem))
    {
        item = getService("lessons")->lessonObject(researchItem);
    }
    if (!present)
    {
        ret = "You must be in the same room as your teacher.";
    }
    else if (!item)
    {
        ret = "That lesson is not part of this teacher's curriculum.";
    }
    else if (student->isResearched(researchItem) ||
        student->equivalentIsResearched(researchItem))
    {
        ret = "You already know that lesson.";
    }
    else if (student->isResearching(researchItem))
    {
        ret = "You are already studying that lesson.";
    }
    else if (!student->canResearch(researchItem))
    {
        ret = "You do not meet this lesson's research prerequisites.\n" +
            item->displayPrerequisites("none", getService("configuration"));
    }
    else if (sizeof(lessonRequirements[researchItem]) &&
        !checkPrerequisites(student, researchItem, this_object()))
    {
        ret = lessonRequirements[researchItem];
    }
    else if (item->query("research type") == "points" &&
        student->researchPoints() < item->query("research cost"))
    {
        ret = sprintf("You need %d research points for this lesson.",
            item->query("research cost"));
    }
    return ret;
}

/////////////////////////////////////////////////////////////////////////////
public nomask int canTeachResearch(object student, string researchItem)
{
    return !sizeof(lessonRefusal(student, researchItem));
}
