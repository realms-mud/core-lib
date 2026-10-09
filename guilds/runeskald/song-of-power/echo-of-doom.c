//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Echo of Doom");
    addSpecification("source", "runeskald");
    addSpecification("description", "The runeskald sings the echo of doom, "
        "a resonating curse that deals heavy spiritual damage to a single "
        "target.");

    addPrerequisite("level",
        (["type": "level", "guild": "runeskald", "value": 14]));
    addPrerequisite("/guilds/runeskald/song-of-power/shriek-of-ruin.c",
        (["type": "research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 20);
    addSpecification("command template", "sing echo of doom ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::sing## the echo of doom, a resonating pronouncement of final destruction aimed at ##TargetName##.");

    addSpecification("spell point cost", 40);
    addSpecification("stamina point cost", 15);

    addSpecification("damage hit points", ({
        ([
            "probability": 65,
            "base damage": 80,
            "range": 90
        ]),
        ([
            "probability": 35,
            "base damage": 140,
            "range": 140
        ])
    }));

    addSpecification("modifiers", ({
        ([
            "type": "skill",
            "name": "singing",
            "formula": "additive",
            "rate": 0.13
        ]),
        ([
            "type": "attribute",
            "name": "charisma",
            "formula": "additive",
            "rate": 0.09
        ]),
        ([
            "type": "research",
            "research item": "/guilds/runeskald/song-of-power/dirge-of-ruin.c",
            "name": "Dirge of Ruin",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ])
    }));
}
