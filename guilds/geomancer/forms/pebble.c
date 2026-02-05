//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/constructedResearchComponent.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Pebble Form");
    addSpecification("source", "geomancer");

    addSpecification("description", "This research provides the user with the "
        "knowledge of creating spells that hurl small stones at a foe.");

    addPrerequisite("/guilds/geomancer/forms/burst.c",
        (["type":"research"]));
    addPrerequisite("level",
        ([
            "type": "level",
            "guild": "geomancer",
            "value": 3
        ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Constructed Spell Multiplier": 10,
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("additional cooldown", 4);
    addSpecification("additional spell point cost", 7);

    addSpecification("use combination message", 
        "##InitiatorName## ##Infinitive::hurl## pebbles of ##Function## at ##TargetName##.");
}
