//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

protected void Setup()
{
    addSpecification("name", "ruin nova");
    addSpecification("source", "Wrathguard");
    addSpecification("description", "Detonates a devastating nova of ruin "
        "energy in all directions, obliterating all nearby enemies.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("scope", "area");
    addSpecification("effect", "combat");
    addSpecification("spell point cost", 150);
    addSpecification("cooldown", 25);
    addSpecification("command template", "ruin nova");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::detonate## a devastating "
        "nova of ruin energy that obliterates all nearby enemies.");
    addSpecification("damage type", "magical");
    addSpecification("damage hit points", ({
        ([
            "probability": 60,
            "base damage": 120,
            "range": 90
        ]),
        ([
            "probability": 40,
            "base damage": 180,
            "range": 110
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
            "rate": 1.35
        ]),
        ([
            "type": "skill",
            "name": "destruction",
            "formula": "additive",
            "rate": 0.20
        ]),
        ([
            "type": "skill",
            "name": "evocation",
            "formula": "additive",
            "rate": 0.18
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
            "rate": 0.70
        ])
    }));
    addPrerequisite("/guilds/wrathguard/destruction/world-unmade.c",
        (["type": "research"]));
    addPrerequisite("level",
        ([
            "type": "level",
            "guild": "Wrathguard",
            "value": 41
        ]));
}