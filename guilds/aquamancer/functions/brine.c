//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/constructedResearchComponent.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Brine Damage");
    addSpecification("source", "aquamancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of creating spells that damage targets with toxic, "
        "corrosive brine drawn from the darkest ocean depths. The poisonous "
        "water eats away at flesh and metal alike.");

    addPrerequisite("/guilds/aquamancer/functions/tempest.c",
        (["type":"research"]));
    addPrerequisite("level",
        ([
            "type": "level",
            "guild": "aquamancer",
            "value": 21
        ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("damage type", "poison");

    addSpecification("affected research", ([
        "Constructed Spell Multiplier": 100,
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("additional cooldown", 25);
    addSpecification("additional spell point cost", 50);

    addSpecification("combination descriptor", "toxic brine");
}
