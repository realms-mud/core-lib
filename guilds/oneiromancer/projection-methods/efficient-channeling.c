//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Efficient Channeling");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of channeling psychic energy more efficiently, reducing "
        "the mental cost of attacks. It can only be used as part of a "
        "combination attack.");
    addSpecification("usage summary", "A tactical modifier that reduces "
        "spell point cost");

    addPrerequisite("/guilds/oneiromancer/projection-methods/rapid-sending.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 31
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("damage hit points", ({ ([
            "probability": 100,
            "base damage": 18,
            "range": 36
        ])
    }));

    addSpecification("damage type", "psionic");

    addSpecification("modifiers", ({ 
        ([
            "type": "skill",
            "name": "mind",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type":"attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.50
        ]),
    }));

    addSpecification("cooldown", 8);
    addSpecification("event handler", "efficientChannelingEvent");

    addSpecification("use combination message", "##Infinitive::channel## "
        "with perfect efficiency");
}
