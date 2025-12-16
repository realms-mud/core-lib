//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Nightmare Fist");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of a technique that concentrates raw nightmare essence into "
        "a devastating psychic blow. It is a form that can either be done by "
        "itself or as part of a combination attack.");
    addSpecification("usage summary", "A concentrated nightmare-force "
        "psionic strike");

    addPrerequisite("/guilds/oneiromancer/psionic-focus/perception-warp.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 25
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("damage hit points", ({ ([
            "probability": 75,
            "base damage": 85,
            "range": 170
        ]),
        ([
            "probability": 25,
            "base damage": 170,
            "range": 340
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
            "rate": 1.10
        ]),
        ([
            "type": "research",
            "research item": "/guilds/oneiromancer/psionic-focus/existential-insight.c",
            "name": "Existential Insight",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "research",
            "research item": "/guilds/oneiromancer/psionic-focus/psychic-resonance.c",
            "name": "Psychic Resonance",
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
            "name": "strength",
            "formula": "additive",
            "rate": 0.25
        ]),
    }));

    addSpecification("spell point cost", 75);
    addSpecification("cooldown", 18);

    addSpecification("event handler", "nightmareFistEvent");
    addSpecification("command template", "nightmare fist [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::clench## ##InitiatorPossessive## fist, wreathing it "
        "in nightmare essence, and ##Infinitive::drive## the psychic blow "
        "into ##TargetName##'s mind.");
    addSpecification("use combination message", "##Infinitive::strike## "
        "with nightmare force");
}
