//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Boltmaster's Finess");
    addSpecification("source", "aeromancer");
    addSpecification("description", "This skill provides the user with the "
        "knowledge to increase the speed with which they can use their "
        "electricity-based abilities.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "aeromancer",
            "value": 23
        ]));
    addPrerequisite("/guilds/aeromancer/lightning/boltmasters-boon.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Ball Lightning": 10,
        "Electric Whip": 10,
        "Lightning Bolt": 10,
        "Shocking Wave": 10,
        "Static Discharge": 10,
        "Raging Tempest": 10,
        "Thundering Swarm": 10,
    ]));
    addSpecification("affected research type", "decrease cooldown");
}
