//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Death of Self");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of inflicting the nightmare of experiencing one's own death - "
        "the final breath, the fading light, the cold embrace of oblivion. "
        "The brush with mortality manifests as undead damage. It can be used "
        "alone or as part of a combination attack.");
    addSpecification("usage summary", "Nightmare imagery of death that "
        "adds undead damage");

    addPrerequisite("/guilds/oneiromancer/dream-imagery/frozen-wasteland.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 55
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("damage hit points", ({ ([
            "probability": 75,
            "base damage": 110,
            "range": 220
        ]),
        ([
            "probability": 25,
            "base damage": 220,
            "range": 440
        ])
    }));

    addSpecification("damage type", "undead");

    addSpecification("modifiers", ({ 
        ([
            "type": "skill",
            "name": "mind",
            "formula": "logarithmic",
            "rate": 1.15
        ]),
        ([
            "type": "skill",
            "name": "evocation",
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

    addSpecification("spell point cost", 100);
    addSpecification("cooldown", 25);

    addSpecification("event handler", "deathOfSelfEvent");
    addSpecification("command template", "death of self [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::force## ##TargetName## to experience the nightmare "
        "of ##TargetPossessive## own death, the touch of mortality searing "
        "##TargetPossessive## soul.");
    addSpecification("use combination message", "##Infinitive::invoke## "
        "the death of self");
}
