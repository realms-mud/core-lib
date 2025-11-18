//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Spiritual Mastery");
    addSpecification("source", "background");
    addSpecification("description", "You channel pure spiritual energy, "
        "achieving complete restoration of mind, body, and spirit.");

    addPrerequisite("/guilds/background/paths/devoted/spiritual-clarity.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("stamina point cost", 35);

    addSpecification("increase spell points", ({
        ([
            "probability": 100,
            "base damage": 50,
            "range": 30
        ])
    }));

    addSpecification("increase stamina points", ({
        ([
            "probability": 100,
            "base damage": 30,
            "range": 20
        ])
    }));

    addSpecification("increase hit points", ({
        ([
            "probability": 100,
            "base damage": 20,
            "range": 15
        ])
    }));

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/background/paths/devoted/divine-vessel.c",
            "name": "Divine Vessel",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 1.0
        ]),
        ([
            "type": "skill",
            "name": "theology",
            "formula": "additive",
            "rate": 0.50
        ]),
        ([
            "type": "skill",
            "name": "philosophy",
            "formula": "additive",
            "rate": 0.25
        ])
    }));

    addSpecification("cooldown", 200);
    addSpecification("event handler", "spiritualMasteryEvent");
    addSpecification("command template", "spiritual mastery");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::channel## pure spiritual energy, achieving "
        "complete restoration.");
}
