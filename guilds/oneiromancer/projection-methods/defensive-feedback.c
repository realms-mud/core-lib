//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Defensive Feedback");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of creating a feedback loop that heals the caster when "
        "their attack connects. It can only be used as part of a combination "
        "attack.");
    addSpecification("usage summary", "A tactical modifier that heals "
        "the caster on hit");

    addPrerequisite("/guilds/oneiromancer/projection-methods/cascading-horror.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 53
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("damage hit points", ({ ([
            "probability": 80,
            "base damage": 40,
            "range": 80
        ]),
        ([
            "probability": 20,
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
            "rate": 0.20
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
            "rate": 0.25
        ]),
        ([
            "type":"attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.50
        ]),
    }));

    addSpecification("cooldown", 18);
    addSpecification("event handler", "defensiveFeedbackEvent");

    addSpecification("use combination message", "##Infinitive::establish## "
        "a healing feedback loop");
}
