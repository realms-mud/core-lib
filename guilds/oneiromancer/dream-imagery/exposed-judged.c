//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Exposed and Judged");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of inflicting the nightmare of public humiliation - naked "
        "before a crowd, every flaw and secret exposed to merciless judgment. "
        "The shame leaves the target's defenses compromised. It can be used "
        "alone or as part of a combination attack.");
    addSpecification("usage summary", "Nightmare imagery of exposure that "
        "reduces defense");

    addPrerequisite("/guilds/oneiromancer/dream-imagery/teeth-crumbling.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 27
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

    // Persisted defense penalties
    addSpecification("penalty to defense", 10);
    addSpecification("penalty to charisma", 2);
    addSpecification("duration", 20);

    addSpecification("modifiers", ({ 
        ([
            "type": "skill",
            "name": "mind",
            "formula": "logarithmic",
            "rate": 1.10
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
            "rate": 0.25
        ]),
        ([
            "type": "attribute",
            "name": "charisma",
            "formula": "additive",
            "rate": 0.25
        ]),
    }));

    addSpecification("spell point cost", 45);
    addSpecification("cooldown", 30);

    addSpecification("event handler", "exposedJudgedEvent");
    addSpecification("command template", "exposed and judged [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::expose## ##TargetName##'s deepest shames to nightmare "
        "judgment, leaving ##TargetObjective## vulnerable and diminished.");
    addSpecification("use combination message", "##Infinitive::expose## "
        "to nightmare judgment");
}
