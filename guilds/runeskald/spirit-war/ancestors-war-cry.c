//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Ancestor's War Cry");
    addSpecification("source", "runeskald");
    addSpecification("description", "The runeskald releases the voice of an "
        "ancestral warrior spirit in a terrifying war cry, dealing spirit "
        "damage to all enemies in the vicinity.");

    addPrerequisite("/guilds/runeskald/spirit-war/spirit-weapon-strike.c",
        (["type": "research"]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 12);
    addSpecification("command template", "invoke ancestors war cry");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::unleash## an ancestral war cry that echoes with spirit-thunder.");

    addSpecification("spell point cost", 50);
    addSpecification("stamina point cost", 15);

    addSpecification("damage hit points", ({
        ([
            "probability": 80,
            "base damage": 20,
            "range": 20
        ]),
        ([
            "probability": 20,
            "base damage": 45,
            "range": 30
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
            "rate": 0.07
        ])
    }));
    addSpecification("consumables", (["basic ward rune": 1]));
}
