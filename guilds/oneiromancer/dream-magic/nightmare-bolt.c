//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Nightmare Bolt");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of concentrating pure nightmare energy into a devastating "
        "bolt that assaults both mind and body.");
    addSpecification("usage summary", "A powerful psionic attack that deals "
        "significant damage");

    addPrerequisite("/guilds/oneiromancer/dream-magic/mind-fog.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 15
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 35);

    addSpecification("damage hit points", ({ ([
            "probability": 70,
            "base damage": 25,
            "range": 35
        ]),
        ([
            "probability": 30,
            "base damage": 40,
            "range": 50
        ])
    }));

    addSpecification("damage type", "psionic");

    addSpecification("modifiers", ({ 
        ([
            "type": "skill",
            "name": "mind",
            "formula": "additive",
            "rate": 0.20
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
            "rate": 0.35
        ]),
        ([
            "type":"attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.20
        ]),
    }));

    addSpecification("cooldown", 10);
    addSpecification("event handler", "nightmareBoltEvent");
    addSpecification("command template", "nightmare bolt [at ##Target##]");

    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::launch## a bolt of concentrated nightmare energy at "
        "##TargetName##, filling ##TargetPossessive## mind with terror.");
}
