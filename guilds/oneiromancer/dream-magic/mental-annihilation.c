//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Mental Annihilation");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of channeling overwhelming psionic force into a single "
        "devastating strike that can shatter a target's mind.");
    addSpecification("usage summary", "An extremely high-damage single-target "
        "attack");

    addPrerequisite("/guilds/oneiromancer/dream-magic/psychic-fortress.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 47
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 150);

    addSpecification("damage hit points", ({ ([
            "probability": 50,
            "base damage": 100,
            "range": 120
        ]),
        ([
            "probability": 35,
            "base damage": 150,
            "range": 180
        ]),
        ([
            "probability": 15,
            "base damage": 250,
            "range": 300
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
            "rate": 0.35
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.35
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.60
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.35
        ]),
    }));

    addSpecification("cooldown", 90);
    addSpecification("event handler", "mentalAnnihilationEvent");
    addSpecification("command template", "mental annihilation [at ##Target##]");

    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::focus## an overwhelming wave of psionic force at "
        "##TargetName##, seeking to utterly shatter ##TargetPossessive## mind.");
}
