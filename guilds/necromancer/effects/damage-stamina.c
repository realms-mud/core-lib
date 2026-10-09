//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Damage Stamina");
    addSpecification("source", "necromancer");
    addSpecification("description", "This research provides knowledge of sapping stamina with necrotic energy.");

    addPrerequisite("/guilds/necromancer/effects/damage-sp.c",
        (["type": "research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 12);
    addSpecification("damage stamina points", ({ ([
        "probability": 80,
        "base damage": 5,
        "range": 10
    ]),
    ([
        "probability": 20,
        "base damage": 10,
        "range": 20
    ])
    }));
    addSpecification("damage type", "energy");
    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/necromancer/construct/spell-focus.c",
            "name": "Spell Focus",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
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
            "type": "skill",
            "name": "spirit",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "level",
            "name": "necromancer",
            "formula": "logarithmic",
            "rate": 1.05
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.05
        ]),
    }));
    addSpecification("cooldown", 5);
    addSpecification("event handler", "necromancerDamageStaminaEvent");
}
