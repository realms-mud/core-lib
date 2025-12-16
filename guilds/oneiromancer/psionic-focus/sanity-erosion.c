//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Sanity Erosion");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of a technique that gradually erodes the target's grip on "
        "reality, wearing away their mental stability grain by grain. "
        "It is a form that can either be done by itself or as part of a "
        "combination attack.");
    addSpecification("usage summary", "A psionic attack that erodes "
        "mental stability");

    addPrerequisite("/guilds/oneiromancer/psionic-focus/cognitive-fracture.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 19
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("damage hit points", ({ ([
            "probability": 80,
            "base damage": 65,
            "range": 130
        ]),
        ([
            "probability": 20,
            "base damage": 130,
            "range": 260
        ])
    }));

    addSpecification("damage type", "psionic");

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/oneiromancer/psionic-focus/nightmare-affinity.c",
            "name": "Nightmare Affinity",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item": "/guilds/oneiromancer/psionic-focus/cognitive-mastery.c",
            "name": "Cognitive Mastery",
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
    }));

    addSpecification("spell point cost", 55);
    addSpecification("cooldown", 14);

    addSpecification("event handler", "sanityErosionEvent");
    addSpecification("command template", "sanity erosion [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::whisper## impossible truths that ##Infinitive::erode## "
        "the foundations of ##TargetName##'s sanity.");
    addSpecification("use combination message", "##Infinitive::erode## "
        "sanity's foundations");
}
