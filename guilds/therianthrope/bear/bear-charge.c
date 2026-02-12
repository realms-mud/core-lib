//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Bear Charge");
    addSpecification("source", "therianthrope");
    addSpecification("description", "While in bear form, you charge at your "
        "target with the full force of your massive body, dealing heavy damage "
        "and staggering the foe.");
    addSpecification("usage summary", "A devastating charge attack only usable "
        "while in bear form");

    addPrerequisite("/guilds/therianthrope/bear/mighty-swipe.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 11
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("stamina point cost", 50);
    addSpecification("cooldown", 12);

    addSpecification("cooldown modifiers", ([
        "/guilds/therianthrope/bear/attack-speed.c": 2,
    ]));

    addSpecification("stamina point cost modifiers", ([
        "/guilds/therianthrope/bear/attack-efficiency.c": 10,
    ]));

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/bear/bear-root.c"
        })
    ]));

    addSpecification("damage hit points", ({ 
        ([
            "probability": 80,
            "base damage": 40,
            "range": 80
        ]),
        ([
            "probability": 20,
            "base damage": 80,
            "range": 120
        ])
    }));

    addSpecification("damage type", "bludgeon");

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/therianthrope/bear/ursine-fury.c",
            "name": "Ursine Fury",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item": "/guilds/therianthrope/bear/savage-instinct.c",
            "name": "Savage Instinct",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "research",
            "research item": "/guilds/therianthrope/bear/apex-predator.c",
            "name": "Apex Predator",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/therianthrope/bear/primordial-beast.c",
            "name": "Primordial Beast",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/therianthrope/bear/titanic-bear.c",
            "name": "Titanic Bear",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.30
        ]),
        ([
            "type": "skill",
            "name": "anatomy and physiology",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "skill",
            "name": "body",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "attribute",
            "name": "strength",
            "formula": "additive",
            "rate": 0.75
        ]),
        ([
            "type": "attribute",
            "name": "constitution",
            "formula": "additive",
            "rate": 0.25
        ]),
        ([
            "type": "level",
            "name": "level",
            "formula": "additive",
            "rate": 0.50
        ])
    }));

    addSpecification("command template", "bear charge [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::drop## to all fours and ##Infinitive::barrel## "
        "into ##TargetName## with the unstoppable force of a charging bear!");
}
