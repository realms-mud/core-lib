//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Blast of Wind");
    addSpecification("source", "aeromancer");
    addSpecification("description", "This skill provides the user with "
        "knowledge that enhances the aeromancer's air-based abilities.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "aeromancer",
            "value": 3
        ]));

    addPrerequisite("/guilds/aeromancer/air/gust.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Gust": 15,
        "Talons of Wind": 15,
        "Stolen Breath": 15,
        "Noxious Breath": 15,
        "Blinding Mist": 15
    ]));
    addSpecification("affected research type", "percentage");
}
