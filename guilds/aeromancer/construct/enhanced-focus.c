//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Enhanced Focus");
    addSpecification("source", "aeromancer");
    addSpecification("description", "This research further refines the "
        "aeromancer's ability to channel magical energy into their constructed "
        "spells, significantly increasing their power.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "aeromancer",
            "value": 17
        ]));
    addPrerequisite("/guilds/aeromancer/construct/spell-focus.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Constructed Aeromancer Spells": 15,
    ]));
    addSpecification("affected research type", "percentage");
}
