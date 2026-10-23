//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";
virtual inherit "/lib/core/prerequisites.c";

private string *lessons = ({});
private mapping lessonRequirements = ([]);

/////////////////////////////////////////////////////////////////////////////
protected nomask void addLesson(string researchItem, mapping requirements,
    string explanation)
{
    if (!getService("research")->validResearch(researchItem) ||
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
    return lessons + ({});
}

/////////////////////////////////////////////////////////////////////////////
public nomask int teachesResearch(string researchItem)
{
    return member(lessons, researchItem) >= 0;
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
    object item = getService("research")->researchObject(researchItem);
    if (!objectp(student) || student == this_object() ||
        !environment(this_object()) ||
        environment(student) != environment(this_object()))
    {
        ret = "You must be in the same room as your teacher.";
    }
    else if (!teachesResearch(researchItem) || !item)
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
