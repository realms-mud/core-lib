//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Invigorating Siphon");
    addSpecification("source", "necromancer");
    addSpecification("description", "This research provides knowledge of siphoning vitality to greatly restore the caster.");

    addPrerequisite("/guilds/necromancer/effects/siphon-hp.c",
        (["type": "research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 28);
    addSpecification("damage hit points", ({ ([
        "probability": 80,
        "base damage": 5,
        "range": 10
    ]),
    ([
        "probability": 20,
        "base damage": 10,
        "range": 20
    ])
    }));
    addSpecification("damage type", "energy");
    addSpecification("siphon hit points", ({ ([
        "probability": 100,
        "base damage": 5,
        "range": 8
    ])
    }));
    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/necromancer/construct/spell-focus.c",
            "name": "Spell Focus",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.25
        ]),
        ([
            "type": "skill",
            "name": "magical essence",
            "formula": "logarithmic",
            "rate": 1.25
        ]),
        ([
            "type": "skill",
            "name": "spirit",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "level",
            "name": "necromancer",
            "formula": "logarithmic",
            "rate": 1.05
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.05
        ]),
    }));
    addSpecification("cooldown", 14);
    addSpecification("event handler", "necromancerInvigoratingEvent");
}
