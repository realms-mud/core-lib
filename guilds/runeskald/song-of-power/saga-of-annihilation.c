//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Saga of Annihilation");
    addSpecification("source", "runeskald");
    addSpecification("description", "The runeskald sings the saga of "
        "annihilation, a devastating spiritual attack that strikes all "
        "nearby enemies with crushing force.");

    addPrerequisite("level",
        (["type": "level", "guild": "runeskald", "value": 18]));
    addPrerequisite("/guilds/runeskald/song-of-power/anguished-wail.c",
        (["type": "research"]));
    addPrerequisite("/guilds/runeskald/song-of-power/echo-of-doom.c",
        (["type": "research"]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 40);
    addSpecification("command template", "sing saga of annihilation");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::sing## the saga of annihilation, voice cracking like thunder across the battlefield.");

    addSpecification("spell point cost", 55);
    addSpecification("stamina point cost", 25);

    addSpecification("damage hit points", ({
        ([
            "probability": 65,
            "base damage": 100,
            "range": 110
        ]),
        ([
            "probability": 35,
            "base damage": 175,
            "range": 175
        ])
    }));

    addSpecification("modifiers", ({
        ([
            "type": "skill",
            "name": "singing",
            "formula": "additive",
            "rate": 0.16
        ]),
        ([
            "type": "attribute",
            "name": "charisma",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "research",
            "research item": "/guilds/runeskald/song-of-power/dirge-of-ruin.c",
            "name": "Dirge of Ruin",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ])
    }));
}
