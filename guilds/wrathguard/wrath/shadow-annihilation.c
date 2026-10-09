//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

protected void Setup()
{
    addSpecification("name", "shadow annihilation");
    addSpecification("source", "Wrathguard");
    addSpecification("description", "The ultimate expression of shadow "
        "magic - a focused beam of void annihilation that obliterates "
        "a single target with the full force of Seilyndria's darkness.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("spell point cost", 130);
    addSpecification("cooldown", 25);
    addSpecification("command template", "shadow annihilation at ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::channel## the full "
        "annihilating power of Seilyndria's void directly at ##TargetName##.");
    addSpecification("damage type", "shadow");
    addSpecification("damage hit points", ({
        ([
            "probability": 60,
            "base damage": 120,
            "range": 80
        ]),
        ([
            "probability": 40,
            "base damage": 180,
            "range": 100
        ])
    }));
    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/wrathguard/wrath/dark-resonance.c",
            "name": "Dark Resonance",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/wrathguard/wrath/seilyndrias-reach.c",
            "name": "Seilyndria's Reach",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.30
        ]),
        ([
            "type": "research",
            "research item": "/guilds/wrathguard/wrath/entropy-focus.c",
            "name": "Entropy Focus",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.35
        ]),
        ([
            "type": "skill",
            "name": "evocation",
            "formula": "additive",
            "rate": 0.18
        ]),
        ([
            "type": "skill",
            "name": "destruction",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.15
        ]),
        ([
            "type": "skill",
            "name": "magical essence",
            "formula": "additive",
            "rate": 0.12
        ]),
        ([
            "type": "skill",
            "name": "anatomy and physiology",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.50
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.25
        ]),
        ([
            "type": "level",
            "name": "Wrathguard",
            "formula": "additive",
            "rate": 0.75
        ])
    }));
    addPrerequisite("/guilds/wrathguard/wrath/umbral-storm.c",
        (["type": "research"]));
    addPrerequisite("level",
        ([
            "type": "level",
            "guild": "Wrathguard",
            "value": 43
        ]));
}