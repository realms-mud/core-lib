//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Frostweaving");
    addSpecification("source", "aeromancer");
    addSpecification("description", "This research teaches the aeromancer "
        "the art of weaving cold air currents together to create more "
        "devastating frost effects. By layering frigid winds atop one "
        "another, the aeromancer can achieve temperatures far below what "
        "a single cold blast could produce.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "aeromancer",
            "value": 9
        ]));

    addPrerequisite("/guilds/aeromancer/air/arctic-blast.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Arctic Blast": 25,
        "Hurricane": 25,
    ]));
    addSpecification("affected research type", "percentage");
}
