//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

protected void Setup()
{
    addSpecification("name", "ruinous cascade");
    addSpecification("source", "Wrathguard");
    addSpecification("description", "Triggers a cascading wave of ruin "
        "that tears through all nearby enemies in a relentless sequence.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("scope", "area");
    addSpecification("effect", "combat");
    addSpecification("spell point cost", 85);
    addSpecification("cooldown", 18);
    addSpecification("command template", "ruinous cascade");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::trigger## a cascading "
        "wave of ruin that tears through all nearby enemies.");
    addSpecification("damage type", "magical");
    addSpecification("damage hit points", ({
        ([
            "probability": 70,
            "base damage": 70,
            "range": 55
        ]),
        ([
            "probability": 30,
            "base damage": 110,
            "range": 70
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
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.05
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
            "rate": 0.60
        ])
    }));
    addPrerequisite("/guilds/wrathguard/destruction/wall-of-ruin.c",
        (["type": "research"]));
    addPrerequisite("level",
        ([
            "type": "level",
            "guild": "Wrathguard",
            "value": 25
        ]));
}