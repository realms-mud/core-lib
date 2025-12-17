//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Mind Prison");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of trapping a target's consciousness within a prison of "
        "their own worst fears and memories.");
    addSpecification("usage summary", "A devastating attack that damages "
        "and debilitates");

    addPrerequisite("/guilds/oneiromancer/dream-magic/dream-rend.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 35
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 75);

    addSpecification("damage hit points", ({ ([
            "probability": 60,
            "base damage": 50,
            "range": 60
        ]),
        ([
            "probability": 40,
            "base damage": 80,
            "range": 90
        ])
    }));

    addSpecification("damage type", "psionic");
    addSpecification("apply enfeebled", 1);
    addSpecification("apply slow", 1);
    addSpecification("duration", 45);

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
            "rate": 0.25
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.25
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.45
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.30
        ]),
    }));

    addSpecification("cooldown", 90);
    addSpecification("event handler", "mindPrisonEvent");
    addSpecification("command template", "mind prison [at ##Target##]");

    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::imprison## ##TargetName##'s consciousness within a "
        "labyrinth of their own deepest fears.");
}
