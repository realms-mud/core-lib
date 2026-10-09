//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Curse of Ruin");
    addSpecification("source", "runeskald");
    addSpecification("description", "The runeskald hurls a cutting verse "
        "that strips away a target's confidence, dealing light spiritual "
        "damage and reducing their combat effectiveness.");

    addPrerequisite("level",
        (["type": "level", "guild": "runeskald", "value": 3]));
    addPrerequisite("/guilds/runeskald/song-of-power/wounding-verse.c",
        (["type": "research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 12);
    addSpecification("command template", "sing curse of ruin ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::hurl## a biting verse of ruin at ##TargetName##, stripping their courage.");

    addSpecification("spell point cost", 18);
    addSpecification("stamina point cost", 8);

    addSpecification("damage hit points", ({
        ([
            "probability": 80,
            "base damage": 18,
            "range": 20
        ]),
        ([
            "probability": 20,
            "base damage": 36,
            "range": 30
        ])
    }));

    addSpecification("penalty to attack", 2);
    addSpecification("penalty to defense", 2);

    addSpecification("modifiers", ({
        ([
            "type": "attribute",
            "name": "charisma",
            "formula": "additive",
            "rate": 0.05
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "additive",
            "rate": 0.05
        ])
    }));
}
