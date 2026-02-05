//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Legendary Efficiency");
    addSpecification("source", "geomancer");
    addSpecification("description", "This skill provides the user with legendary "
        "knowledge to maximize the speed with which they can cast their "
        "constructed spells.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "geomancer",
            "value": 45
        ]));
    addPrerequisite("/guilds/geomancer/construct/grandmaster-efficiency.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Constructed Geomancer Spells": 5,
    ]));
    addSpecification("affected research type", "decrease cooldown");
}
