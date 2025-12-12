//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/constructedResearchComponent.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Acid Damage");
    addSpecification("source", "aquamancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of creating spells that damage targets with highly "
        "corrosive acidic water. The caustic liquid dissolves armor, eats "
        "through flesh, and leaves burning wounds that continue to fester.");

    addPrerequisite("/guilds/aquamancer/functions/steam.c",
        (["type":"research"]));
    addPrerequisite("level",
        ([
            "type": "level",
            "guild": "aquamancer",
            "value": 19
        ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("damage type", "acid");

    addSpecification("affected research", ([
        "Constructed Spell Multiplier": 90,
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("additional cooldown", 22);
    addSpecification("additional spell point cost", 45);

    addSpecification("combination descriptor", "corrosive acid");
}
