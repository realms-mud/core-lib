//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Dream Rend");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of tearing at a target's connection to reality with "
        "claws of nightmare energy.");
    addSpecification("usage summary", "A high-damage single-target attack");

    addPrerequisite("/guilds/oneiromancer/dream-magic/veil-of-dreams.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 31
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 60);

    addSpecification("damage hit points", ({ ([
            "probability": 60,
            "base damage": 45,
            "range": 55
        ]),
        ([
            "probability": 40,
            "base damage": 70,
            "range": 80
        ])
    }));

    addSpecification("damage type", "psionic");

    addSpecification("modifiers", ({ 
        ([
            "type": "skill",
            "name": "mind",
            "formula": "additive",
            "rate": 0.25
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type":"attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.40
        ]),
        ([
            "type":"attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.25
        ]),
    }));

    addSpecification("cooldown", 15);
    addSpecification("event handler", "dreamRendEvent");
    addSpecification("command template", "dream rend [at ##Target##]");

    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::rake## ##TargetName## with claws of solidified "
        "nightmare.");
}
