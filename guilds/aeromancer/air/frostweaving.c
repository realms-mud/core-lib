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
    addSpecification("description", "This skill provides the user with "
        "knowledge that enhances the aeromancer's cold-based air abilities.");

    addPrerequisite("level",
        (["type":"level",
            "guild" : "aeromancer",
            "value" : 9
        ]));

    addPrerequisite("/guilds/aeromancer/air/arctic-focus.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Arctic Blast":25,
        "Glacial Winds" : 25,
        "Icy Convergence" : 25,
        "Freezing Tide" : 25,
        "Frost Veil" : 25
    ]));
    addSpecification("affected research type", "percentage");
}
