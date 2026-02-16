//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Constrict");
    addSpecification("source", "therianthrope");
    addSpecification("description", "While in serpent form, you wrap your "
        "coils around your target and squeeze with crushing force.");
    addSpecification("usage summary", "A crushing constriction attack only "
        "usable while in serpent form");

    addPrerequisite("/guilds/therianthrope/serpent/serpent-agility.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 13
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("stamina point cost", 30);
    addSpecification("cooldown", 6);

    addSpecification("cooldown modifiers", ([
        "/guilds/therianthrope/serpent/strike-speed.c": 1,
    ]));

    addSpecification("stamina point cost modifiers", ([
        "/guilds/therianthrope/serpent/strike-efficiency.c": 5,
    ]));

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/serpent/serpent-root.c"
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
            "range": 75
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
            "research item": "/guilds/therianthrope/serpent/coils-of-the-python.c",
            "name": "Coils of the Python",
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

    addSpecification("command template", "constrict [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::coil## around ##TargetName## and "
        "##Infinitive::squeeze## with bone-crushing force!");
}
