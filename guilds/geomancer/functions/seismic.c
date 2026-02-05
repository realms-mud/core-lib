//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/constructedResearchComponent.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Seismic Damage");
    addSpecification("source", "geomancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of creating spells that damage targets with apocalyptic "
        "seismic energy - the ultimate expression of earth's wrath.");

    addPrerequisite("/guilds/geomancer/functions/tectonic.c",
        (["type":"research"]));
    addPrerequisite("level",
        ([
            "type": "level",
            "guild": "geomancer",
            "value": 21
        ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("damage type", "earth");

    addSpecification("affected research", ([
        "Constructed Spell Multiplier": 100,
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("additional cooldown", 30);
    addSpecification("additional spell point cost", 55);

    addSpecification("combination descriptor", "seismic devastation");
}
