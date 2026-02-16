//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Frost Breath");
    addSpecification("source", "therianthrope");
    addSpecification("description", "While in dragon form, you exhale a "
        "blast of freezing cold at your target, dealing cold damage.");
    addSpecification("usage summary", "A frost breath attack only usable "
        "while in dragon form");

    addPrerequisite("/guilds/therianthrope/dragon/glacial-fangs.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 35
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("stamina point cost", 40);
    addSpecification("spell point cost", 20);
    addSpecification("cooldown", 8);

    addSpecification("cooldown modifiers", ([
        "/guilds/therianthrope/dragon/draconic-celerity.c": 2,
    ]));

    addSpecification("stamina point cost modifiers", ([
        "/guilds/therianthrope/dragon/draconic-efficiency.c": 10,
    ]));

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/dragon/dragon-root.c"
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

    addSpecification("damage type", "cold");

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/therianthrope/dragon/glacial-fangs.c",
            "name": "Glacial Fangs",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item": "/guilds/therianthrope/dragon/wyrms-cunning.c",
            "name": "Wyrm's Cunning",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item": "/guilds/therianthrope/dragon/rime-mastery.c",
            "name": "Rime Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "research",
            "research item": "/guilds/therianthrope/dragon/frozen-heart.c",
            "name": "Frozen Heart",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "research",
            "research item": "/guilds/therianthrope/dragon/permafrost.c",
            "name": "Permafrost",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/therianthrope/dragon/boreal-fury.c",
            "name": "Boreal Fury",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/therianthrope/dragon/ancient-wyrm.c",
            "name": "Ancient Wyrm",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/therianthrope/dragon/dragon-apotheosis.c",
            "name": "Dragon Apotheosis",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/therianthrope/dragon/primordial-dragon.c",
            "name": "Primordial Dragon",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/therianthrope/dragon/mythic-dragon.c",
            "name": "Mythic Dragon",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.30
        ]),
        ([
            "type": "research",
            "research item": "/guilds/therianthrope/dragon/silver-dragon-sovereign.c",
            "name": "Silver Dragon Sovereign",
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

    addSpecification("command template", "frost breath [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::exhale## a blast of freezing cold at "
        "##TargetName##!");
}
