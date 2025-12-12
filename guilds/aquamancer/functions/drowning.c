//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/constructedResearchComponent.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Drowning Damage");
    addSpecification("source", "aquamancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of creating spells that damage targets by forcing water "
        "into their lungs, causing them to drown on dry land.");

    addPrerequisite("/guilds/aquamancer/functions/current.c",
        (["type":"research"]));
    addPrerequisite("level",
        ([
            "type": "level",
            "guild": "aquamancer",
            "value": 13
        ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("damage type", "water");

    addSpecification("affected research", ([
        "Constructed Spell Multiplier": 50,
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("additional cooldown", 12);
    addSpecification("additional spell point cost", 22);

    addSpecification("combination descriptor", "drowning water");
}
