//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

protected void Setup()
{
    addSpecification("name", "world unmade");
    addSpecification("source", "Wrathguard");
    addSpecification("description", "Channels Seilyndria's vision of a "
        "world unmade, detonating catastrophic destruction that tears "
        "through all nearby enemies.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("scope", "area");
    addSpecification("effect", "combat");
    addSpecification("spell point cost", 130);
    addSpecification("cooldown", 25);
    addSpecification("command template", "world unmade");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::channel## Seilyndria's "
        "vision of a world unmade, detonating catastrophic destruction nearby.");
    addSpecification("damage type", "magical");
    addSpecification("damage hit points", ({
        ([
            "probability": 65,
            "base damage": 100,
            "range": 80
        ]),
        ([
            "probability": 35,
            "base damage": 155,
            "range": 100
        ])
    }));
    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/wrathguard/destruction/unmaking-mastery.c",
            "name": "Unmaking Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/wrathguard/destruction/annihilating-mastery.c",
            "name": "Annihilating Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/wrathguard/destruction/obliterating-mastery.c",
            "name": "Obliterating Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.30
        ]),
        ([
            "type": "skill",
            "name": "destruction",
            "formula": "additive",
            "rate": 0.18
        ]),
        ([
            "type": "skill",
            "name": "evocation",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "skill",
            "name": "elemental fire",
            "formula": "additive",
            "rate": 0.12
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.10
        ]),
        ([
            "type": "skill",
            "name": "anatomy and physiology",
            "formula": "additive",
            "rate": 0.08
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.45
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.20
        ]),
        ([
            "type": "level",
            "name": "Wrathguard",
            "formula": "additive",
            "rate": 0.65
        ])
    }));
    addPrerequisite("/guilds/wrathguard/destruction/unmaking-strike.c",
        (["type": "research"]));
    addPrerequisite("level",
        ([
            "type": "level",
            "guild": "Wrathguard",
            "value": 37
        ]));
}