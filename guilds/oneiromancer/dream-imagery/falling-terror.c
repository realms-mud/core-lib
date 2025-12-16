//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Falling Terror");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of infusing attacks with the primal terror of endless "
        "falling - the sickening lurch, the rushing wind, the ground that "
        "never comes. The psychic impact manifests as crushing bludgeoning "
        "force. It can be used alone or as part of a combination attack.");
    addSpecification("usage summary", "Nightmare imagery of falling that "
        "adds bludgeon damage");

    addPrerequisite("/guilds/oneiromancer/dream-imagery/imagery-root.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 1
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("damage hit points", ({ ([
            "probability": 90,
            "base damage": 15,
            "range": 30
        ]),
        ([
            "probability": 10,
            "base damage": 30,
            "range": 60
        ])
    }));

    addSpecification("damage type", "bludgeon");

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

    addSpecification("spell point cost", 10);
    addSpecification("cooldown", 6);

    addSpecification("event handler", "fallingTerrorEvent");
    addSpecification("command template", "falling terror [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::project## the nightmare of endless falling into "
        "##TargetName##'s mind, the psychic impact hitting with "
        "bone-crushing force.");
    addSpecification("use combination message", "##Infinitive::invoke## "
        "the terror of falling");
}
