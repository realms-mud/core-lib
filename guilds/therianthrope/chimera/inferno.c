//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Inferno");
    addSpecification("source", "therianthrope");
    addSpecification("description", "While in chimera form, you rear back and "
        "exhale a massive conflagration that engulfs all nearby enemies in "
        "fire.");
    addSpecification("usage summary", "An area-of-effect fire attack only "
        "usable while in chimera form");

    addPrerequisite("/guilds/therianthrope/chimera/flame-ward.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 45
        ]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("stamina point cost", 80);
    addSpecification("spell point cost", 40);
    addSpecification("cooldown", 30);

    addSpecification("cooldown modifiers", ([
        "/guilds/therianthrope/chimera/feral-celerity.c": 5,
        "/guilds/therianthrope/chimera/tri-form-fury.c": 3,
    ]));

    addSpecification("stamina point cost modifiers", ([
        "/guilds/therianthrope/chimera/feral-efficiency.c": 15,
    ]));

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/chimera/chimera-root.c"
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

    addSpecification("damage type", "fire");

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/therianthrope/chimera/burning-blood.c",
            "name": "Burning Blood",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.10
        ]),
        ([
            "type": "research",
            "research item": "/guilds/therianthrope/chimera/lionheart.c",
            "name": "Lionheart",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item": "/guilds/therianthrope/chimera/chimeric-mastery.c",
            "name": "Chimeric Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "research",
            "research item": "/guilds/therianthrope/chimera/searing-claws.c",
            "name": "Searing Claws",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item": "/guilds/therianthrope/chimera/primal-chimera.c",
            "name": "Primal Chimera",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/therianthrope/chimera/chimeric-apotheosis.c",
            "name": "Chimeric Apotheosis",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/therianthrope/chimera/three-headed-assault.c",
            "name": "Three-Headed Assault",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "research",
            "research item": "/guilds/therianthrope/chimera/ember-heart.c",
            "name": "Ember Heart",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/therianthrope/chimera/molten-core.c",
            "name": "Molten Core",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/therianthrope/chimera/chimera-ascendant.c",
            "name": "Chimera Ascendant",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.30
        ]),
        ([
            "type": "research",
            "research item": "/guilds/therianthrope/chimera/mythic-chimera.c",
            "name": "Mythic Chimera",
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

    addSpecification("command template", "inferno");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::rear## back and ##Infinitive::exhale## a massive "
        "conflagration that engulfs everything nearby!");
}
