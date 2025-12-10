//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Icy Convergence");
    addSpecification("source", "aeromancer");
    addSpecification("description", "This research teaches the aeromancer to "
        "draw cold air currents from multiple directions simultaneously, "
        "converging them upon a single point. This technique dramatically "
        "amplifies the freezing power of their cold-based attacks by creating "
        "zones of extreme temperature differential.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "aeromancer",
            "value": 17
        ]));

    addPrerequisite("/guilds/aeromancer/air/frostweaving.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Arctic Blast": 25,
        "Hurricane": 25,
    ]));
    addSpecification("affected research type", "percentage");
}
