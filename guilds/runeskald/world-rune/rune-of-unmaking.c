//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Rune of Unmaking");
    addSpecification("source", "runeskald");
    addSpecification("description", "The runeskald speaks a world rune of "
        "unmaking directly at a foe, unraveling the bonds that hold their "
        "form together for devastating necrotic damage.");

    addPrerequisite("/guilds/runeskald/world-rune/world-rune-lore.c",
        (["type": "research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 12);
    addSpecification("command template", "invoke rune of unmaking ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::speak## a rune of unmaking that tears at ##TargetName##'s very form.");

    addSpecification("spell point cost", 55);
    addSpecification("stamina point cost", 15);

    addSpecification("damage hit points", ({
        ([
            "probability": 65,
            "base damage": 40,
            "range": 35
        ]),
        ([
            "probability": 35,
            "base damage": 80,
            "range": 50
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
