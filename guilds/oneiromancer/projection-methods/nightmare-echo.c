//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Nightmare Echo");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of causing psionic attacks to echo through the targets "
        "mind, repeating the horror again and again. The lingering effect "
        "causes additional damage over time. It can only be used as part "
        "of a combination attack.");
    addSpecification("usage summary", "A tactical modifier that causes "
        "attacks to echo repeatedly");

    addPrerequisite("/guilds/oneiromancer/projection-methods/defensive-feedback.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 61
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 55);

    addSpecification("damage hit points", ({ ([
            "probability": 70,
            "base damage": 80,
            "range": 160
        ]),
        ([
            "probability": 30,
            "base damage": 160,
            "range": 320
        ])
    }));

    addSpecification("damage type", "psionic");

    addSpecification("modifiers", ({ 
        ([
            "type": "skill",
            "name": "mind",
            "formula": "additive",
            "rate": 0.40
        ]),
        ([
            "type": "skill",
            "name": "senses",
            "formula": "additive",
            "rate": 0.20
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
            "rate": 0.30
        ]),
    }));

    addSpecification("cooldown", 20);
    addSpecification("event handler", "nightmareEchoEvent");

    addSpecification("use combination message", "##Infinitive::cause## "
        "the nightmare to echo endlessly");
}
