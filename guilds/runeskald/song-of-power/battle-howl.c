//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Battle Howl");
    addSpecification("source", "runeskald");
    addSpecification("description", "The runeskald releases a terrifying "
        "battle howl, striking all nearby enemies with spiritual damage "
        "and shattering morale.");

    addPrerequisite("level",
        (["type": "level", "guild": "runeskald", "value": 8]));
    addPrerequisite("/guilds/runeskald/song-of-power/verse-of-doom.c",
        (["type": "research"]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 20);
    addSpecification("command template", "battle howl");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::unleash## a terrifying battle howl that shakes all nearby foes.");

    addSpecification("spell point cost", 32);
    addSpecification("stamina point cost", 15);

    addSpecification("damage hit points", ({
        ([
            "probability": 75,
            "base damage": 32,
            "range": 35
        ]),
        ([
            "probability": 25,
            "base damage": 60,
            "range": 60
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
