//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Blazing Convergence");
    addSpecification("source", "pyromancer");
    addSpecification("description", "This research provides the user with "
        "knowledge of converging multiple streams of fire into devastating attacks.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "pyromancer",
            "value": 17
        ]));

    addPrerequisite("/guilds/pyromancer/fire/flameweaving.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Searing Blast": 25,
        "Molten Core": 25,
        "Scorching Tide": 25,
    ]));
    addSpecification("affected research type", "percentage");
}
