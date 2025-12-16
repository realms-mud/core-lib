//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Gestured Sending");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of delivering psionic attacks through somatic gestures. "
        "The physical movements help focus and direct mental energy more "
        "efficiently. It can only be used as part of a combination attack.");
    addSpecification("usage summary", "A delivery method using gestures "
        "for improved spell point efficiency");

    addPrerequisite("/guilds/oneiromancer/projection-methods/eye-contact.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 5
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 6);

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
            "research item": "/guilds/oneiromancer/projection-methods/refined-conduit.c",
            "name": "Refined Conduit",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "skill",
            "name": "mind",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type":"attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.25
        ]),
        ([
            "type":"attribute",
            "name": "dexterity",
            "formula": "additive",
            "rate": 0.25
        ]),
    }));

    addSpecification("cooldown", 4);
    addSpecification("event handler", "gesturedSendingEvent");

    addSpecification("use combination message", "##Infinitive::trace## "
        "psychic sigils in the air");
}
