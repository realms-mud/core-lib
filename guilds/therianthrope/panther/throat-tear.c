//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Throat Tear");
    addSpecification("source", "therianthrope");
    addSpecification("description", "While in panther form, you lunge for your "
        "target's throat, tearing flesh and siphoning vitality from the wound.");
    addSpecification("usage summary", "A life-stealing bite attack only usable "
        "while in panther form");

    addPrerequisite("/guilds/therianthrope/panther/shadow-stalker.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 23
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("stamina point cost", 75);
    addSpecification("cooldown", 20);

    addSpecification("cooldown modifiers", ([
        "/guilds/therianthrope/panther/blinding-speed.c": 5,
    ]));

    addSpecification("stamina point cost modifiers", ([
        "/guilds/therianthrope/panther/hunting-efficiency.c": 15,
    ]));

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/panther/panther-root.c"
        })
    ]));

    addSpecification("siphon hit points", ({ 
        ([
            "probability": 80,
            "base damage": 35,
            "range": 70
        ]),
        ([
            "probability": 20,
            "base damage": 70,
            "range": 110
        ])
    }));

    addSpecification("damage type", "slash");

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/therianthrope/panther/predatory-grace.c",
            "name": "Predatory Grace",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item": "/guilds/therianthrope/panther/killing-instinct.c",
            "name": "Killing Instinct",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "research",
            "research item": "/guilds/therianthrope/panther/shadow-stalker.c",
            "name": "Shadow Stalker",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/therianthrope/panther/phantasmal-panther.c",
            "name": "Phantasmal Panther",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/therianthrope/panther/lord-of-the-hunt.c",
            "name": "Lord of the Hunt",
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
            "name": "dexterity",
            "formula": "additive",
            "rate": 0.50
        ]),
        ([
            "type": "attribute",
            "name": "strength",
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

    addSpecification("command template", "throat tear [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::lunge## at ##TargetName##'s throat, tearing flesh "
        "and drinking in ##TargetPossessive## vitality!");
}
