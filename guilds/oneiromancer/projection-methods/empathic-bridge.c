//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Empathic Bridge");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of delivering psionic attacks through an emotional "
        "connection. By attuning to the target's feelings, the attack "
        "bypasses some mental defenses. It can only be used as part of a "
        "combination attack.");
    addSpecification("usage summary", "A delivery method using emotional "
        "connection to bypass resistance");

    addPrerequisite("/guilds/oneiromancer/projection-methods/whispered-word.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 9
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 12);

    addSpecification("damage hit points", ({ ([
            "probability": 80,
            "base damage": 12,
            "range": 24
        ]),
        ([
            "probability": 20,
            "base damage": 24,
            "range": 48
        ])
    }));

    addSpecification("damage type", "psionic");

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/oneiromancer/projection-methods/refined-conduit.c",
            "name": "Refined Conduit",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "research",
            "research item": "/guilds/oneiromancer/projection-methods/amplified-conduit.c",
            "name": "Amplified Conduit",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.10
        ]),
        ([
            "type": "skill",
            "name": "mind",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "skill",
            "name": "senses",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "additive",
            "rate": 0.05
        ]),
        ([
            "type":"attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.50
        ]),
        ([
            "type":"attribute",
            "name": "charisma",
            "formula": "additive",
            "rate": 0.25
        ]),
    }));

    addSpecification("cooldown", 6);
    addSpecification("event handler", "empathicBridgeEvent");

    addSpecification("use combination message", "##Infinitive::forge## "
        "an empathic bridge to ##TargetPossessive## emotions");
}
