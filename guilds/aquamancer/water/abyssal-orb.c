//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Abyssal Orb");
    addSpecification("source", "aquamancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the abyssal orb spell. The aquamancer conjures a sphere "
        "of water drawn from the darkest ocean trenches, filled with crushing "
        "pressure and deadly toxins. The orb detonates on impact, releasing "
        "its poisonous payload.");

    addPrerequisite("/guilds/aquamancer/water/drowning-embrace.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "aquamancer",
            "value": 51
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 110);

    addSpecification("damage hit points", ({ ([
            "probability": 80,
            "base damage": 70,
            "range": 100
        ]),
        ([
            "probability": 20,
            "base damage": 110,
            "range": 150
        ])
    }));
    addSpecification("damage type", "poison");

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/aquamancer/water/water-blast.c",
            "name": "Water Blast",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/aquamancer/water/toxic-waters.c",
            "name": "Toxic Waters",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/aquamancer/water/drowning-embrace.c",
            "name": "Drowning Embrace",
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

    addSpecification("cooldown", 30);
    addSpecification("event handler", "abyssalOrbEvent");
    addSpecification("command template", "abyssal orb [at ##Target##]");
    addSpecification("use ability message", "A sphere of dark, toxic water "
        "from the ocean's depths hurtles toward ##TargetName##, detonating "
        "with devastating force.");
}
