//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Thought Crush");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of a technique that applies overwhelming mental pressure "
        "to the target's mind, as if crushing their thoughts in a vice. "
        "It is a form that can either be done by itself or as part of a "
        "combination attack.");
    addSpecification("usage summary", "A crushing psionic attack that "
        "overwhelms the mind with pressure");

    addPrerequisite("/guilds/oneiromancer/psionic-focus/mind-spike.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 5
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("damage hit points", ({ ([
            "probability": 85,
            "base damage": 35,
            "range": 70
        ]),
        ([
            "probability": 15,
            "base damage": 70,
            "range": 140
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

    addSpecification("spell point cost", 25);
    addSpecification("cooldown", 8);

    addSpecification("event handler", "thoughtCrushEvent");
    addSpecification("command template", "thought crush [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::clench## ##InitiatorPossessive## fist and "
        "##Infinitive::squeeze##, crushing ##TargetName##'s thoughts "
        "under immense psychic pressure.");
    addSpecification("use combination message", "##Infinitive::crush## "
        "with overwhelming mental force");
}
