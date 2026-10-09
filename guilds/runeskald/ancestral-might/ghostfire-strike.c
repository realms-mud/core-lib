//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Ghostfire Strike");
    addSpecification("source", "runeskald");
    addSpecification("description", "The runeskald channels ancestor spirits "
        "into their weapon in a powerful slam, dealing spiritual and "
        "physical damage in a single ferocious blow.");

    addPrerequisite("level",
        (["type": "level", "guild": "runeskald", "value": 7]));
    addPrerequisite("/guilds/runeskald/ancestral-might/spirit-strike.c",
        (["type": "research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 20);
    addSpecification("command template", "invoke ghostfire strike ##Target##");
    addSpecification("use ability message",
        "##InitiatorName##'s weapon blazes with ghostfire as they deliver a ferocious strike at ##TargetName##.");

    addSpecification("spell point cost", 28);
    addSpecification("stamina point cost", 18);

    addSpecification("damage hit points", ({
        ([
            "probability": 70,
            "base damage": 48,
            "range": 52
        ]),
        ([
            "probability": 30,
            "base damage": 88,
            "range": 85
        ])
    }));

    addSpecification("modifiers", ({
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.08
        ]),
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
        ]),
        ([
            "type": "research",
            "research item": "/guilds/runeskald/ancestral-might/ancestral-blessing.c",
            "name": "Ancestral Blessing",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ])
    }));
    addSpecification("consumables", (["basic ward rune": 1]));
}
