//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Chimeric Rampage");
    addSpecification("source", "therianthrope");
    addSpecification("description", "While in chimera form, you unleash a "
        "savage flurry of claws, horns, and fangs upon your target, dealing "
        "devastating damage.");
    addSpecification("usage summary", "A brutal combination attack only "
        "usable while in chimera form");

    addPrerequisite("/guilds/therianthrope/chimera/flame-ward.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 41
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("stamina point cost", 50);
    addSpecification("cooldown", 10);

    addSpecification("cooldown modifiers", ([
        "/guilds/therianthrope/chimera/feral-celerity.c": 2,
    ]));

    addSpecification("stamina point cost modifiers", ([
        "/guilds/therianthrope/chimera/feral-efficiency.c": 10,
    ]));

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/chimera/chimera-root.c"
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

    addSpecification("command template", "chimeric rampage [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::unleash## a savage flurry of claws, horns, and "
        "fangs upon ##TargetName##!");
}
