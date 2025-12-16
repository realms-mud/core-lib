//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Void Thought");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of a technique that projects the absolute emptiness of the "
        "void into the target's mind, filling their consciousness with "
        "nothingness. The touch of the void leaves lasting damage to the "
        "target's mental faculties. It is a form that can either be done by "
        "itself or as part of a combination attack.");
    addSpecification("usage summary", "A void-based psionic attack of "
        "pure emptiness that impairs mental attributes");

    addPrerequisite("/guilds/oneiromancer/psionic-focus/mind-annihilation.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 35
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("damage hit points", ({ ([
            "probability": 70,
            "base damage": 120,
            "range": 240
        ]),
        ([
            "probability": 30,
            "base damage": 240,
            "range": 480
        ])
    }));

    addSpecification("damage type", "psionic");

    addSpecification("penalty to intelligence", 3);
    addSpecification("penalty to wisdom", 3);
    addSpecification("penalty to attack", 5);
    addSpecification("duration", 45);

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/oneiromancer/psionic-focus/psychic-resonance.c",
            "name": "Psychic Resonance",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
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
            "rate": 1.30
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
            "rate": 1.10
        ]),
        ([
            "type": "skill",
            "name": "senses",
            "formula": "additive",
            "rate": 0.15
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
            "rate": 0.75
        ]),
    }));

    addSpecification("spell point cost", 150);
    addSpecification("cooldown", 60);

    addSpecification("event handler", "voidThoughtEvent");
    addSpecification("command template", "void thought [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::project## the absolute emptiness of the void into "
        "##TargetName##'s mind, replacing thought with nothingness and "
        "leaving lasting damage to ##TargetPossessive## psyche.");
    addSpecification("use combination message", "##Infinitive::project## "
        "void emptiness");
}
