//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Memory Shatter");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of a technique that attacks through the target's own "
        "memories, shattering recollections into painful fragments. "
        "It is a form that can either be done by itself or as part of a "
        "combination attack.");
    addSpecification("usage summary", "A psionic attack that weaponizes "
        "the target's memories");

    addPrerequisite("/guilds/oneiromancer/psionic-focus/ego-rend.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 13
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("damage hit points", ({ ([
            "probability": 80,
            "base damage": 50,
            "range": 100
        ]),
        ([
            "probability": 20,
            "base damage": 100,
            "range": 200
        ])
    }));

    addSpecification("damage type", "psionic");

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/oneiromancer/psionic-focus/overwhelming-presence.c",
            "name": "Overwhelming Presence",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item": "/guilds/oneiromancer/psionic-focus/cognitive-mastery.c",
            "name": "Cognitive Mastery",
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

    addSpecification("spell point cost", 40);
    addSpecification("cooldown", 12);

    addSpecification("event handler", "memoryShatterEvent");
    addSpecification("command template", "memory shatter [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::reach## into ##TargetName##'s past, shattering "
        "precious memories into jagged, painful fragments.");
    addSpecification("use combination message", "##Infinitive::shatter## "
        "treasured memories");
}
