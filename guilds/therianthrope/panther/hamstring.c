//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Hamstring");
    addSpecification("source", "therianthrope");
    addSpecification("description", "While in panther form, you strike at your "
        "target's legs with surgical precision, slicing tendons and hobbling "
        "their movement.");
    addSpecification("usage summary", "A crippling attack that damages and "
        "slows the target, only usable while in panther form");

    addPrerequisite("/guilds/therianthrope/panther/feline-agility.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 7
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("stamina point cost", 25);
    addSpecification("cooldown", 12);

    addSpecification("cooldown modifiers", ([
        "/guilds/therianthrope/panther/blinding-speed.c": 2,
    ]));

    addSpecification("stamina point cost modifiers", ([
        "/guilds/therianthrope/panther/hunting-efficiency.c": 5,
    ]));

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/panther/panther-root.c"
        })
    ]));

    addSpecification("damage hit points", ({ 
        ([
            "probability": 80,
            "base damage": 20,
            "range": 40
        ]),
        ([
            "probability": 20,
            "base damage": 40,
            "range": 60
        ])
    }));
    addSpecification("damage stamina points", ({ 
        ([
            "probability": 80,
            "base damage": 20,
            "range": 40
        ]),
        ([
            "probability": 20,
            "base damage": 40,
            "range": 60
        ])
    }));

    addSpecification("damage type", "slash");

    addSpecification("apply slow", 1);
    addSpecification("penalty to dodge", 3);
    addSpecification("penalty to defense", 2);
    addSpecification("duration", 20);

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
            "rate": 0.50
        ])
    }));

    addSpecification("command template", "hamstring [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::dart## low and ##Infinitive::slash## at "
        "##TargetName##'s legs with razor-sharp claws, hobbling "
        "##TargetPossessive## movement!");
}
