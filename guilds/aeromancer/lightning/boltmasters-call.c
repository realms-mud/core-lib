//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Boltmaster's Call");
    addSpecification("source", "aeromancer");
    addSpecification("description", "This skill provides the user with the "
        "knowledge to decrease the stamina cost for which they can use their "
        "blade attack abilities.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "aeromancer",
            "value": 21
        ]));
    addPrerequisite("/guilds/aeromancer/lightning/boltmasters-reserve.c",
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
    addSpecification("affected research type", "decrease cost");
}
