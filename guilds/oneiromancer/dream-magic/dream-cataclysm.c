//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Dream Cataclysm");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of unleashing a cataclysmic wave of dream energy that "
        "devastates all enemies in the area with repeated strikes.");
    addSpecification("usage summary", "A devastating area attack with "
        "multiple hits");

    addPrerequisite("/guilds/oneiromancer/dream-magic/realm-of-nightmares.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 55
        ]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 200);
    addSpecification("repeat effect", 3);

    addSpecification("damage hit points", ({ ([
            "probability": 60,
            "base damage": 80,
            "range": 100
        ]),
        ([
            "probability": 30,
            "base damage": 130,
            "range": 160
        ]),
        ([
            "probability": 10,
            "base damage": 200,
            "range": 250
        ])
    }));

    addSpecification("damage type", "psionic");

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
            "rate": 0.40
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.40
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.65
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.40
        ]),
    }));

    addSpecification("cooldown", 120);
    addSpecification("event handler", "dreamCataclysmEvent");
    addSpecification("command template", "dream cataclysm");

    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::unleash## a cataclysmic surge of dream energy that "
        "tears through all nearby enemies in wave after devastating wave.");
}
