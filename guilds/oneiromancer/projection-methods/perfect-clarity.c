//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Perfect Clarity");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of achieving perfect mental clarity when projecting "
        "psionic attacks. This crystalline focus dramatically increases "
        "precision and damage. It can only be used as part of a "
        "combination attack.");
    addSpecification("usage summary", "An intensity modifier providing "
        "crystalline mental focus");

    addPrerequisite("/guilds/oneiromancer/projection-methods/overwhelming-presence.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 43
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 40);

    addSpecification("damage hit points", ({ ([
            "probability": 70,
            "base damage": 55,
            "range": 110
        ]),
        ([
            "probability": 30,
            "base damage": 110,
            "range": 220
        ])
    }));

    addSpecification("damage type", "psionic");

    addSpecification("modifiers", ({ 
        ([
            "type": "skill",
            "name": "mind",
            "formula": "additive",
            "rate": 0.35
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
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.25
        ]),
    }));

    addSpecification("cooldown", 16);
    addSpecification("event handler", "perfectClarityEvent");

    addSpecification("use combination message", "##Infinitive::focus## "
        "with perfect clarity");
}
