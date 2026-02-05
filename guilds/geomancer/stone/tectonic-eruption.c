//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Tectonic Eruption");
    addSpecification("source", "geomancer");
    addSpecification("description", "This skill provides the user with "
        "mastery of tectonic manipulation that further enhances the "
        "geomancer's stone-based abilities.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "geomancer",
            "value": 57
        ]));

    addPrerequisite("/guilds/geomancer/stone/seismic-burst.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Pebble": 25,
        "Dust Cloud": 25,
        "Grinding Wave": 25,
        "Stone Blades": 25,
        "Rock Discharge": 25,
        "Rock Snap": 25,
        "Earthen Swarm": 25,
        "Boulder Storm": 25,
        "Stone Bolt": 25,
        "Stone Lash": 25,
        "Stone Shards": 25,
        "Stone Whip": 25,
        "Raging Avalanche": 25,
    ]));
    addSpecification("affected research type", "percentage");
}
