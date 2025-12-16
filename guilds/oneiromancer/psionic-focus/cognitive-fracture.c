//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Cognitive Fracture");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of a technique that splinters the target's capacity for "
        "logical thought, creating fractures in their reasoning. The target "
        "is left enfeebled, their mental faculties impaired. "
        "It is a form that can either be done by itself or as part of a "
        "combination attack.");
    addSpecification("usage summary", "A psionic attack that fractures "
        "logical thought processes and enfeebles the target");

    addPrerequisite("/guilds/oneiromancer/psionic-focus/dream-fang.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 15
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("damage hit points", ({ ([
            "probability": 80,
            "base damage": 55,
            "range": 110
        ]),
        ([
            "probability": 20,
            "base damage": 110,
            "range": 220
        ])
    }));

    addSpecification("damage type", "psionic");

    // Persisted enfeebled effect
    addSpecification("apply enfeebled", 1);
    addSpecification("duration", 30);

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/oneiromancer/psionic-focus/nightmare-affinity.c",
            "name": "Nightmare Affinity",
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
            "rate": 0.75
        ]), 
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.25
        ]),
    }));

    addSpecification("spell point cost", 45);
    addSpecification("cooldown", 12);

    addSpecification("event handler", "cognitiveFractureEvent");
    addSpecification("command template", "cognitive fracture [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::focus## intently, creating hairline fractures "
        "throughout ##TargetName##'s capacity for reason, leaving "
        "##TargetObjective## enfeebled.");
    addSpecification("use combination message", "##Infinitive::fracture## "
        "cognitive processes");
}
