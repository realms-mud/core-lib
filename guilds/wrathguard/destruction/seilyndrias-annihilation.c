//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

protected void Setup()
{
    addSpecification("name", "seilyndria's annihilation");
    addSpecification("source", "Wrathguard");
    addSpecification("description", "The ultimate act of devotion to "
        "Seilyndria - channeling her total annihilation into a single "
        "target, reducing them utterly to nothing.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("spell point cost", 180);
    addSpecification("cooldown", 30);
    addSpecification("command template",
        "seilyndrias annihilation at ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::channel## the total "
        "annihilation of Seilyndria into ##TargetName##, reducing them "
        "to nothing.");
    addSpecification("damage type", "magical");
    addSpecification("damage hit points", ({
        ([
            "probability": 55,
            "base damage": 160,
            "range": 110
        ]),
        ([
            "probability": 45,
            "base damage": 230,
            "range": 130
        ])
    }));
    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/wrathguard/destruction/ruinous-impact.c",
            "name": "Ruinous Impact",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/wrathguard/destruction/seilyndrias-wrath.c",
            "name": "Seilyndria's Wrath",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.30
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
            "rate": 0.75
        ])
    }));
    addPrerequisite("/guilds/wrathguard/destruction/ruin-nova.c",
        (["type": "research"]));
    addPrerequisite("level",
        ([
            "type": "level",
            "guild": "Wrathguard",
            "value": 45
        ]));
}