//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/constructedResearchComponent.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Crushing Damage");
    addSpecification("source", "aquamancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of creating spells that damage targets with the crushing "
        "pressure of the ocean depths, capable of imploding armor.");

    addPrerequisite("/guilds/aquamancer/functions/drowning.c",
        (["type":"research"]));
    addPrerequisite("level",
        ([
            "type": "level",
            "guild": "aquamancer",
            "value": 15
        ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("damage type", "physical");

    addSpecification("affected research", ([
        "Constructed Spell Multiplier": 65,
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("additional cooldown", 16);
    addSpecification("additional spell point cost", 30);

    addSpecification("combination descriptor", "crushing depths");
}