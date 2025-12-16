//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Grasping Tentacles");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of manifesting the nightmare of writhing, grasping "
        "appendages from the deep. Phantom tentacles constrict and crush "
        "the target. It can be used alone or as part of a combination attack.");
    addSpecification("usage summary", "Nightmare imagery of tentacles that "
        "adds physical crushing damage");

    addPrerequisite("/guilds/oneiromancer/dream-imagery/imagery-root.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 3
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("damage hit points", ({ ([
            "probability": 90,
            "base damage": 18,
            "range": 36
        ]),
        ([
            "probability": 10,
            "base damage": 36,
            "range": 72
        ])
    }));

    addSpecification("damage type", "physical");

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

    addSpecification("spell point cost", 12);
    addSpecification("cooldown", 6);

    addSpecification("event handler", "graspingTentaclesEvent");
    addSpecification("command template", "grasping tentacles [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::conjure## phantom tentacles from ##TargetName##'s "
        "nightmares, the writhing appendages constricting with crushing force.");
    addSpecification("use combination message", "##Infinitive::summon## "
        "grasping tentacles");
}
