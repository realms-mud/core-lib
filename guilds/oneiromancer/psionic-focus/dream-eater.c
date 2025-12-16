//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Dream Eater");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of a technique that devours the target's psychic energy, "
        "draining both their vitality and mental reserves. The violation of "
        "their dreamscape leaves them slowed and sluggish. It is a form that "
        "can either be done by itself or as part of a combination attack.");
    addSpecification("usage summary", "A draining psionic attack that "
        "consumes mental energy and slows the target");

    addPrerequisite("/guilds/oneiromancer/psionic-focus/soul-flense.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 33
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("damage hit points", ({ ([
            "probability": 80,
            "base damage": 95,
            "range": 190
        ]),
        ([
            "probability": 20,
            "base damage": 190,
            "range": 380
        ])
    }));
    addSpecification("damage spell points", ({ ([
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

    // Persisted slow effect
    addSpecification("apply slow", 1);
    addSpecification("duration", 20);

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/oneiromancer/psionic-focus/annihilating-will.c",
            "name": "Annihilating Will",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "research",
            "research item": "/guilds/oneiromancer/psionic-focus/void-mastery.c",
            "name": "Void Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
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
    }));

    addSpecification("spell point cost", 100);
    addSpecification("cooldown", 30);

    addSpecification("event handler", "dreamEaterEvent");
    addSpecification("command template", "dream eater [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::open## ##InitiatorPossessive## maw of consciousness "
        "and ##Infinitive::devour## ##TargetName##'s psychic essence, leaving "
        "##TargetObjective## sluggish and drained.");
    addSpecification("use combination message", "##Infinitive::devour## "
        "psychic essence");
}
