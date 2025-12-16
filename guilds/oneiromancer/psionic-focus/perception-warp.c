//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Perception Warp");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of a technique that violently distorts the target's sensory "
        "processing, causing their perception of reality to twist painfully. "
        "It is a form that can either be done by itself or as part of a "
        "combination attack.");
    addSpecification("usage summary", "A psionic attack that warps "
        "sensory perception");

    addPrerequisite("/guilds/oneiromancer/psionic-focus/will-breaker.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 21
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("damage hit points", ({ ([
            "probability": 80,
            "base damage": 70,
            "range": 140
        ]),
        ([
            "probability": 20,
            "base damage": 140,
            "range": 280
        ])
    }));

    addSpecification("damage type", "psionic");

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/oneiromancer/psionic-focus/cognitive-mastery.c",
            "name": "Cognitive Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item": "/guilds/oneiromancer/psionic-focus/existential-insight.c",
            "name": "Existential Insight",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "skill",
            "name": "mind",
            "formula": "logarithmic",
            "rate": 1.10
        ]),
        ([
            "type": "skill",
            "name": "senses",
            "formula": "logarithmic",
            "rate": 1.10
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.05
        ]),
        ([
            "type":"attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.5
        ]), 
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.5
        ]),
    }));

    addSpecification("spell point cost", 60);
    addSpecification("cooldown", 15);

    addSpecification("event handler", "perceptionWarpEvent");
    addSpecification("command template", "perception warp [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::twist## ##TargetName##'s senses, warping "
        "##TargetPossessive## perception of reality into something "
        "unrecognizable and painful.");
    addSpecification("use combination message", "##Infinitive::warp## "
        "sensory perception");
}
