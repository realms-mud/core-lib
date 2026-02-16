//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Miasma");
    addSpecification("source", "therianthrope");
    addSpecification("description", "While in serpent form, you exhale a "
        "cloud of toxic vapor that poisons all nearby enemies.");
    addSpecification("usage summary", "An area-of-effect poison attack only "
        "usable while in serpent form");

    addPrerequisite("/guilds/therianthrope/serpent/primordial-scales.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 35
        ]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("stamina point cost", 80);
    addSpecification("spell point cost", 40);
    addSpecification("cooldown", 30);

    addSpecification("cooldown modifiers", ([
        "/guilds/therianthrope/serpent/strike-speed.c": 5,
        "/guilds/therianthrope/serpent/ophidian-swiftness.c": 3,
    ]));

    addSpecification("stamina point cost modifiers", ([
        "/guilds/therianthrope/serpent/strike-efficiency.c": 15,
    ]));

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/serpent/serpent-root.c"
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
            "range": 100
        ])
    }));
    addSpecification("damage spell points", ({ 
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

    addSpecification("damage type", "poison");

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/therianthrope/serpent/venom-potency.c",
            "name": "Venom Potency",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.10
        ]),
        ([
            "type": "research",
            "research item": "/guilds/therianthrope/serpent/serpentine-fury.c",
            "name": "Serpentine Fury",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item": "/guilds/therianthrope/serpent/venomous-mastery.c",
            "name": "Venomous Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "research",
            "research item": "/guilds/therianthrope/serpent/naga-form.c",
            "name": "Naga Form",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/therianthrope/serpent/world-serpent.c",
            "name": "World Serpent",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/therianthrope/serpent/necrotic-venom.c",
            "name": "Necrotic Venom",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/therianthrope/serpent/serpent-ascendant.c",
            "name": "Serpent Ascendant",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.30
        ]),
        ([
            "type": "research",
            "research item": "/guilds/therianthrope/serpent/world-devourer.c",
            "name": "World Devourer",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.35
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
        ])
    }));

    addSpecification("command template", "miasma");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::exhale## a billowing cloud of toxic vapor that "
        "engulfs everything nearby!");
}
