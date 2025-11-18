//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Shared Burden");
    addSpecification("source", "background");
    addSpecification("description", "You reach out and touch an ally, "
        "channeling some of their pain into yourself.");

    addPrerequisite("/guilds/background/paths/compassionate/healers-instinct.c",
        (["type":"research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("stamina point cost", 15);
    addSpecification("hit point cost", 10);

    addSpecification("increase hit points", ({
        ([
            "probability": 100,
            "base damage": 20,
            "range": 10
        ])
    }));

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/background/paths/compassionate/merciful-soul.c",
            "name": "Merciful Soul",
            "formula": "additive",
            "base value": 1,
            "rate": 3.0
        ]),
        ([
            "type": "research",
            "research item": "/guilds/background/paths/compassionate/selfless-devotion.c",
            "name": "Selfless Devotion",
            "formula": "additive",
            "base value": 1,
            "rate": 5.0
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.25
        ]),
        ([
            "type": "skill",
            "name": "anatomy and physiology",
            "formula": "additive",
            "rate": 0.10
        ])
    }));

    addSpecification("cooldown", 90);
    addSpecification("event handler", "sharedBurdenEvent");
    addSpecification("command template", "share burden with ##Target##");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::touch## ##TargetName##, taking on some of their pain.");
}
