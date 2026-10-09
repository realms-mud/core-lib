//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Exhausting Damage");
    addSpecification("source", "cryomancer");
    addSpecification("description", "This research provides knowledge of dealing cold damage that exhausts and reduces the target's stamina.");

    addPrerequisite("/guilds/cryomancer/effects/apply-frozen.c",
        (["type": "research"]));

    addPrerequisite("level",
        ([
            "type": "level",
            "guild": "cryomancer",
            "value": 21
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 45);

    addSpecification("damage hit points", ({ ([
            "probability": 80,
            "base damage": 12,
            "range": 18
        ]),
        ([
            "probability": 20,
            "base damage": 24,
            "range": 36
        ])
    }));

    addSpecification("penalty to parry", 5);
    addSpecification("duration", 30);

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/cryomancer/construct/spell-focus.c",
            "name": "Spell Focus",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item": "/guilds/cryomancer/construct/enhanced-focus.c",
            "name": "Enhanced Focus",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item": "/guilds/cryomancer/construct/spell-amplification.c",
            "name": "Spell Amplification",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item": "/guilds/cryomancer/construct/spell-mastery.c",
            "name": "Spell Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item": "/guilds/cryomancer/construct/arcane-precision.c",
            "name": "Arcane Precision",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item": "/guilds/cryomancer/construct/spell-perfection.c",
            "name": "Spell Perfection",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "weapon damage",
            "name": "staff",
            "types": ({ "staff" }),
            "formula": "additive",
            "rate": 1.05
        ]),
        ([
            "type": "skill",
            "name": "elemental water",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "level",
            "name": "cryomancer",
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

    addSpecification("cooldown", 10);
    addSpecification("event handler", "cryomancerExhaustingDamageEvent");
}
