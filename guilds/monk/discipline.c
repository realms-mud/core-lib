//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("monastic discipline");
    Description("The foundations of breath, awareness, focus, and practice "
        "that support advancement through the monk guild.");
    Source("monk");
    addPrerequisite("monk", ([ "type":"guild", "value":({ "monk" }) ]));

    string *items = ({
        "/guilds/monk/discipline/root.c",
        "/guilds/monk/discipline/disciplined-breath.c",
        "/guilds/monk/discipline/students-awareness.c",
        "/guilds/monk/discipline/disciples-insight.c",
        "/guilds/monk/discipline/adepts-focus.c",
        "/guilds/monk/discipline/inner-discipline.c",
        "/guilds/monk/discipline/mastery-of-fundamentals.c"
    });
    foreach(string item in items)
    {
        addResearchElement(item);
    }
    string *lessons = ({
        "/guilds/monk/discipline/initiates-discipline.c",
        "/guilds/monk/discipline/steady-practice.c",
        "/guilds/monk/discipline/teachers-recognition.c",
        "/guilds/monk/discipline/controlled-expenditure.c",
        "/guilds/monk/discipline/adepts-trial.c",
        "/guilds/monk/discipline/senior-disciples-trial.c",
        "/guilds/monk/discipline/master-candidates-trial.c",
        "/guilds/monk/discipline/masters-trial.c"
    });
    foreach(string lesson in lessons)
    {
        addResearchElement(lesson);
    }
    TreeRoot(items[0]);
    for (int index = 1; index < sizeof(items); index++)
    {
        addChild(items[index], items[index - 1]);
    }
    addChild(lessons[0], items[0]);
    addChild(lessons[1], lessons[0]);
    addChild(lessons[1], items[1]);
    addChild(lessons[2], lessons[1]);
    addChild(lessons[3], lessons[2]);
    addChild(lessons[3], items[2]);
    addChild(lessons[4], lessons[2]);
    addChild(lessons[4], items[3]);
    for (int index = 5; index < sizeof(lessons); index++)
    {
        addChild(lessons[index], lessons[2]);
        addChild(lessons[index], items[index - 1]);
    }
}
