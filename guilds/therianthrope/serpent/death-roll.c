//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Death Roll");
    addSpecification("source", "therianthrope");
    addSpecification("description", "While in serpent form, you seize your "
        "target in your coils and violently twist, dealing devastating "
        "damage.");
    addSpecification("usage summary", "A brutal twisting attack only usable "
        "while in serpent form");

    addPrerequisite("/guilds/therianthrope/serpent/coils-of-the-python.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 19
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("stamina point cost", 50);
    addSpecification("cooldown", 10);

    addSpecification("cooldown modifiers", ([
        "/guilds/therianthrope/serpent/strike-speed.c": 2,
    ]));

    addSpecification("stamina point cost modifiers", ([
        "/guilds/therianthrope/serpent/strike-efficiency.c": 10,
    ]));

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/serpent/serpent-root.c"
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
            "research item": "/guilds/therianthrope/serpent/serpentine-fury.c",
            "name": "Serpentine Fury",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item": "/guilds/therianthrope/serpent/viper-reflexes.c",
            "name": "Viper Reflexes",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
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
            "research item": "/guilds/therianthrope/serpent/serpent-apotheosis.c",
            "name": "Serpent Apotheosis",
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

    addSpecification("command template", "death roll [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::seize## ##TargetName## in massive coils and "
        "##Infinitive::twist## violently!");
}
