//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Blazing Focus");
    addSpecification("source", "pyromancer");
    addSpecification("description", "This research provides the user with "
        "knowledge of focusing the heat of their flames to a razor's edge, "
        "enhancing the power of heat-based attacks.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "pyromancer",
            "value": 7
        ]));

    addPrerequisite("/guilds/pyromancer/fire/searing-blast.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Searing Blast": 25,
        "Conflagration": 25,
        "Inferno": 25,
        "Great Inferno": 25,
    ]));
    addSpecification("affected research type", "percentage");
}
