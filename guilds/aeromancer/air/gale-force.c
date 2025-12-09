//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Gale Force");
    addSpecification("source", "aeromancer");
    addSpecification("description", "This skill provides the user with "
        "knowledge that enhances the power of the aeromancer's wind-based "
        "area attacks.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "aeromancer",
            "value": 11
        ]));

    addPrerequisite("/guilds/aeromancer/air/cyclone.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Cyclone": 25,
        "Tornado": 25,
        "Hurricane": 25,
        "Maelstrom": 25,
        "Cataclysmic Tempest": 25,
    ]));
    addSpecification("affected research type", "percentage");
}
