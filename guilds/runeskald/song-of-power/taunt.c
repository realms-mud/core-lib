//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Taunt");
    addSpecification("source", "runeskald");
    addSpecification("description", "The runeskald shouts a mocking taunt "
        "at a foe, drawing their attention and lowering their combat "
        "effectiveness.");

    addPrerequisite("level",
        (["type": "level", "guild": "runeskald", "value": 2]));
    addPrerequisite("/guilds/runeskald/song-of-power/dirge-of-ruin.c",
        (["type": "research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 12);
    addSpecification("command template", "taunt ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::hurl## a blistering taunt at ##TargetName##, rattling their confidence.");

    addSpecification("spell point cost", 10);
    addSpecification("stamina point cost", 5);

    addSpecification("damage hit points", ({
        ([
            "probability": 80,
            "base damage": 10,
            "range": 12
        ]),
        ([
            "probability": 20,
            "base damage": 20,
            "range": 18
        ])
    }));

    addSpecification("modifiers", ({
        ([
            "type": "skill",
            "name": "singing",
            "formula": "additive",
            "rate": 0.05
        ]),
        ([
            "type": "attribute",
            "name": "charisma",
            "formula": "additive",
            "rate": 0.04
        ])
    }));
}
