//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Subtle Approach");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of attacking with subtlety, masking the psychic assault "
        "to reduce the chance of drawing attention or retaliation. It can "
        "only be used as part of a combination attack.");
    addSpecification("usage summary", "A tactical modifier that reduces "
        "threat generation");

    addPrerequisite("/guilds/oneiromancer/projection-methods/methods-root.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 7
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 8);

    addSpecification("damage hit points", ({ ([
            "probability": 90,
            "base damage": 6,
            "range": 12
        ]),
        ([
            "probability": 10,
            "base damage": 12,
            "range": 24
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
            "name": "hiding",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "skill",
            "name": "stealth",
            "formula": "additive",
            "rate": 0.10
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

    addSpecification("cooldown", 5);
    addSpecification("event handler", "subtleApproachEvent");

    addSpecification("use combination message", "##Infinitive::mask## "
        "the assault with subtle misdirection");
}
