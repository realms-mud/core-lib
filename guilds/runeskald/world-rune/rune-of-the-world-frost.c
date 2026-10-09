//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Rune of the World-Frost");
    addSpecification("source", "runeskald");
    addSpecification("description", "The runeskald speaks the rune of the "
        "world-frost, encasing a single target in a wave of primordial "
        "cold that deals heavy damage and briefly slows the victim.");

    addPrerequisite("/guilds/runeskald/world-rune/world-rune-conduit.c",
        (["type": "research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 12);
    addSpecification("command template", "invoke rune of the world-frost ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::speak## the rune of the world-frost and a wave of primordial cold crashes into ##TargetName##.");

    addSpecification("spell point cost", 70);
    addSpecification("stamina point cost", 20);

    addSpecification("damage hit points", ({
        ([
            "probability": 65,
            "base damage": 45,
            "range": 40
        ]),
        ([
            "probability": 35,
            "base damage": 85,
            "range": 50
        ])
    }));

    addSpecification("modifiers", ({
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.09
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
