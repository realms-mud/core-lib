//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Voice of Ruin");
    addSpecification("source", "runeskald");
    addSpecification("description", "The runeskald channels pure destructive "
        "song into a single searing strike of sonic and spiritual energy "
        "against one target.");

    addPrerequisite("level",
        (["type": "level", "guild": "runeskald", "value": 15]));
    addPrerequisite("/guilds/runeskald/song-of-power/echo-of-doom.c",
        (["type": "research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 20);
    addSpecification("command template", "sing voice of ruin ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::direct## a lance of pure ruinous song at ##TargetName##.");

    addSpecification("spell point cost", 42);
    addSpecification("stamina point cost", 18);

    addSpecification("damage hit points", ({
        ([
            "probability": 60,
            "base damage": 90,
            "range": 100
        ]),
        ([
            "probability": 40,
            "base damage": 160,
            "range": 150
        ])
    }));

    addSpecification("modifiers", ({
        ([
            "type": "attribute",
            "name": "charisma",
            "formula": "additive",
            "rate": 0.12
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "additive",
            "rate": 0.12
        ])
    }));
}
