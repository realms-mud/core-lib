//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Spirit Weapon Strike");
    addSpecification("source", "runeskald");
    addSpecification("description", "The runeskald channels a warrior spirit "
        "through their weapon in a single devastating blow, dealing bonus "
        "spirit damage on top of the normal weapon strike.");

    addPrerequisite("/guilds/runeskald/spirit-war/call-warrior-spirit.c",
        (["type": "research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 12);
    addSpecification("command template", "invoke spirit weapon strike ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::drive## a spirit-channeled strike into ##TargetName##.");

    addSpecification("spell point cost", 30);
    addSpecification("stamina point cost", 12);

    addSpecification("damage hit points", ({
        ([
            "probability": 70,
            "base damage": 28,
            "range": 28
        ]),
        ([
            "probability": 30,
            "base damage": 55,
            "range": 40
        ])
    }));

    addSpecification("modifiers", ({
        ([
            "type": "attribute",
            "name": "strength",
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
    addSpecification("consumables", (["basic ward rune": 1]));
}
