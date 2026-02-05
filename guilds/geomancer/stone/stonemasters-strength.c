//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Stonemaster's Strength");
    addSpecification("source", "geomancer");
    addSpecification("description", "This skill provides the user with the "
        "knowledge to further decrease the cooldown for which they "
        "can use their stone attack abilities.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "geomancer",
            "value": 43
        ]));
    addPrerequisite("/guilds/geomancer/stone/stonemasters-endurance.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Dust Cloud": 10,
        "Grinding Wave": 10,
        "Rock Discharge": 10,
        "Boulder Storm": 10,
        "Stone Bolt": 10,
        "Stone Whip": 10,
        "Raging Avalanche": 10,
        "Earthen Swarm": 10,
    ]));
    addSpecification("affected research type", "decrease cooldown");
}
