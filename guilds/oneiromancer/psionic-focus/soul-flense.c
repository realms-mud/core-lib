//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Soul Flense");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of a technique that strips away psychic defenses, flensing "
        "the target's soul of its protective barriers. It is a form that can "
        "either be done by itself or as part of a combination attack.");
    addSpecification("usage summary", "A psionic attack that strips "
        "mental defenses");

    addPrerequisite("/guilds/oneiromancer/psionic-focus/nightmare-fist.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 29
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("damage hit points", ({ ([
            "probability": 80,
            "base damage": 90,
            "range": 180
        ]),
        ([
            "probability": 20,
            "base damage": 180,
            "range": 360
        ])
    }));

    addSpecification("damage type", "psionic");

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/oneiromancer/psionic-focus/psychic-resonance.c",
            "name": "Psychic Resonance",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "research",
            "research item": "/guilds/oneiromancer/psionic-focus/annihilating-will.c",
            "name": "Annihilating Will",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
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

    addSpecification("spell point cost", 85);
    addSpecification("cooldown", 20);

    addSpecification("event handler", "soulFlenseEvent");
    addSpecification("command template", "soul flense [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::make## a peeling gesture, stripping away layers of "
        "##TargetName##'s psychic defenses like skin from flesh.");
    addSpecification("use combination message", "##Infinitive::flense## "
        "the soul's defenses");
}
