//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Psychic Scream");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of a technique that unleashes a devastating mental scream "
        "affecting all enemies in the area. It is a form that can either be "
        "done by itself or as part of a combination attack.");
    addSpecification("usage summary", "An area-effect psionic assault");

    addPrerequisite("/guilds/oneiromancer/psionic-focus/existential-dread.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 27
        ]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("damage hit points", ({ ([
            "probability": 80,
            "base damage": 70,
            "range": 140
        ]),
        ([
            "probability": 20,
            "base damage": 140,
            "range": 280
        ])
    }));

    addSpecification("damage type", "psionic");

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/oneiromancer/psionic-focus/existential-insight.c",
            "name": "Existential Insight",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item": "/guilds/oneiromancer/psionic-focus/psychic-resonance.c",
            "name": "Psychic Resonance",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/oneiromancer/psionic-focus/void-mastery.c",
            "name": "Void Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "skill",
            "name": "mind",
            "formula": "logarithmic",
            "rate": 1.10
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.05
        ]),
        ([
            "type": "skill",
            "name": "senses",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type":"attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.5
        ]), 
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.5
        ]),
        ([
            "type": "attribute",
            "name": "charisma",
            "formula": "additive",
            "rate": 0.25
        ]),
    }));

    addSpecification("spell point cost", 100);
    addSpecification("cooldown", 60);

    addSpecification("event handler", "psychicScreamEvent");
    addSpecification("command template", "psychic scream");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::throw## back ##InitiatorPossessive## head and "
        "##Infinitive::unleash## a devastating psychic scream that tears "
        "through the minds of all nearby enemies.");
    addSpecification("use combination message", "##Infinitive::scream## "
        "psychically");
}
