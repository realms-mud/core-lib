//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Dissolving Flesh");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of inflicting the nightmare of flesh dissolving - watching "
        "helplessly as skin bubbles and sloughs away, bones becoming visible "
        "beneath. The horror manifests as corrosive acid damage. It can be "
        "used alone or as part of a combination attack.");
    addSpecification("usage summary", "Nightmare imagery of dissolution that "
        "adds acid damage");

    addPrerequisite("/guilds/oneiromancer/dream-imagery/burning-alive.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 13
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("damage hit points", ({ ([
            "probability": 85,
            "base damage": 35,
            "range": 70
        ]),
        ([
            "probability": 15,
            "base damage": 70,
            "range": 140
        ])
    }));

    addSpecification("damage type", "acid");

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

    addSpecification("spell point cost", 25);
    addSpecification("cooldown", 10);

    addSpecification("event handler", "dissolvingFleshEvent");
    addSpecification("command template", "dissolving flesh [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::project## the nightmare of dissolving flesh into "
        "##TargetName##'s mind, phantom acid eating away at "
        "##TargetPossessive## psyche.");
    addSpecification("use combination message", "##Infinitive::dissolve## "
        "with nightmare acid");
}
