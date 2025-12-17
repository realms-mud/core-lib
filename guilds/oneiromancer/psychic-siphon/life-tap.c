//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Life Tap");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with "
        "knowledge of draining life force from a target to heal themselves.");

    addPrerequisite("/guilds/oneiromancer/psychic-siphon/drain-essence.c",
        (["type":"research"]));

    addPrerequisite("guild rank",
        (["type": "guild rank",
            "guild": "oneiromancer",
            "value": ({ "psion", "master" })
        ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 9
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 35);

    addSpecification("siphon hit points", ({ ([
            "probability": 80,
            "base damage": 20,
            "range": 40
        ]),
        ([
            "probability": 20,
            "base damage": 40,
            "range": 80
        ])
    }));

    addSpecification("damage type", "psionic");

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/oneiromancer/psychic-siphon/improved-siphon.c",
            "name": "Improved Siphon",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "research",
            "research item": "/guilds/oneiromancer/psychic-siphon/efficient-drain.c",
            "name": "Efficient Drain",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/oneiromancer/psychic-siphon/master-siphon.c",
            "name": "Master Siphon",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.35
        ]),
        ([
            "type": "skill",
            "name": "mind",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.10
        ]),
        ([
            "type": "level",
            "name": "level",
            "formula": "logarithmic",
            "rate": 1.05
        ]),
    }));

    addSpecification("cooldown", 45);
    addSpecification("event handler", "lifeTapEvent");
    addSpecification("command template", "life tap [from ##Target##]");

    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::siphon## life force from ##TargetName##, "
        "mending ##InitiatorPossessive## own wounds.");
}
