//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Eye Contact");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of delivering psionic attacks through direct eye contact. "
        "The connection of gazes creates a powerful conduit for mental assault. "
        "It can only be used as part of a combination attack.");
    addSpecification("usage summary", "A delivery method using direct "
        "eye contact for increased accuracy");

    addPrerequisite("/guilds/oneiromancer/projection-methods/methods-root.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 1
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 5);

    addSpecification("damage hit points", ({ ([
            "probability": 90,
            "base damage": 5,
            "range": 10
        ]),
        ([
            "probability": 10,
            "base damage": 10,
            "range": 20
        ])
    }));

    addSpecification("damage type", "psionic");

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/oneiromancer/projection-methods/enhanced-projection.c",
            "name": "Enhanced Projection",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item": "/guilds/oneiromancer/projection-methods/refined-conduit.c",
            "name": "Refined Conduit",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.10
        ]),
        ([
            "type": "skill",
            "name": "mind",
            "formula": "additive",
            "rate": 0.10
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
            "rate": 0.25
        ]),
        ([
            "type":"attribute",
            "name": "charisma",
            "formula": "additive",
            "rate": 0.25
        ]),
    }));

    addSpecification("cooldown", 4);
    addSpecification("event handler", "eyeContactEvent");

    addSpecification("use combination message", "##Infinitive::lock## "
        "eyes with ##TargetName##");
}
