//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

protected void Setup()
{
    addSpecification("name", "corrosive burst");
    addSpecification("source", "Wrathguard");
    addSpecification("description", "Detonates a burst of corrosive energy "
        "that deals acid damage to all nearby enemies.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("scope", "area");
    addSpecification("effect", "combat");
    addSpecification("spell point cost", 70);
    addSpecification("cooldown", 18);
    addSpecification("command template", "corrosive burst");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::detonate## a burst of "
        "corrosive energy that sears all nearby enemies.");
    addSpecification("damage type", "acid");
    addSpecification("damage hit points", ({
        ([
            "probability": 75,
            "base damage": 55,
            "range": 50
        ]),
        ([
            "probability": 25,
            "base damage": 90,
            "range": 65
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
            "rate": 1.05
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
    addPrerequisite("/guilds/wrathguard/destruction/ruin-strike.c",
        (["type": "research"]));
    addPrerequisite("level",
        ([
            "type": "level",
            "guild": "Wrathguard",
            "value": 15
        ]));
}