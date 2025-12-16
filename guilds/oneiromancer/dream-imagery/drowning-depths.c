//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Drowning Depths");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of inflicting the nightmare of drowning - lungs burning, "
        "the crushing pressure of fathomless depths, the desperate need for "
        "air that will never come. The horror manifests as water damage. "
        "It can be used alone or as part of a combination attack.");
    addSpecification("usage summary", "Nightmare imagery of drowning that "
        "adds water damage");

    addPrerequisite("/guilds/oneiromancer/dream-imagery/endless-void.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 39
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("damage hit points", ({ ([
            "probability": 80,
            "base damage": 80,
            "range": 160
        ]),
        ([
            "probability": 20,
            "base damage": 160,
            "range": 320
        ])
    }));

    addSpecification("damage type", "water");

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
            "name": "elemental water",
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
            "rate": 0.5
        ]),
    }));

    addSpecification("spell point cost", 65);
    addSpecification("cooldown", 18);

    addSpecification("event handler", "drowningDepthsEvent");
    addSpecification("command template", "drowning depths [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::drag## ##TargetName## into the nightmare of drowning "
        "in fathomless depths, phantom waters crushing ##TargetPossessive## "
        "lungs.");
    addSpecification("use combination message", "##Infinitive::drown## "
        "in nightmare depths");
}
