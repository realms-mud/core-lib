//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Verse of Agony");
    addSpecification("source", "runeskald");
    addSpecification("description", "The runeskald sings a verse of pure "
        "sonic agony that deals spiritual damage to a single target and "
        "briefly disrupts their concentration.");

    addPrerequisite("level",
        (["type": "level", "guild": "runeskald", "value": 6]));
    addPrerequisite("/guilds/runeskald/song-of-power/verse-of-doom.c",
        (["type": "research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 20);
    addSpecification("command template", "sing verse of agony ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::sing## a verse of pure agony that tears through ##TargetName##'s focus.");

    addSpecification("spell point cost", 25);
    addSpecification("stamina point cost", 10);

    addSpecification("damage hit points", ({
        ([
            "probability": 75,
            "base damage": 35,
            "range": 38
        ]),
        ([
            "probability": 25,
            "base damage": 68,
            "range": 62
        ])
    }));

    addSpecification("modifiers", ({
        ([
            "type": "attribute",
            "name": "charisma",
            "formula": "additive",
            "rate": 0.07
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "additive",
            "rate": 0.07
        ])
    }));
}
