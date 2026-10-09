//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

protected void Setup()
{
    addSpecification("name", "absolute dominion");
    addSpecification("source", "Wrathguard");
    addSpecification("description", "The Wrathguard exerts absolute "
        "dominion over the target, dealing catastrophic magical damage "
        "as Seilyndria's full authority manifests through her chosen.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("spell point cost", 110);
    addSpecification("cooldown", 28);
    addSpecification("command template", "absolute dominion over ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::exert## absolute dominion "
        "over ##TargetName##.");
    addSpecification("damage type", "magical");
    addSpecification("damage hit points", ({
        ([
            "probability": 100,
            "base damage": 150,
            "range": 110
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
            "research item": "/guilds/wrathguard/blessings/queens-will-strike.c",
            "name": "Queen's Will Strike",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.10
        ]),
        ([
            "type": "skill",
            "name": "theology",
            "formula": "additive",
            "rate": 0.45
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
            "rate": 0.25
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
            "rate": 2.20
        ])
    }));
    addPrerequisite("/guilds/wrathguard/blessings/word-of-annihilation.c",
        (["type": "research"]));
    addPrerequisite("level",
        ([
            "type": "level",
            "guild": "Wrathguard",
            "value": 67
        ]));
}
