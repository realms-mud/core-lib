//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Psychic Touch");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of delivering psionic attacks through physical contact. "
        "The direct touch creates an overwhelming psychic conduit, massively "
        "increasing damage but requiring close proximity. It can only be "
        "used as part of a combination attack.");
    addSpecification("usage summary", "A delivery method using touch "
        "for massive damage increase");

    addPrerequisite("/guilds/oneiromancer/projection-methods/memory-anchor.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 21
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 25);

    addSpecification("damage hit points", ({ ([
            "probability": 65,
            "base damage": 35,
            "range": 70
        ]),
        ([
            "probability": 35,
            "base damage": 70,
            "range": 140
        ])
    }));

    addSpecification("damage type", "psionic");

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/oneiromancer/projection-methods/amplified-conduit.c",
            "name": "Amplified Conduit",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "research",
            "research item": "/guilds/oneiromancer/projection-methods/perfected-conduit.c",
            "name": "Perfected Conduit",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "skill",
            "name": "mind",
            "formula": "additive",
            "rate": 0.25
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
            "rate": 0.10
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
            "rate": 0.50
        ]),
    }));

    addSpecification("cooldown", 12);
    addSpecification("event handler", "psychicTouchEvent");

    addSpecification("use combination message", "##Infinitive::reach## "
        "out to touch ##TargetName## with devastating psychic force");
}
