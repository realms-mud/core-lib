//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";

int *MonkPromotionLevels = ({ 10, 20, 30, 40, 55, 70 });

/////////////////////////////////////////////////////////////////////////////
void TeachMonkTrialLesson(object student, object *teachers, string path)
{
    if (!student.isResearched(path))
    {
        string treePath = regreplace(path, "/[^/]+\\.c$", ".c");
        object tree = getService("research")->researchTree(treePath);
        foreach(string parent in tree.getParents(path))
        {
            TeachMonkTrialLesson(student, teachers, parent);
        }
        object item = tree.getResearchItem(path);
        foreach(string prerequisite, mapping requirement in
            item.getPrerequisites())
        {
            if (requirement["type"] == "research")
            {
                TeachMonkTrialLesson(student, teachers, prerequisite);
            }
        }
        object instructor = 0;
        foreach(object teacher in teachers)
        {
            if (teacher.teachesResearch(path))
            {
                instructor = teacher;
            }
        }
        ExpectTrue(objectp(instructor), "Instructor for " + path);
        if (instructor)
        {
            ExpectTrue(student.learnResearchFrom(instructor, path), path);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////
void CompleteMonkUpperTrial(object student, object lian, object ren, int stage)
{
    string *trials = ({ "senior-disciples-trial", "master-candidates-trial",
        "masters-trial" });
    string path = "/guilds/monk/discipline/" + trials[stage] + ".c";
    object trial = getService("research")->researchObject(path);
    mapping route = trial.getPrerequisites()["specialist mastery"]
        ["prerequisites"][0];
    foreach(string lesson, mapping requirement in route)
    {
        if (requirement["type"] == "research")
        {
            TeachMonkTrialLesson(student, ({ lian, ren }), lesson);
        }
    }
    mapping practice = route["qualifying practice"];
    for (int use = 0; use < practice["value"]; use++)
    {
        ExpectTrue(mappingp(student.recordObservation(([
            "type":practice["criteria"]["type"],
            "context":([
                "research":practice["criteria"]["research"],
                "qualifying opponent":1
            ])
        ]), 1)));
    }
    ExpectTrue(student.learnResearchFrom(ren, path), path);
}
