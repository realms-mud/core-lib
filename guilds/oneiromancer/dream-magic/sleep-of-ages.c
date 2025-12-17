//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Sleep of Ages");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of overwhelming a target's mind with the weight of "
        "countless dreams, potentially paralyzing them with slumber.");
    addSpecification("usage summary", "An attack that can paralyze targets");

    addPrerequisite("/guilds/oneiromancer/dream-magic/nightmare-bolt.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 19
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 45);

    addSpecification("damage hit points", ({ ([
            "probability": 100,
            "base damage": 15,
            "range": 20
        ])
    }));

    addSpecification("damage type", "psionic");
    addSpecification("apply paralysis", 1);
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
            "rate": 0.15
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.15
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.30
        ]),
    }));

    addSpecification("cooldown", 60);
    addSpecification("event handler", "sleepOfAgesEvent");
    addSpecification("command template", "sleep of ages [at ##Target##]");

    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::call## upon the weight of ancient dreams to press down "
        "upon ##TargetName##.");
}
