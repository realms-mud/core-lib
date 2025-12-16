//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Ego Rend");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of a technique that tears at the target's sense of self, "
        "fragmenting their identity and ego. It is a form that can either "
        "be done by itself or as part of a combination attack.");
    addSpecification("usage summary", "A rending psionic attack that "
        "fragments the target's identity");

    addPrerequisite("/guilds/oneiromancer/psionic-focus/thought-crush.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 9
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("damage hit points", ({ ([
            "probability": 80,
            "base damage": 40,
            "range": 80
        ]),
        ([
            "probability": 20,
            "base damage": 80,
            "range": 160
        ])
    }));

    addSpecification("damage type", "psionic");

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/oneiromancer/psionic-focus/ruthless-precision.c",
            "name": "Ruthless Precision",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item": "/guilds/oneiromancer/psionic-focus/overwhelming-presence.c",
            "name": "Overwhelming Presence",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "skill",
            "name": "mind",
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
            "type": "skill",
            "name": "senses",
            "formula": "additive",
            "rate": 0.10
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
        ([
            "type": "attribute",
            "name": "charisma",
            "formula": "additive",
            "rate": 0.25
        ]),
    }));

    addSpecification("spell point cost", 30);
    addSpecification("cooldown", 10);

    addSpecification("event handler", "egoRendEvent");
    addSpecification("command template", "ego rend [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::reach## into ##TargetName##'s psyche and "
        "##Infinitive::tear## at the very fabric of ##TargetPossessive## "
        "identity.");
    addSpecification("use combination message", "##Infinitive::rend## "
        "the ego asunder");
}
