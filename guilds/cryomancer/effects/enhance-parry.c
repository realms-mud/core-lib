//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Enhance Parry");
    addSpecification("source", "cryomancer");
    addSpecification("description", "This research provides knowledge of the cryomancer spell construction component for enhancing parry.");

    addPrerequisite("/guilds/cryomancer/effects/enhance-dodge.c",
        (["type": "research"]));

    addPrerequisite("level",
        ([
            "type": "level",
            "guild": "cryomancer",
            "value": 17
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 30);

    addSpecification("bonus parry", 5);
    addSpecification("duration", 60);

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

    addSpecification("cooldown", 6);
    addSpecification("event handler", "cryomancerEnhanceParryEvent");
}
