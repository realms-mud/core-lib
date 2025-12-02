//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Life Ward");
    addSpecification("source", "background");
    addSpecification("description", "You channel your own life force to "
        "mend the wounds of an ally.");

    addPrerequisite("/guilds/background/paths/compassionate/nurturer.c",
        (["type":"research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("stamina point cost", 20);
    addSpecification("hit point cost", 15);

    addSpecification("increase hit points", ({
        ([
            "probability": 100,
            "base damage": 30,
            "range": 15
        ])
    }));

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/background/paths/compassionate/beacon-of-hope.c",
            "name": "Beacon of Hope",
            "formula": "additive",
            "base value": 1,
            "rate": 5.0
        ]),
        ([
            "type": "research",
            "research item": "/guilds/background/paths/compassionate/martyrs-resolve.c",
            "name": "Martyr's Resolve",
            "formula": "additive",
            "base value": 1,
            "rate": 5.0
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.50
        ]),
        ([
            "type": "skill",
            "name": "anatomy and physiology",
            "formula": "additive",
            "rate": 0.25
        ]),
        ([
            "type": "skill",
            "name": "herbalism",
            "formula": "additive",
            "rate": 0.10
        ])
    }));

    addSpecification("cooldown", 120);
    addSpecification("event handler", "lifeWardEvent");
    addSpecification("command template", "life ward ##Target##");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::channel## life energy to heal ##TargetName##.");
}
