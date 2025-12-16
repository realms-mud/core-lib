//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Thoughtform Projection");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of projecting a visible thoughtform to deliver attacks. "
        "The terrifying manifestation serves as a herald of the mental "
        "assault, adding psychological impact. It can only be used as part "
        "of a combination attack.");
    addSpecification("usage summary", "A delivery method using a visible "
        "manifestation for additional psychological damage");

    addPrerequisite("/guilds/oneiromancer/projection-methods/dream-thread.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 25
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 28);

    addSpecification("damage hit points", ({ ([
            "probability": 70,
            "base damage": 30,
            "range": 60
        ]),
        ([
            "probability": 30,
            "base damage": 60,
            "range": 120
        ])
    }));

    addSpecification("damage type", "psionic");

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/oneiromancer/projection-methods/perfected-conduit.c",
            "name": "Perfected Conduit",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/oneiromancer/projection-methods/transcendent-conduit.c",
            "name": "Transcendent Conduit",
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
            "name": "evocation",
            "formula": "additive",
            "rate": 0.20
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
            "name": "charisma",
            "formula": "additive",
            "rate": 0.50
        ]),
    }));

    addSpecification("cooldown", 14);
    addSpecification("event handler", "thoughtformProjectionEvent");

    addSpecification("use combination message", "##Infinitive::project## "
        "a terrifying thoughtform at ##TargetName##");
}
