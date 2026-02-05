//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Burning Touch");
    addSpecification("source", "pyromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the burning touch spell. The pyromancer's touch becomes "
        "searing hot, capable of burning through armor and flesh alike.");

    addPrerequisite("/guilds/pyromancer/fire/burning-grasp.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "pyromancer",
            "value": 15
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 45);

    addSpecification("siphon hit points", ({ ([
            "probability": 80,
            "base damage": 20,
            "range": 30
        ]),
        ([
            "probability": 20,
            "base damage": 35,
            "range": 50
        ])
    }));
    addSpecification("damage type", "fire");

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/pyromancer/fire/fire-blast.c",
            "name": "Fire Blast",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/pyromancer/fire/fire-mastery.c",
            "name": "Fire Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "weapon damage",
            "name": "staff",
            "types": ({ "staff" }),
            "formula": "additive",
            "rate": 1.0
        ]),
        ([
            "type": "skill",
            "name": "elemental fire",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "level",
            "name": "level",
            "formula": "logarithmic",
            "rate": 1.05
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
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.05
        ]),
    }));

    addSpecification("cooldown", 25);
    addSpecification("event handler", "burningTouchEvent");
    addSpecification("command template", "burning touch [at ##Target##]");
    addSpecification("use ability message", "##InitiatorPossessive::Name## "
        "hand glows white-hot as ##InitiatorSubjective## ##Infinitive::press## it "
        "against ##TargetName##, searing ##TargetPossessive## flesh.");
}
