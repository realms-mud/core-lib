//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Mind Annihilation");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of a devastating technique that attempts to completely "
        "obliterate the target's consciousness. It is a form that can either "
        "be done by itself or as part of a combination attack.");
    addSpecification("usage summary", "A devastating high-damage "
        "psionic assault");

    addPrerequisite("/guilds/oneiromancer/psionic-focus/psychic-scream.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 31
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("damage hit points", ({ ([
            "probability": 70,
            "base damage": 100,
            "range": 200
        ]),
        ([
            "probability": 30,
            "base damage": 200,
            "range": 400
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
            "rate": 1.10
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
            "type": "research",
            "research item": "/guilds/oneiromancer/psionic-focus/void-mastery.c",
            "name": "Void Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "skill",
            "name": "mind",
            "formula": "logarithmic",
            "rate": 1.15
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.10
        ]),
        ([
            "type": "skill",
            "name": "senses",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type":"attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.75
        ]), 
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.75
        ]),
    }));

    addSpecification("spell point cost", 125);
    addSpecification("cooldown", 45);

    addSpecification("event handler", "mindAnnihilationEvent");
    addSpecification("command template", "mind annihilation [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::focus## the entirety of ##InitiatorPossessive## "
        "psychic might, attempting to annihilate ##TargetName##'s "
        "consciousness utterly.");
    addSpecification("use combination message", "##Infinitive::annihilate## "
        "the mind");
}
