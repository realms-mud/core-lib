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
    addSpecification("description", "While in chimera form, you lunge forward "
        "and rake your target with the savage claws of a lion, dealing "
        "slashing damage.");
    addSpecification("usage summary", "A claw attack only usable "
        "while in chimera form");

    addPrerequisite("/guilds/therianthrope/chimera/predatory-precision.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 25
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("stamina point cost", 25);
    addSpecification("cooldown", 4);

    addSpecification("cooldown modifiers", ([
        "/guilds/therianthrope/chimera/feral-celerity.c": 1,
    ]));

    addSpecification("stamina point cost modifiers", ([
        "/guilds/therianthrope/chimera/feral-efficiency.c": 5,
    ]));

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/chimera/chimera-root.c"
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

    addSpecification("damage type", "slash");

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/therianthrope/chimera/burning-blood.c",
            "name": "Burning Blood",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
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
            "rate": 1.20
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
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/therianthrope/chimera/eternal-chimera.c",
            "name": "Eternal Chimera",
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

    addSpecification("command template", "rending claws [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::lunge## forward and ##Infinitive::rake## "
        "##TargetName## with savage claws!");
}
