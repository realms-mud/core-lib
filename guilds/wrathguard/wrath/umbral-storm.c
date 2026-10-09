//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

protected void Setup()
{
    addSpecification("name", "umbral storm");
    addSpecification("source", "Wrathguard");
    addSpecification("description", "Conjures a raging storm of umbral "
        "energy that tears through all nearby enemies with devastating "
        "shadow damage.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("scope", "area");
    addSpecification("effect", "combat");
    addSpecification("spell point cost", 100);
    addSpecification("cooldown", 20);
    addSpecification("command template", "umbral storm");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::call## forth a raging "
        "storm of umbral shadow that tears through all nearby enemies.");
    addSpecification("damage type", "shadow");
    addSpecification("damage hit points", ({
        ([
            "probability": 70,
            "base damage": 80,
            "range": 60
        ]),
        ([
            "probability": 30,
            "base damage": 120,
            "range": 80
        ])
    }));
    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/wrathguard/wrath/umbral-focus.c",
            "name": "Umbral Focus",
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
            "rate": 1.30
        ]),
        ([
            "type": "skill",
            "name": "evocation",
            "formula": "additive",
            "rate": 0.15
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
            "rate": 1.10
        ]),
        ([
            "type": "skill",
            "name": "magical essence",
            "formula": "additive",
            "rate": 0.10
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
            "rate": 0.70
        ])
    }));
    addPrerequisite("/guilds/wrathguard/wrath/seilyndrias-gaze.c",
        (["type": "research"]));
    addPrerequisite("level",
        ([
            "type": "level",
            "guild": "Wrathguard",
            "value": 35
        ]));
}