//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Lightning Strike");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of manifesting the nightmare of being struck by lightning - "
        "the blinding flash, the deafening crack, every nerve screaming in "
        "agony. It can be used alone or as part of a combination attack.");
    addSpecification("usage summary", "Nightmare imagery of electrocution that "
        "adds electricity damage");

    addPrerequisite("/guilds/oneiromancer/dream-imagery/grasping-tentacles.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 9
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("damage hit points", ({ ([
            "probability": 85,
            "base damage": 28,
            "range": 56
        ]),
        ([
            "probability": 15,
            "base damage": 56,
            "range": 112
        ])
    }));

    addSpecification("damage type", "electricity");

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
            "type": "skill",
            "name": "elemental air",
            "formula": "additive",
            "rate": 0.05
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

    addSpecification("spell point cost", 20);
    addSpecification("cooldown", 8);

    addSpecification("event handler", "lightningStrikeEvent");
    addSpecification("command template", "lightning strike [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::manifest## the nightmare of a lightning strike in "
        "##TargetName##'s mind, psychic electricity arcing through "
        "##TargetPossessive## consciousness.");
    addSpecification("use combination message", "##Infinitive::strike## "
        "with nightmare lightning");
}
