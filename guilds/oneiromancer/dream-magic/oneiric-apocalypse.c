//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Oneiric Apocalypse");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of triggering an apocalyptic collapse of the boundary "
        "between dreams and reality, devastating all enemies with overwhelming "
        "nightmare energy.");
    addSpecification("usage summary", "An apocalyptic area attack with "
        "damage and severe debuffs");

    addPrerequisite("/guilds/oneiromancer/dream-magic/dream-cataclysm.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 59
        ]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 250);
    addSpecification("repeat effect", 2);

    addSpecification("damage hit points", ({ ([
            "probability": 60,
            "base damage": 100,
            "range": 120
        ]),
        ([
            "probability": 30,
            "base damage": 175,
            "range": 200
        ]),
        ([
            "probability": 10,
            "base damage": 300,
            "range": 350
        ])
    }));

    addSpecification("damage type", "psionic");
    addSpecification("apply enfeebled", 1);
    addSpecification("apply slow", 1);
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
            "rate": 0.45
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.45
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.70
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.45
        ]),
    }));

    addSpecification("cooldown", 180);
    addSpecification("event handler", "oneiricApocalypseEvent");
    addSpecification("command template", "oneiric apocalypse");

    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::tear## open the boundary between dreams and reality, "
        "unleashing an apocalyptic flood of nightmare energy.");
}
