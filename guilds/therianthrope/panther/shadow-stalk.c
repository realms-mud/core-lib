//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Shadow Stalk");
    addSpecification("source", "therianthrope");
    addSpecification("description", "While in panther form, you meld with "
        "the shadows and strike from an impossible angle, dealing massive "
        "damage to all nearby enemies.");
    addSpecification("usage summary", "An area-of-effect ambush attack only "
        "usable while in panther form");

    addPrerequisite("/guilds/therianthrope/panther/shadow-stalker.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 23
        ]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("stamina point cost", 75);
    addSpecification("cooldown", 30);

    addSpecification("cooldown modifiers", ([
        "/guilds/therianthrope/panther/blinding-speed.c": 10,
    ]));

    addSpecification("stamina point cost modifiers", ([
        "/guilds/therianthrope/panther/hunting-efficiency.c": 15,
    ]));

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/panther/panther-root.c"
        })
    ]));

    addSpecification("damage hit points", ({ 
        ([
            "probability": 80,
            "base damage": 25,
            "range": 50
        ]),
        ([
            "probability": 20,
            "base damage": 50,
            "range": 80
        ])
    }));
    addSpecification("damage stamina points", ({ 
        ([
            "probability": 80,
            "base damage": 25,
            "range": 40
        ]),
        ([
            "probability": 20,
            "base damage": 40,
            "range": 80
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
            "rate": 0.50
        ]),
        ([
            "type": "level",
            "name": "level",
            "formula": "additive",
            "rate": 0.75
        ])
    }));

    addSpecification("command template", "shadow stalk");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::vanish## into the shadows and ##Infinitive::reappear## "
        "in a whirlwind of slashing claws, striking all nearby!");
}
