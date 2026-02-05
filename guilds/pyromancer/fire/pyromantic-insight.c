//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Pyromantic Insight");
    addSpecification("source", "pyromancer");
    addSpecification("description", "This research provides the user with "
        "profound insight into the nature of fire, greatly enhancing all "
        "pyromantic abilities.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "pyromancer",
            "value": 57
        ]));

    addPrerequisite("/guilds/pyromancer/fire/inferno-mastery.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Spark": 25,
        "Fire Dominion": 25,
        "Apocalypse": 25,
    ]));
    addSpecification("affected research type", "percentage");
}
