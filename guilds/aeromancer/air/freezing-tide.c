//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Freezing Tide");
    addSpecification("source", "aeromancer");
    addSpecification("description", "This research allows the aeromancer to "
        "unleash cold not as a single blast but as a wave - a tide of freezing "
        "air that rolls across the battlefield. This technique allows cold "
        "attacks to penetrate deeper and linger longer, maximizing the damage "
        "dealt to enemies.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "aeromancer",
            "value": 37
        ]));

    addPrerequisite("/guilds/aeromancer/air/glacial-winds.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Arctic Blast": 25,
        "Hurricane": 25,
    ]));
    addSpecification("affected research type", "percentage");
}
