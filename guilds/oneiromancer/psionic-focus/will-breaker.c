//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Will Breaker");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of a technique that directly targets the target's resolve "
        "and determination, breaking their will to resist. "
        "It is a form that can either be done by itself or as part of a "
        "combination attack.");
    addSpecification("usage summary", "A psionic attack that breaks "
        "willpower and resolve");

    addPrerequisite("/guilds/oneiromancer/psionic-focus/memory-shatter.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 17
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("damage hit points", ({ ([
            "probability": 80,
            "base damage": 60,
            "range": 120
        ]),
        ([
            "probability": 20,
            "base damage": 120,
            "range": 240
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
            "rate": 1.10
        ]),
        ([
            "type": "research",
            "research item": "/guilds/oneiromancer/psionic-focus/cognitive-mastery.c",
            "name": "Cognitive Mastery",
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
            "rate": 0.25
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
            "rate": 0.5
        ]),
    }));

    addSpecification("spell point cost", 50);
    addSpecification("cooldown", 14);

    addSpecification("event handler", "willBreakerEvent");
    addSpecification("command template", "will breaker [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::bore## into ##TargetName##'s psyche, systematically "
        "dismantling ##TargetPossessive## will to resist.");
    addSpecification("use combination message", "##Infinitive::break## "
        "the will to resist");
}
