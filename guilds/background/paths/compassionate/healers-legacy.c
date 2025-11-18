//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Healer's Legacy");
    addSpecification("source", "background");
    addSpecification("description", "You channel a tremendous amount of your "
        "life force to restore an ally from even the brink of death.");

    addPrerequisite("/guilds/background/paths/compassionate/beacon-of-hope.c",
        (["type":"research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("stamina point cost", 30);
    addSpecification("hit point cost", 25);

    addSpecification("increase hit points", ({
        ([
            "probability": 100,
            "base damage": 50,
            "range": 25
        ])
    }));

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/background/paths/compassionate/saint.c",
            "name": "Saint",
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
            "type": "attribute",
            "name": "constitution",
            "formula": "additive",
            "rate": 0.50
        ]),
        ([
            "type": "skill",
            "name": "anatomy and physiology",
            "formula": "additive",
            "rate": 0.50
        ])
    }));

    addSpecification("cooldown", 180);
    addSpecification("event handler", "healersLegacyEvent");
    addSpecification("command template", "healer's legacy on ##Target##");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::place## both hands on ##TargetName##, channeling "
        "an immense surge of healing energy.");
}
