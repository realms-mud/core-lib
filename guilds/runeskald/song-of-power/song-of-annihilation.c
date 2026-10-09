//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Song of Annihilation");
    addSpecification("source", "runeskald");
    addSpecification("description", "The runeskald bellows a song of pure "
        "annihilating power, dealing catastrophic spiritual damage to all "
        "nearby enemies.");

    addPrerequisite("level",
        (["type": "level", "guild": "runeskald", "value": 19]));
    addPrerequisite("/guilds/runeskald/song-of-power/saga-of-annihilation.c",
        (["type": "research"]));
    addPrerequisite("/guilds/runeskald/song-of-power/voice-of-ruin.c",
        (["type": "research"]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 40);
    addSpecification("command template", "sing song of annihilation");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::bellow## a song of pure annihilation that tears through the entire area.");

    addSpecification("spell point cost", 58);
    addSpecification("stamina point cost", 25);

    addSpecification("damage hit points", ({
        ([
            "probability": 60,
            "base damage": 120,
            "range": 130
        ]),
        ([
            "probability": 40,
            "base damage": 220,
            "range": 200
        ])
    }));

    addSpecification("modifiers", ({
        ([
            "type": "attribute",
            "name": "charisma",
            "formula": "additive",
            "rate": 0.14
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "additive",
            "rate": 0.14
        ])
    }));
}
