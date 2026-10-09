//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Verse of Doom");
    addSpecification("source", "runeskald");
    addSpecification("description", "The runeskald unleashes the verse of "
        "doom, a powerful prophetic declaration that strikes multiple "
        "nearby enemies with spiritual dread.");

    addPrerequisite("level",
        (["type": "level", "guild": "runeskald", "value": 6]));
    addPrerequisite("/guilds/runeskald/song-of-power/dirge-of-ruin.c",
        (["type": "research"]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 20);
    addSpecification("command template", "sing verse of doom");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::proclaim## the verse of doom, voice thundering with dark prophetic power.");

    addSpecification("spell point cost", 30);
    addSpecification("stamina point cost", 12);

    addSpecification("damage hit points", ({
        ([
            "probability": 75,
            "base damage": 28,
            "range": 30
        ]),
        ([
            "probability": 25,
            "base damage": 52,
            "range": 50
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
            "research item": "/guilds/runeskald/song-of-power/dirge-of-ruin.c",
            "name": "Dirge of Ruin",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.10
        ])
    }));
}
