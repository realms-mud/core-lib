//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Maelstrom");
    addSpecification("source", "aquamancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the maelstrom spell. The aquamancer creates a powerful "
        "spinning vortex of water that pulls enemies toward its center while "
        "battering them with crushing currents. The maelstrom tears at "
        "everything caught within its grasp.");

    addPrerequisite("/guilds/aquamancer/water/water-blast.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "aquamancer",
            "value": 13
        ]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 65);

    addSpecification("damage hit points", ({ ([
            "probability": 80,
            "base damage": 20,
            "range": 35
        ]),
        ([
            "probability": 20,
            "base damage": 35,
            "range": 55
        ])
    }));
    addSpecification("damage type", "water");

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/aquamancer/water/tidal-force.c",
            "name": "Tidal Force",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/aquamancer/water/water-mastery.c",
            "name": "Water Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/aquamancer/water/water-channeling.c",
            "name": "Water Channeling",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/aquamancer/water/ocean-mastery.c",
            "name": "Ocean Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "weapon damage",
            "name": "staff",
            "types": ({ "staff" }),
            "formula": "additive",
            "rate": 1.0
        ]),
        ([
            "type": "skill",
            "name": "elemental water",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "level",
            "name": "level",
            "formula": "logarithmic",
            "rate": 1.05
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.25
        ]),
        ([
            "type": "skill",
            "name": "magical essence",
            "formula": "logarithmic",
            "rate": 1.25
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.05
        ]),
    }));

    addSpecification("cooldown", 25);
    addSpecification("event handler", "maelstromEvent");
    addSpecification("command template", "maelstrom");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::summon## a devastating maelstrom that tears through "
        "the area, crushing all foes in its churning depths.");
}
