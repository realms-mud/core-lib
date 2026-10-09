//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Wounding Verse");
    addSpecification("source", "runeskald");
    addSpecification("description", "The runeskald sings a biting verse that "
        "tears at the target's morale and wounds their spirit, dealing "
        "moderate psychic damage.");

    addPrerequisite("level",
        (["type": "level", "guild": "runeskald", "value": 1]));
    addPrerequisite("/guilds/runeskald/song-of-power/root.c",
        (["type": "research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 12);
    addSpecification("command template", "sing wounding verse ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::sing## a biting verse that tears at ##TargetName##'s spirit.");

    addSpecification("spell point cost", 15);
    addSpecification("stamina point cost", 5);

    addSpecification("damage hit points", ({
        ([
            "probability": 80,
            "base damage": 16,
            "range": 18
        ]),
        ([
            "probability": 20,
            "base damage": 30,
            "range": 28
        ])
    }));

    addSpecification("modifiers", ({
        ([
            "type": "skill",
            "name": "singing",
            "formula": "additive",
            "rate": 0.07
        ]),
        ([
            "type": "attribute",
            "name": "charisma",
            "formula": "additive",
            "rate": 0.05
        ])
    }));
}
