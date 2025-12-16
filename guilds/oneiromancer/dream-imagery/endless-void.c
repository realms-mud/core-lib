//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Endless Void");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of inflicting the nightmare of absolute emptiness - drifting "
        "alone in infinite darkness, no up or down, no sound, no hope. The "
        "existential horror manifests as chaos damage. It can be used alone "
        "or as part of a combination attack.");
    addSpecification("usage summary", "Nightmare imagery of the void that "
        "adds chaos damage");

    addPrerequisite("/guilds/oneiromancer/dream-imagery/buried-alive.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 31
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("damage hit points", ({ ([
            "probability": 80,
            "base damage": 65,
            "range": 130
        ]),
        ([
            "probability": 20,
            "base damage": 130,
            "range": 260
        ])
    }));

    addSpecification("damage type", "chaos");

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
            "rate": 0.5
        ]),
    }));

    addSpecification("spell point cost", 55);
    addSpecification("cooldown", 16);

    addSpecification("event handler", "endlessVoidEvent");
    addSpecification("command template", "endless void [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::cast## ##TargetName## into the nightmare of the "
        "endless void, existential chaos tearing at ##TargetPossessive## "
        "sanity.");
    addSpecification("use combination message", "##Infinitive::cast## "
        "into the endless void");
}
