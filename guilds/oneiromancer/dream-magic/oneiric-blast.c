//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Oneiric Blast");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of unleashing a powerful blast of pure dream energy that "
        "tears through the target's mental defenses.");
    addSpecification("usage summary", "A powerful area-effect psionic attack");

    addPrerequisite("/guilds/oneiromancer/dream-magic/lucid-strike.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 23
        ]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 55);

    addSpecification("damage hit points", ({ ([
            "probability": 80,
            "base damage": 30,
            "range": 40
        ]),
        ([
            "probability": 20,
            "base damage": 50,
            "range": 60
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
            "rate": 0.25
        ]),
    }));

    addSpecification("cooldown", 20);
    addSpecification("event handler", "oneiricBlastEvent");
    addSpecification("command template", "oneiric blast");

    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::release## a devastating wave of oneiric energy that "
        "washes over all nearby enemies.");
}
