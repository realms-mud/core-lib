//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Spirit Storm");
    addSpecification("source", "runeskald");
    addSpecification("description", "The runeskald releases both warrior and "
        "guardian spirits outward in a chaotic storm of ancestral energy, "
        "dealing heavy damage to all enemies nearby.");

    addPrerequisite("/guilds/runeskald/spirit-war/ancestors-war-cry.c",
        (["type": "research"]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 12);
    addSpecification("command template", "invoke spirit storm");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::release## both spirits in a howling storm of ancestral fury.");

    addSpecification("spell point cost", 65);
    addSpecification("stamina point cost", 20);

    addSpecification("damage hit points", ({
        ([
            "probability": 65,
            "base damage": 28,
            "range": 28
        ]),
        ([
            "probability": 35,
            "base damage": 55,
            "range": 38
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
            "rate": 0.08
        ])
    }));
    addSpecification("consumables", (["basic ward rune": 1]));
}
