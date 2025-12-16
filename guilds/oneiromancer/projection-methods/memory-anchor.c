//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Memory Anchor");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of anchoring psionic attacks to the target's own memories. "
        "By using their recollections as a conduit, the attack gains "
        "tremendous additional potency. It can only be used as part of a "
        "combination attack.");
    addSpecification("usage summary", "A delivery method using memories "
        "for greatly increased damage");

    addPrerequisite("/guilds/oneiromancer/projection-methods/gestured-sending.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 13
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 18);

    addSpecification("damage hit points", ({ ([
            "probability": 75,
            "base damage": 20,
            "range": 40
        ]),
        ([
            "probability": 25,
            "base damage": 40,
            "range": 80
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
            "rate": 1.15
        ]),
        ([
            "type": "skill",
            "name": "mind",
            "formula": "additive",
            "rate": 0.20
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
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.50
        ]),
        ([
            "type":"attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.25
        ]),
    }));

    addSpecification("cooldown", 8);
    addSpecification("event handler", "memoryAnchorEvent");

    addSpecification("use combination message", "##Infinitive::anchor## "
        "the attack to ##TargetPossessive## deepest memories");
}
