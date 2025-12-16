//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Paralytic Dread");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of inflicting the nightmare of being frozen in place while "
        "danger approaches - the desperate need to move while muscles refuse "
        "to respond. The target is left sluggish and slowed. It can be used "
        "alone or as part of a combination attack.");
    addSpecification("usage summary", "Nightmare imagery of paralysis that "
        "slows the target");

    addPrerequisite("/guilds/oneiromancer/dream-imagery/lightning-strike.c",
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
            "probability": 85,
            "base damage": 30,
            "range": 60
        ]),
        ([
            "probability": 15,
            "base damage": 60,
            "range": 120
        ])
    }));

    addSpecification("damage type", "psionic");

    // Persisted slow effect
    addSpecification("apply slow", 1);
    addSpecification("duration", 15);

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
    }));

    addSpecification("spell point cost", 30);
    addSpecification("cooldown", 20);

    addSpecification("event handler", "paralyticDreadEvent");
    addSpecification("command template", "paralytic dread [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::inflict## the nightmare of paralysis upon "
        "##TargetName##, leaving ##TargetObjective## sluggish with dread.");
    addSpecification("use combination message", "##Infinitive::freeze## "
        "with paralytic dread");
}
