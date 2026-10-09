//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Rune-Burst");
    addSpecification("source", "runeskald");
    addSpecification("description", "The runeskald detonates one of their "
        "bound runes in a burst of raw runic energy, dealing significant "
        "damage to a single target.");

    addPrerequisite("/guilds/runeskald/runic-binding/binding-mastery.c",
        (["type": "research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 12);
    addSpecification("command template", "invoke rune-burst ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::detonate## a bound rune in a blinding flash of runic force at ##TargetName##.");

    addSpecification("spell point cost", 45);
    addSpecification("stamina point cost", 12);

    addSpecification("damage hit points", ({
        ([
            "probability": 75,
            "base damage": 30,
            "range": 30
        ]),
        ([
            "probability": 25,
            "base damage": 65,
            "range": 40
        ])
    }));

    addSpecification("consumables", (["basic power rune": 1]));

    addSpecification("modifiers", ({
        ([
            "type": "attribute",
            "name": "intelligence",
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
}
