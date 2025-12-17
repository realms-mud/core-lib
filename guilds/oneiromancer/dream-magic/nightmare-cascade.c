//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Nightmare Cascade");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of triggering a cascade of nightmares that rip through "
        "multiple enemies, leaving them weakened and terrified.");
    addSpecification("usage summary", "An area attack that damages and "
        "debilitates all enemies");

    addPrerequisite("/guilds/oneiromancer/dream-magic/dream-tempest.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 43
        ]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 125);

    addSpecification("damage hit points", ({ ([
            "probability": 70,
            "base damage": 60,
            "range": 70
        ]),
        ([
            "probability": 30,
            "base damage": 100,
            "range": 120
        ])
    }));

    addSpecification("damage type", "psionic");
    addSpecification("apply enfeebled", 1);
    addSpecification("duration", 30);

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/oneiromancer/dream-magic/dream-mastery.c",
            "name": "Dream Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/oneiromancer/dream-magic/oneiric-potency.c",
            "name": "Oneiric Potency",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/oneiromancer/dream-magic/nightmare-potency.c",
            "name": "Nightmare Potency",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "skill",
            "name": "mind",
            "formula": "additive",
            "rate": 0.30
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.30
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.50
        ]),
    }));

    addSpecification("cooldown", 60);
    addSpecification("event handler", "nightmareCascadeEvent");
    addSpecification("command template", "nightmare cascade");

    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::trigger## a cascading wave of nightmares that washes "
        "over all nearby enemies.");
}
