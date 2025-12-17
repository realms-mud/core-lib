//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Drain Essence");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with "
        "knowledge of draining mental essence from a target, dealing damage "
        "and restoring spell points.");

    addPrerequisite("/guilds/oneiromancer/psychic-siphon/mental-leech.c",
        (["type":"research"]));

    addPrerequisite("guild rank",
        (["type": "guild rank",
            "guild": "oneiromancer",
            "value": ({ "psion", "master" })
        ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 5
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 25);

    addSpecification("siphon spell points", ({ ([
            "probability": 80,
            "base damage": 15,
            "range": 30
        ]),
        ([
            "probability": 20,
            "base damage": 30,
            "range": 60
        ])
    }));

    addSpecification("siphon hit points", ({ ([
            "probability": 100,
            "base damage": 10,
            "range": 15
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
            "rate": 1.25
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
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.05
        ]),
    }));

    addSpecification("cooldown", 30);
    addSpecification("event handler", "drainEssenceEvent");
    addSpecification("command template", "drain essence [from ##Target##]");

    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::reach## into ##TargetName##'s mind and "
        "##Infinitive::drain## ##TargetPossessive## mental essence.");
}