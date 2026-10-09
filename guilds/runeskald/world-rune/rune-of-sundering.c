//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Rune of Sundering");
    addSpecification("source", "runeskald");
    addSpecification("description", "The runeskald speaks a world rune of "
        "sundering that splits the air and strikes all enemies in range "
        "with primordial force.");

    addPrerequisite("/guilds/runeskald/world-rune/rune-of-unmaking.c",
        (["type": "research"]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 12);
    addSpecification("command template", "invoke rune of sundering");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::speak## a rune of sundering and the air fractures outward in a shockwave.");

    addSpecification("spell point cost", 70);
    addSpecification("stamina point cost", 20);

    addSpecification("damage hit points", ({
        ([
            "probability": 70,
            "base damage": 30,
            "range": 30
        ]),
        ([
            "probability": 30,
            "base damage": 60,
            "range": 40
        ])
    }));

    addSpecification("modifiers", ({
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.08
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "additive",
            "rate": 0.09
        ])
    }));
    addSpecification("consumables", (["basic power rune": 1]));
}
