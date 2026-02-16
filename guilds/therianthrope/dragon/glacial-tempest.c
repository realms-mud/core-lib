//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Glacial Tempest");
    addSpecification("source", "therianthrope");
    addSpecification("description", "While in dragon form, you exhale a "
        "massive cone of freezing cold that engulfs all nearby enemies.");
    addSpecification("usage summary", "An area-of-effect cold attack only "
        "usable while in dragon form");

    addPrerequisite("/guilds/therianthrope/dragon/hoarfrost-mantle.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 49
        ]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("stamina point cost", 80);
    addSpecification("spell point cost", 40);
    addSpecification("cooldown", 30);

    addSpecification("cooldown modifiers", ([
        "/guilds/therianthrope/dragon/draconic-celerity.c": 5,
    ]));

    addSpecification("stamina point cost modifiers", ([
        "/guilds/therianthrope/dragon/draconic-efficiency.c": 15,
    ]));

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/dragon/dragon-root.c"
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

    addSpecification("damage type", "cold");

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/therianthrope/dragon/glacial-fangs.c",
            "name": "Glacial Fangs",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.10
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
            "rate": 1.15
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
            "research item": "/guilds/therianthrope/dragon/winter-ward.c",
            "name": "Winter Ward",
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

    addSpecification("command template", "glacial tempest");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::rear## back and ##Infinitive::exhale## a massive "
        "cone of freezing cold that engulfs everything nearby!");
}
