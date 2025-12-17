//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Collective Resonance");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of projecting psionic attacks through the collective "
        "unconscious. The assault echoes through shared mental space, "
        "amplifying its effect. It can only be used as part of a "
        "combination attack.");
    addSpecification("usage summary", "A delivery method using the "
        "collective unconscious");

    addPrerequisite("/guilds/oneiromancer/projection-methods/thoughtform-projection.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 37
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 35);

    addSpecification("damage hit points", ({ ([
            "probability": 70,
            "base damage": 40,
            "range": 80
        ]),
        ([
            "probability": 30,
            "base damage": 80,
            "range": 160
        ])
    }));

    addSpecification("damage type", "psionic");

    addSpecification("modifiers", ({ 
        ([
            "type": "skill",
            "name": "mind",
            "formula": "additive",
            "rate": 0.30
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
            "rate": 0.50
        ]),
        ([
            "type":"attribute",
            "name": "charisma",
            "formula": "additive",
            "rate": 0.25
        ]),
    }));

    addSpecification("cooldown", 14);
    addSpecification("event handler", "collectiveResonanceEvent");

    addSpecification("use combination message", "##Infinitive::channel## "
        "through the collective unconscious");
}
