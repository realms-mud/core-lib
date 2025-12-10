//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Legendary Efficiency");
    addSpecification("source", "aeromancer");
    addSpecification("description", "This research represents legendary mastery "
        "of casting efficiency. The aeromancer can weave constructed spells "
        "with such practiced ease that they recover almost instantly.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "aeromancer",
            "value": 45
        ]));
    addPrerequisite("/guilds/aeromancer/construct/grandmaster-efficiency.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Constructed Aeromancer Spells": 5,
    ]));
    addSpecification("affected research type", "decrease cooldown");
}
