//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Spit Venom");
    addSpecification("source", "therianthrope");
    addSpecification("description", "While in serpent form, you project a "
        "stream of corrosive venom at your target from a distance, dealing "
        "poison damage.");
    addSpecification("usage summary", "A ranged venom attack only usable "
        "while in serpent form");

    addPrerequisite("/guilds/therianthrope/serpent/hypnotic-gaze.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 23
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("stamina point cost", 40);
    addSpecification("spell point cost", 20);
    addSpecification("cooldown", 8);

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
            "base damage": 35,
            "range": 70
        ]),
        ([
            "probability": 20,
            "base damage": 70,
            "range": 100
        ])
    }));
    addSpecification("damage spell points", ({ 
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

    addSpecification("command template", "spit venom [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::rear## back and ##Infinitive::spit## a stream of "
        "corrosive venom at ##TargetName##!");
}
