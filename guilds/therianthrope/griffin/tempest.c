//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Tempest");
    addSpecification("source", "therianthrope");
    addSpecification("description", "While in griffin form, you beat your "
        "wings with tremendous force, unleashing a violent gale that damages "
        "all nearby enemies.");
    addSpecification("usage summary", "An area-of-effect wind attack only "
        "usable while in griffin form");

    addPrerequisite("/guilds/therianthrope/griffin/gale-ward.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 37
        ]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("stamina point cost", 80);
    addSpecification("spell point cost", 40);
    addSpecification("cooldown", 30);

    addSpecification("cooldown modifiers", ([
        "/guilds/therianthrope/griffin/aerial-celerity.c": 5,
        "/guilds/therianthrope/griffin/zephyr-swiftness.c": 3,
    ]));

    addSpecification("stamina point cost modifiers", ([
        "/guilds/therianthrope/griffin/soaring-efficiency.c": 15,
    ]));

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/griffin/griffin-root.c"
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

    addSpecification("damage type", "air");

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/therianthrope/griffin/raptor-fury.c",
            "name": "Raptor Fury",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.10
        ]),
        ([
            "type": "research",
            "research item": "/guilds/therianthrope/griffin/hunters-instinct.c",
            "name": "Hunter's Instinct",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item": "/guilds/therianthrope/griffin/sky-mastery.c",
            "name": "Sky Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "research",
            "research item": "/guilds/therianthrope/griffin/hippogriff.c",
            "name": "Hippogriff",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/therianthrope/griffin/sky-sovereign.c",
            "name": "Sky Sovereign",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/therianthrope/griffin/storm-pinion.c",
            "name": "Storm Pinion",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/therianthrope/griffin/griffin-ascendant.c",
            "name": "Griffin Ascendant",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.30
        ]),
        ([
            "type": "research",
            "research item": "/guilds/therianthrope/griffin/lord-of-the-skies.c",
            "name": "Lord of the Skies",
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

    addSpecification("command template", "tempest");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::beat## ##InitiatorPossessive## wings with tremendous "
        "force, unleashing a violent gale that engulfs everything nearby!");
}
