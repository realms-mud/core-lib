//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Forgotten Identity");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of inflicting the nightmare of forgetting oneself - looking "
        "in a mirror and seeing a stranger, memories of family fading, one's "
        "own name becoming meaningless. The identity dissolution severely "
        "impairs the target's mental faculties. It can be used alone or as "
        "part of a combination attack.");
    addSpecification("usage summary", "Nightmare imagery of identity loss that "
        "severely penalizes intelligence and wisdom");

    addPrerequisite("/guilds/oneiromancer/dream-imagery/loved-ones-twisted.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 51
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("damage hit points", ({ ([
            "probability": 75,
            "base damage": 100,
            "range": 200
        ]),
        ([
            "probability": 25,
            "base damage": 200,
            "range": 400
        ])
    }));

    addSpecification("damage type", "psionic");

    // Persisted severe mental penalties
    addSpecification("penalty to intelligence", 4);
    addSpecification("penalty to wisdom", 4);
    addSpecification("duration", 35);

    addSpecification("modifiers", ({ 
        ([
            "type": "skill",
            "name": "mind",
            "formula": "logarithmic",
            "rate": 1.15
        ]),
        ([
            "type": "skill",
            "name": "evocation",
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

    addSpecification("spell point cost", 90);
    addSpecification("cooldown", 45);

    addSpecification("event handler", "forgottenIdentityEvent");
    addSpecification("command template", "forgotten identity [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::erase## ##TargetName##'s sense of self, the nightmare "
        "of forgotten identity leaving ##TargetObjective## mentally crippled.");
    addSpecification("use combination message", "##Infinitive::erase## "
        "their identity");
}
