//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Absolute Conviction");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of projecting psionic attacks with absolute conviction. "
        "The unwavering certainty of the assault makes it nearly impossible "
        "to resist. It can only be used as part of a combination attack.");
    addSpecification("usage summary", "The ultimate intensity modifier "
        "with unwavering force");

    addPrerequisite("/guilds/oneiromancer/projection-methods/perfect-clarity.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 51
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 50);

    addSpecification("damage hit points", ({ ([
            "probability": 70,
            "base damage": 70,
            "range": 140
        ]),
        ([
            "probability": 30,
            "base damage": 140,
            "range": 280
        ])
    }));

    addSpecification("damage type", "psionic");

    addSpecification("modifiers", ({ 
        ([
            "type": "skill",
            "name": "mind",
            "formula": "additive",
            "rate": 0.40
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
            "rate": 0.30
        ]),
    }));

    addSpecification("cooldown", 18);
    addSpecification("event handler", "absoluteConvictionEvent");

    addSpecification("use combination message", "##Infinitive::strike## "
        "with absolute conviction");
}
