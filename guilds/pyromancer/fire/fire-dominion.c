//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Fire Dominion");
    addSpecification("source", "pyromancer");
    addSpecification("description", "This research provides the user with "
        "absolute dominion over fire, the ultimate enhancement to fire magic.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "pyromancer",
            "value": 63
        ]));

    addPrerequisite("/guilds/pyromancer/fire/pyromantic-insight.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Spark": 35,
        "Apocalypse": 35,
    ]));
    addSpecification("affected research type", "percentage");
}
