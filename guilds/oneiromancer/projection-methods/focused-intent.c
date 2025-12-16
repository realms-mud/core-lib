//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Focused Intent");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of focusing their mental intent to dramatically increase "
        "the damage of their psionic assault. It can only be used as part "
        "of a combination attack.");
    addSpecification("usage summary", "An intensity modifier that "
        "significantly increases damage");

    addPrerequisite("/guilds/oneiromancer/projection-methods/methods-root.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 3
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 8);

    addSpecification("damage hit points", ({ ([
            "probability": 85,
            "base damage": 8,
            "range": 16
        ]),
        ([
            "probability": 15,
            "base damage": 16,
            "range": 32
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
            "rate": 1.10
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
            "rate": 0.25
        ]),
    }));

    addSpecification("cooldown", 5);
    addSpecification("event handler", "focusedIntentMethodEvent");

    addSpecification("use combination message", "##Infinitive::focus## "
        "##InitiatorPossessive## intent with deadly precision");
}
