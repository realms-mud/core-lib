//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Neural Sever");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of a precision technique that severs specific neural "
        "pathways in the target's mind with surgical accuracy. "
        "It is a form that can either be done by itself or as part of a "
        "combination attack.");
    addSpecification("usage summary", "A precise psionic attack that "
        "severs neural connections");

    addPrerequisite("/guilds/oneiromancer/psionic-focus/psychic-lash.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 7
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

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
            "research item": "/guilds/oneiromancer/psionic-focus/penetrating-thought.c",
            "name": "Penetrating Thought",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.10
        ]),
        ([
            "type": "research",
            "research item": "/guilds/oneiromancer/psionic-focus/ruthless-precision.c",
            "name": "Ruthless Precision",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "skill",
            "name": "mind",
            "formula": "logarithmic",
            "rate": 1.15
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.05
        ]),
        ([
            "type": "skill",
            "name": "anatomy and physiology",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "skill",
            "name": "senses",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type":"attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.75
        ]), 
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.25
        ]),
    }));

    addSpecification("spell point cost", 20);
    addSpecification("cooldown", 7);

    addSpecification("event handler", "neuralSeverEvent");
    addSpecification("command template", "neural sever [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::make## a cutting gesture, severing neural pathways "
        "within ##TargetName##'s mind with surgical precision.");
    addSpecification("use combination message", "##Infinitive::sever## "
        "neural pathways");
}
