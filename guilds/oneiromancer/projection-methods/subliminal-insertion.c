//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Subliminal Insertion");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of inserting psionic attacks beneath the targets conscious "
        "awareness. The assault bypasses mental defenses by operating below "
        "the threshold of perception. It can only be used as part of a "
        "combination attack.");
    addSpecification("usage summary", "A delivery method that bypasses "
        "conscious defenses");

    addPrerequisite("/guilds/oneiromancer/projection-methods/psychic-touch.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 29
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 25);

    addSpecification("damage hit points", ({ ([
            "probability": 70,
            "base damage": 30,
            "range": 60
        ]),
        ([
            "probability": 30,
            "base damage": 60,
            "range": 120
        ])
    }));

    addSpecification("damage type", "psionic");

    addSpecification("modifiers", ({ 
        ([
            "type": "skill",
            "name": "mind",
            "formula": "additive",
            "rate": 0.25
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
    }));

    addSpecification("cooldown", 10);
    addSpecification("event handler", "subliminalInsertionEvent");

    addSpecification("use combination message", "##Infinitive::insert## "
        "the assault beneath ##TargetPossessive## awareness");
}
