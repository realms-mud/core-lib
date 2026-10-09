//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Saga of the Fallen");
    addSpecification("source", "runeskald");
    addSpecification("description", "The runeskald sings a brief but powerful "
        "saga of a fallen hero, invoking spiritual damage against a single "
        "foe.");

    addPrerequisite("level",
        (["type": "level", "guild": "runeskald", "value": 5]));
    addPrerequisite("/guilds/runeskald/song-of-power/battle-saga.c",
        (["type": "research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 12);
    addSpecification("command template", "sing saga of the fallen ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::sing## the saga of the fallen, invoking the weight of countless deaths on ##TargetName##.");

    addSpecification("spell point cost", 25);
    addSpecification("stamina point cost", 10);

    addSpecification("damage hit points", ({
        ([
            "probability": 75,
            "base damage": 30,
            "range": 35
        ]),
        ([
            "probability": 25,
            "base damage": 55,
            "range": 55
        ])
    }));

    addSpecification("modifiers", ({
        ([
            "type": "skill",
            "name": "singing",
            "formula": "additive",
            "rate": 0.09
        ]),
        ([
            "type": "attribute",
            "name": "charisma",
            "formula": "additive",
            "rate": 0.06
        ]),
        ([
            "type": "research",
            "research item": "/guilds/runeskald/song-of-power/battle-saga.c",
            "name": "Battle Saga",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.10
        ])
    }));
}
