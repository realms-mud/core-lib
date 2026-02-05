//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/constructedResearchComponent.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Weight Damage");
    addSpecification("source", "geomancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of creating spells that damage targets with the crushing "
        "weight of stone.");

    addPrerequisite("/guilds/geomancer/functions/earth.c",
        (["type":"research"]));
    addPrerequisite("level",
        ([
            "type": "level",
            "guild": "geomancer",
            "value": 7
        ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("damage type", "physical");

    addSpecification("affected research", ([
        "Constructed Spell Multiplier": 25,
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("additional cooldown", 6);
    addSpecification("additional spell point cost", 12);

    addSpecification("combination descriptor", "crushing weight");
}
