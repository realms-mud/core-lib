//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Fanged Bite");
    addSpecification("source", "therianthrope");
    addSpecification("description", "While in serpent form, you lunge forward "
        "and sink venomous fangs into your target, dealing physical and "
        "poison damage.");
    addSpecification("usage summary", "A venomous bite attack only usable "
        "while in serpent form");

    addPrerequisite("/guilds/therianthrope/serpent/serpent-strike.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 11
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("stamina point cost", 25);
    addSpecification("cooldown", 4);

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
            "base damage": 15,
            "range": 30
        ]),
        ([
            "probability": 20,
            "base damage": 30,
            "range": 50
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
            "rate": 1.15
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

    addSpecification("command template", "fanged bite [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::lunge## forward and ##Infinitive::sink## venomous "
        "fangs into ##TargetName##!");
}
