//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

protected void Setup()
{
    addSpecification("name", "shadow embrace");
    addSpecification("source", "Wrathguard");
    addSpecification("description", "The Herald enfolds a single target "
        "in living shadow, crushing them and leaving them weakened and "
        "exposed.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("spell point cost", 50);
    addSpecification("cooldown", 35);
    addSpecification("command template", "shadow embrace ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::surround## ##TargetName## "
        "in crushing, living shadow.");
    addSpecification("damage type", "shadow");
    addSpecification("damage hit points", ({
        ([
            "probability": 100,
            "base damage": 55,
            "range": 35
        ])
    }));
    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/wrathguard/herald/herald-form.c",
            "name": "Herald Form",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/wrathguard/herald/heralds-wrath.c",
            "name": "Herald's Wrath",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.10
        ]),
        ([
            "type": "skill",
            "name": "destruction",
            "formula": "additive",
            "rate": 0.30
        ]),
        ([
            "type": "skill",
            "name": "theology",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "skill",
            "name": "magical essence",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.15
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
            "rate": 0.15
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "level",
            "name": "Wrathguard",
            "formula": "additive",
            "rate": 0.65
        ])
    }));
    addSpecification("limited by", ([
        "research active":
            "/guilds/wrathguard/herald/herald-form.c"
    ]));
    addPrerequisite("/guilds/wrathguard/herald/heralds-wrath.c",
        (["type": "research"]));
    addPrerequisite("level",
        ([
            "type": "level",
            "guild": "Wrathguard",
            "value": 40
        ]));
}
