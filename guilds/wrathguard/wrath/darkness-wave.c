//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

protected void Setup()
{
    addSpecification("name", "darkness wave");
    addSpecification("source", "Wrathguard");
    addSpecification("description", "Unleashes a wave of crushing darkness "
        "that slams into all nearby enemies.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("scope", "area");
    addSpecification("effect", "combat");
    addSpecification("spell point cost", 65);
    addSpecification("cooldown", 18);
    addSpecification("command template", "darkness wave");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::unleash## a devastating "
        "wave of darkness upon all nearby enemies.");
    addSpecification("damage type", "shadow");
    addSpecification("damage hit points", ({
        ([
            "probability": 75,
            "base damage": 50,
            "range": 45
        ]),
        ([
            "probability": 25,
            "base damage": 80,
            "range": 55
        ])
    }));
    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/wrathguard/wrath/twilight-mastery.c",
            "name": "Twilight Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/wrathguard/wrath/dark-shroud-mastery.c",
            "name": "Dark Shroud Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
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
            "name": "magical essence",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "skill",
            "name": "anatomy and physiology",
            "formula": "additive",
            "rate": 0.05
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.40
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
    addPrerequisite("/guilds/wrathguard/wrath/shadow-drain.c",
        (["type": "research"]));
    addPrerequisite("level",
        ([
            "type": "level",
            "guild": "Wrathguard",
            "value": 23
        ]));
}