//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Grandmaster Efficiency");
    addSpecification("source", "aeromancer");
    addSpecification("description", "This research provides grandmaster-level "
        "understanding of magical efficiency, allowing the aeromancer to cast "
        "constructed spells with remarkable speed.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "aeromancer",
            "value": 37
        ]));
    addPrerequisite("/guilds/aeromancer/construct/master-efficiency.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Constructed Aeromancer Spells": 5,
    ]));
    addSpecification("affected research type", "decrease cooldown");
}
