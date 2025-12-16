//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Teeth Crumbling");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of inflicting the nightmare of bodily disintegration - "
        "teeth crumbling and falling out, the horror of losing control of "
        "one's own form. The target's constitution is temporarily impaired. "
        "It can be used alone or as part of a combination attack.");
    addSpecification("usage summary", "Nightmare imagery of bodily decay that "
        "penalizes constitution");

    addPrerequisite("/guilds/oneiromancer/dream-imagery/dissolving-flesh.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 19
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("damage hit points", ({ ([
            "probability": 85,
            "base damage": 40,
            "range": 80
        ]),
        ([
            "probability": 15,
            "base damage": 80,
            "range": 160
        ])
    }));

    addSpecification("damage type", "psionic");

    // Persisted constitution penalty
    addSpecification("penalty to constitution", 3);
    addSpecification("duration", 25);

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

    addSpecification("spell point cost", 35);
    addSpecification("cooldown", 25);

    addSpecification("event handler", "teethCrumblingEvent");
    addSpecification("command template", "teeth crumbling [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::inflict## the nightmare of bodily decay upon "
        "##TargetName##, phantom teeth crumbling as ##TargetPossessive## "
        "vitality falters.");
    addSpecification("use combination message", "##Infinitive::crumble## "
        "with decay imagery");
}
