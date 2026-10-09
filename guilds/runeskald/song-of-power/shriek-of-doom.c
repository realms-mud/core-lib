//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Shriek of Doom");
    addSpecification("source", "runeskald");
    addSpecification("description", "The runeskald releases a bone-rattling "
        "shriek that deals heavy spiritual damage to all nearby enemies "
        "and briefly weakens their defenses.");

    addPrerequisite("level",
        (["type": "level", "guild": "runeskald", "value": 12]));
    addPrerequisite("/guilds/runeskald/song-of-power/shriek-of-ruin.c",
        (["type": "research"]));
    addPrerequisite("/guilds/runeskald/song-of-power/wail-of-the-fallen.c",
        (["type": "research"]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 20);
    addSpecification("command template", "sing shriek of doom");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::unleash## a bone-rattling shriek of doom that tears through everything nearby.");

    addSpecification("spell point cost", 40);
    addSpecification("stamina point cost", 18);

    addSpecification("damage hit points", ({
        ([
            "probability": 65,
            "base damage": 70,
            "range": 80
        ]),
        ([
            "probability": 35,
            "base damage": 130,
            "range": 120
        ])
    }));

    addSpecification("modifiers", ({
        ([
            "type": "attribute",
            "name": "charisma",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "additive",
            "rate": 0.10
        ])
    }));
}
