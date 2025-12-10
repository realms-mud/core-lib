//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Fortifying Siphon");
    addSpecification("source", "aeromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the aeromancer spell construction component for siphoning "
        "life force from a target while fortifying the caster with enhanced "
        "defensive capabilities.");

    addPrerequisite("/guilds/aeromancer/effects/invigorating-siphon.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "aeromancer",
            "value": 21
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 50);

    addSpecification("siphon hit points", ({ ([
            "probability": 80,
            "base damage": 10,
            "range": 15
        ]),
        ([
            "probability": 20,
            "base damage": 20,
            "range": 25
        ])
    }));

    addSpecification("bonus defense", 5);
    addSpecification("bonus soak", 3);
    addSpecification("duration", 30);

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/aeromancer/construct/spell-focus.c",
            "name": "Spell Focus",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item": "/guilds/aeromancer/construct/enhanced-focus.c",
            "name": "Enhanced Focus",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item": "/guilds/aeromancer/construct/spell-amplification.c",
            "name": "Spell Amplification",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item": "/guilds/aeromancer/construct/spell-mastery.c",
            "name": "Spell Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item": "/guilds/aeromancer/construct/arcane-precision.c",
            "name": "Arcane Precision",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item": "/guilds/aeromancer/construct/spell-perfection.c",
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
            "type": "weapon damage",
            "name": "not a staff",
            "types": ({ "dagger", "short sword", "long sword", "bow", "axe",
                "hand and a half sword", "two-handed sword", "crossbow", 
                "sling", "thrown", "pole arm", "mace", "hammer", "flail" }),
            "formula": "subtractive",
            "rate": 1.25
        ]),
        ([
            "type": "skill",
            "name": "elemental air",
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

    addSpecification("cooldown", 10);
    addSpecification("event handler", "aeromancerFortifyingSiphonEvent");
}
