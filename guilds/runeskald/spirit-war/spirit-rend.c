//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Spirit Rend");
    addSpecification("source", "runeskald");
    addSpecification("description", "The runeskald drives a warrior spirit "
        "directly through a foe's defenses, bypassing armor to deal "
        "raw spirit damage.");

    addPrerequisite("/guilds/runeskald/spirit-war/spirit-weapon-strike.c",
        (["type": "research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 12);
    addSpecification("command template", "invoke spirit rend ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::drive## a warrior spirit through ##TargetName##'s defenses.");

    addSpecification("spell point cost", 35);
    addSpecification("stamina point cost", 12);

    addSpecification("damage hit points", ({
        ([
            "probability": 70,
            "base damage": 22,
            "range": 22
        ]),
        ([
            "probability": 30,
            "base damage": 45,
            "range": 32
        ])
    }));

    addSpecification("modifiers", ({
        ([
            "type": "attribute",
            "name": "strength",
            "formula": "additive",
            "rate": 0.06
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "additive",
            "rate": 0.06
        ])
    }));
    addSpecification("consumables", (["basic ward rune": 1]));
}
