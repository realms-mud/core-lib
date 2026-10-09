//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "World Rune Devastation");
    addSpecification("source", "runeskald");
    addSpecification("description", "The runeskald speaks the most destructive "
        "of known world runes directly at a single enemy, calling down a "
        "cataclysm of primordial runic energy.");

    addPrerequisite("/guilds/runeskald/world-rune/world-rune-aegis.c",
        (["type": "research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 12);
    addSpecification("command template", "invoke world rune devastation ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::speak## a world rune of devastation and the air tears apart around ##TargetName##.");

    addSpecification("spell point cost", 90);
    addSpecification("stamina point cost", 30);

    addSpecification("damage hit points", ({
        ([
            "probability": 55,
            "base damage": 60,
            "range": 50
        ]),
        ([
            "probability": 45,
            "base damage": 110,
            "range": 60
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
