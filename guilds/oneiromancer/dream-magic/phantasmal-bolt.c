//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Phantasmal Bolt");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of hurling a concentrated bolt of dream energy that "
        "strikes with illusory force made real.");
    addSpecification("usage summary", "A ranged psionic attack with "
        "improved damage");

    addPrerequisite("/guilds/oneiromancer/dream-magic/waking-dreams.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 7
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 20);

    addSpecification("damage hit points", ({ ([
            "probability": 80,
            "base damage": 15,
            "range": 25
        ]),
        ([
            "probability": 20,
            "base damage": 25,
            "range": 35
        ])
    }));

    addSpecification("damage type", "psionic");

    addSpecification("modifiers", ({ 
        ([
            "type": "skill",
            "name": "mind",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type":"attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.30
        ]),
        ([
            "type":"attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.20
        ]),
    }));

    addSpecification("cooldown", 8);
    addSpecification("event handler", "phantasmalBoltEvent");
    addSpecification("command template", "phantasmal bolt [at ##Target##]");

    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::hurl## a shimmering bolt of phantasmal energy at "
        "##TargetName##.");
}
