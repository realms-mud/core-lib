//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Shriek of Ruin");
    addSpecification("source", "runeskald");
    addSpecification("description", "The runeskald unleashes a terrible "
        "shriek charged with runic power, dealing heavy spiritual damage "
        "to a single enemy.");

    addPrerequisite("level",
        (["type": "level", "guild": "runeskald", "value": 7]));
    addPrerequisite("/guilds/runeskald/song-of-power/curse-of-weakness.c",
        (["type": "research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 20);
    addSpecification("command template", "shriek of ruin ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::unleash## a terrible runic shriek at ##TargetName##.");

    addSpecification("spell point cost", 28);
    addSpecification("stamina point cost", 10);

    addSpecification("damage hit points", ({
        ([
            "probability": 70,
            "base damage": 40,
            "range": 45
        ]),
        ([
            "probability": 30,
            "base damage": 75,
            "range": 70
        ])
    }));

    addSpecification("modifiers", ({
        ([
            "type": "skill",
            "name": "singing",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "attribute",
            "name": "charisma",
            "formula": "additive",
            "rate": 0.07
        ]),
        ([
            "type": "research",
            "research item": "/guilds/runeskald/song-of-power/dirge-of-ruin.c",
            "name": "Dirge of Ruin",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ])
    }));
}
