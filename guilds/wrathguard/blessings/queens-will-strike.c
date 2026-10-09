//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

protected void Setup()
{
    addSpecification("name", "queen's will strike");
    addSpecification("source", "Wrathguard");
    addSpecification("description", "The Wrathguard channels every ounce "
        "of mastered will into a focused strike - a pure expression of "
        "Seilyndria's divine authority made manifest as a weapon.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("spell point cost", 90);
    addSpecification("cooldown", 24);
    addSpecification("command template", "queens will strike at ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::channel## the Queen's will "
        "into a devastating strike against ##TargetName##.");
    addSpecification("damage type", "magical");
    addSpecification("damage hit points", ({
        ([
            "probability": 100,
            "base damage": 115,
            "range": 80
        ])
    }));
    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/wrathguard/blessings/word-of-annihilation.c",
            "name": "Word of Annihilation",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item": "/guilds/wrathguard/blessings/voice-of-ruin.c",
            "name": "Voice of Ruin",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.10
        ]),
        ([
            "type": "skill",
            "name": "theology",
            "formula": "additive",
            "rate": 0.40
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
            "formula": "additive",
            "rate": 0.20
        ]),
        ([
            "type": "skill",
            "name": "evocation",
            "formula": "additive",
            "rate": 0.20
        ]),
        ([
            "type": "skill",
            "name": "manipulation",
            "formula": "additive",
            "rate": 0.20
        ]),
        ([
            "type": "skill",
            "name": "mind",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "skill",
            "name": "anatomy and physiology",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.25
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.20
        ]),
        ([
            "type": "level",
            "name": "Wrathguard",
            "formula": "additive",
            "rate": 1.90
        ])
    }));
    addPrerequisite("/guilds/wrathguard/blessings/will-mastery.c",
        (["type": "research"]));
    addPrerequisite("level",
        ([
            "type": "level",
            "guild": "Wrathguard",
            "value": 63
        ]));
}
