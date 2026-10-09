//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "World Rune Torrent");
    addSpecification("source", "runeskald");
    addSpecification("description", "The runeskald speaks a torrent of world "
        "runes in rapid succession, hammering all enemies in range with "
        "wave after wave of primordial force.");

    addPrerequisite("/guilds/runeskald/world-rune/world-rune-devastation.c",
        (["type": "research"]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 12);
    addSpecification("command template", "invoke world rune torrent");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::speak## a torrent of world runes, filling the air with shattering primordial force.");

    addSpecification("spell point cost", 100);
    addSpecification("stamina point cost", 35);

    addSpecification("damage hit points", ({
        ([
            "probability": 60,
            "base damage": 45,
            "range": 40
        ]),
        ([
            "probability": 40,
            "base damage": 85,
            "range": 55
        ])
    }));

    addSpecification("modifiers", ({
        ([
            "type": "attribute",
            "name": "intelligence",
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
    addSpecification("consumables", (["basic power rune": 1]));
}
