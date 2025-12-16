//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Unraveling Reality");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of inflicting the nightmare of reality itself coming apart - "
        "the fabric of existence fraying, fundamental truths dissolving, "
        "cause and effect becoming meaningless. The target is left paralyzed "
        "with existential horror. It can be used alone or as part of a "
        "combination attack.");
    addSpecification("usage summary", "Nightmare imagery of reality dissolution "
        "that applies paralysis");

    addPrerequisite("/guilds/oneiromancer/dream-imagery/forgotten-identity.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 59
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("damage hit points", ({ ([
            "probability": 75,
            "base damage": 120,
            "range": 240
        ]),
        ([
            "probability": 25,
            "base damage": 240,
            "range": 480
        ])
    }));

    addSpecification("damage type", "psionic");

    // Persisted paralysis
    addSpecification("apply paralysis", 1);
    addSpecification("duration", 8);

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

    addSpecification("spell point cost", 120);
    addSpecification("cooldown", 90);

    addSpecification("event handler", "unravelingRealityEvent");
    addSpecification("command template", "unraveling reality [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::unravel## reality itself in ##TargetName##'s mind, "
        "the nightmare of existence dissolving leaving ##TargetObjective## "
        "paralyzed with horror.");
    addSpecification("use combination message", "##Infinitive::unravel## "
        "reality itself");
}
