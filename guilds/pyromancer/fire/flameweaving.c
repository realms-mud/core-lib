//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Flameweaving");
    addSpecification("source", "pyromancer");
    addSpecification("description", "This research provides the user with "
        "knowledge of weaving fire into complex patterns, enhancing the power "
        "of steam and heat-based attacks.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "pyromancer",
            "value": 9
        ]));

    addPrerequisite("/guilds/pyromancer/fire/searing-blast.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Searing Blast": 25,
        "Blazing Convergence": 25,
        "Molten Core": 25,
        "Scorching Tide": 25,
    ]));
    addSpecification("affected research type", "percentage");
}
