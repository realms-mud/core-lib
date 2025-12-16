//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Buried Alive");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of inflicting the nightmare of being buried alive - the "
        "crushing weight of earth, the suffocating darkness, the desperate "
        "clawing at the coffin lid. The horror manifests as crushing earth "
        "damage. It can be used alone or as part of a combination attack.");
    addSpecification("usage summary", "Nightmare imagery of burial that "
        "adds earth damage");

    addPrerequisite("/guilds/oneiromancer/dream-imagery/paralytic-dread.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 23
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("damage hit points", ({ ([
            "probability": 80,
            "base damage": 50,
            "range": 100
        ]),
        ([
            "probability": 20,
            "base damage": 100,
            "range": 200
        ])
    }));

    addSpecification("damage type", "earth");

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
            "name": "elemental earth",
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

    addSpecification("spell point cost", 40);
    addSpecification("cooldown", 14);

    addSpecification("event handler", "buriedAliveEvent");
    addSpecification("command template", "buried alive [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::inflict## the nightmare of being buried alive upon "
        "##TargetName##, phantom earth crushing down on ##TargetPossessive## "
        "consciousness.");
    addSpecification("use combination message", "##Infinitive::bury## "
        "in nightmare earth");
}
