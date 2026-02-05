//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/constructedResearchComponent.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Tectonic Damage");
    addSpecification("source", "geomancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of creating spells that damage targets with the raw power "
        "of tectonic forces - earth-shattering devastation.");

    addPrerequisite("/guilds/geomancer/functions/crystal.c",
        (["type":"research"]));
    addPrerequisite("level",
        ([
            "type": "level",
            "guild": "geomancer",
            "value": 17
        ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("damage type", "earth");

    addSpecification("affected research", ([
        "Constructed Spell Multiplier": 80,
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("additional cooldown", 20);
    addSpecification("additional spell point cost", 40);

    addSpecification("combination descriptor", "tectonic fury");
}
