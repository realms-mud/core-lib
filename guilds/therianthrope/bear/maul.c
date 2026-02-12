//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Maul");
    addSpecification("source", "therianthrope");
    addSpecification("description", "While in bear form, you maul your target "
        "with a savage combination of claws and teeth, dealing devastating "
        "damage.");
    addSpecification("usage summary", "A brutal combination attack only usable "
        "while in bear form");

    addPrerequisite("/guilds/therianthrope/bear/savage-instinct.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 19
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("stamina point cost", 60);
    addSpecification("cooldown", 10);

    addSpecification("cooldown modifiers", ([
        "/guilds/therianthrope/bear/attack-speed.c": 5,
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
            "base damage": 50,
            "range": 100
        ]),
        ([
            "probability": 20,
            "base damage": 100,
            "range": 150
        ])
    }));

    addSpecification("damage type", "slash");

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
            "rate": 0.75
        ])
    }));

    addSpecification("command template", "maul [##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::rear## up and ##Infinitive::bring## both massive "
        "paws crashing down on ##TargetName##, following with a vicious "
        "bite in a savage mauling!");
}
