//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Fire Blast");
    addSpecification("source", "pyromancer");
    addSpecification("description", "This research provides the user with "
        "deeper understanding of how to focus and intensify fire-based attacks. "
        "By studying the principles of combustion and thermal dynamics, the "
        "pyromancer learns to deliver more powerful impacts with their "
        "offensive fire magic.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "pyromancer",
            "value": 3
        ]));

    addPrerequisite("/guilds/pyromancer/fire/spark.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Spark": 25,
        "Heat Wave": 25,
        "Talons of Fire": 25,
        "Burning Grasp": 25,
        "Burning Touch": 25,
        "Smoke Screen": 25,
        "Battering Flames": 25,
        "Backdraft": 25,
        "Daggers of Fire": 25,
        "Immolating Depths": 25,
        "Immolating Embrace": 25,
        "Hellfire Orb": 25,
    ]));
    addSpecification("affected research type", "percentage");
}
