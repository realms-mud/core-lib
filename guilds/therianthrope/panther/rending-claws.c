//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Rending Claws");
    addSpecification("source", "therianthrope");
    addSpecification("description", "While in panther form, you rapidly slash "
        "your target with both sets of claws in a tearing frenzy.");
    addSpecification("usage summary", "A rapid double-claw attack only usable "
        "while in panther form");

    addPrerequisite("/guilds/therianthrope/panther/vicious-rake.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 11
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("stamina point cost", 40);
    addSpecification("cooldown", 8);

    addSpecification("cooldown modifiers", ([
        "/guilds/therianthrope/panther/blinding-speed.c": 2,
    ]));

    addSpecification("stamina point cost modifiers", ([
        "/guilds/therianthrope/panther/hunting-efficiency.c": 8,
    ]));

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/panther/panther-root.c"
        })
    ]));

    addSpecification("damage hit points", ({ 
        ([
            "probability": 80,
            "base damage": 30,
            "range": 60
        ]),
        ([
            "probability": 20,
            "base damage": 60,
            "range": 90
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
            "rate": 0.50
        ])
    }));

    addSpecification("command template", "rending claws [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::blur## forward in a whirlwind of claws, rending "
        "##TargetName## with a flurry of savage slashes!");
}
