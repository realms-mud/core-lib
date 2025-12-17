//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Mind Crush");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with "
        "the ability to utterly crush a target's mind with overwhelming "
        "psychic force.");

    addPrerequisite("/guilds/oneiromancer/dream-dominion/absolute-command.c",
        (["type":"research"]));

    addPrerequisite("guild rank",
        (["type": "guild rank",
            "guild": "oneiromancer",
            "value": ({ "master" })
        ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 9
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 125);

    addSpecification("damage hit points", ({ ([
            "probability": 70,
            "base damage": 75,
            "range": 100
        ]),
        ([
            "probability": 25,
            "base damage": 125,
            "range": 175
        ]),
        ([
            "probability": 5,
            "base damage": 200,
            "range": 250
        ])
    }));

    addSpecification("damage type", "psionic");

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/oneiromancer/dream-dominion/enhanced-dominion.c",
            "name": "Enhanced Dominion",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/oneiromancer/dream-dominion/absolute-dominion.c",
            "name": "Absolute Dominion",
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
            "rate": 1.20
        ]),
        ([
            "type": "level",
            "name": "level",
            "formula": "logarithmic",
            "rate": 1.10
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.05
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.025
        ]),
    }));

    addSpecification("cooldown", 90);
    addSpecification("event handler", "mindCrushEvent");
    addSpecification("command template", "mind crush [at ##Target##]");

    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::exert## absolute dominion over ##TargetName##'s mind, "
        "crushing it with overwhelming psychic force.");
}
