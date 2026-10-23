//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/realizations/researchTeacher.c";

protected void Setup()
{
    Name("sora");
    short("Sister Sora, instructor of the monastic blades");
    description("Sora alternates precise paired-blade forms with slow, "
        "committed odachi strokes and close kama and claw drills. "
        "She teaches recognized monks to "
        "respect the recovery and vulnerabilities of each style.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("swordsman", 30);
    addRelationshipInteraction("training.completed",
        ([ "respect":2, "admiration":1 ]));
    foreach(string discipline in ({ "paired-swords", "odachi",
        "kama", "claw" }))
    {
        object tree = getService("research")->researchTree(
            "/guilds/monk/" + discipline + ".c");
        foreach(object item in m_indices(tree->getFlattenedResearchTree()))
        {
            if (item->query("research type") != "tree root")
            {
                addLesson(program_name(item), ([]), "");
            }
        }
    }
}
