//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Curse of Weakness");
    addSpecification("source", "runeskald");
    addSpecification("description", "The runeskald sings a verse that saps "
        "the strength from a foe, dealing spiritual damage and briefly "
        "weakening their blows.");

    addPrerequisite("level",
        (["type": "level", "guild": "runeskald", "value": 4]));
    addPrerequisite("/guilds/runeskald/song-of-power/dirge-of-ruin.c",
        (["type": "research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 12);
    addSpecification("command template", "sing curse of weakness ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::sing## a draining verse that saps the strength from ##TargetName##.");

    addSpecification("spell point cost", 22);
    addSpecification("stamina point cost", 8);

    addSpecification("damage hit points", ({
        ([
            "probability": 75,
            "base damage": 20,
            "range": 22
        ]),
        ([
            "probability": 25,
            "base damage": 38,
            "range": 35
        ])
    }));

    addSpecification("modifiers", ({
        ([
            "type": "skill",
            "name": "singing",
            "formula": "additive",
            "rate": 0.08
        ]),
        ([
            "type": "attribute",
            "name": "charisma",
            "formula": "additive",
            "rate": 0.05
        ])
    }));
}
