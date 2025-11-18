//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Spiritual Clarity");
    addSpecification("source", "background");
    addSpecification("description", "You achieve a moment of perfect clarity, "
        "restoring both your mental and physical vitality.");

    addPrerequisite("/guilds/background/paths/devoted/root.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("stamina point cost", 20);

    addSpecification("increase spell points", ({
        ([
            "probability": 100,
            "base damage": 25,
            "range": 15
        ])
    }));

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/background/paths/devoted/divine-purpose.c",
            "name": "Divine Purpose",
            "formula": "additive",
            "base value": 1,
            "rate": 5.0
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.75
        ]),
        ([
            "type": "skill",
            "name": "theology",
            "formula": "additive",
            "rate": 0.25
        ])
    }));

    addSpecification("cooldown", 150);
    addSpecification("event handler", "spiritualClarityEvent");
    addSpecification("command template", "spiritual clarity");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::achieve## a moment of perfect spiritual clarity.");
}
