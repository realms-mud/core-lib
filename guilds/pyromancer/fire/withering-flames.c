//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Withering Flames");
    addSpecification("source", "pyromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the withering flames spell. The pyromancer conjures "
        "flames that wither and consume everything they touch.");

    addPrerequisite("/guilds/pyromancer/fire/whirling-flames.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "pyromancer",
            "value": 57
        ]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 200);

    addSpecification("damage hit points", ({ ([
            "probability": 80,
            "base damage": 60,
            "range": 80
        ]),
        ([
            "probability": 20,
            "base damage": 90,
            "range": 120
        ])
    }));
    addSpecification("damage type", "fire");

    addSpecification("repeat effect", 3);
    addSpecification("repeat effect modifiers", ([
        "/guilds/pyromancer/fire/withering-flames-intensity.c": 2
    ]));

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/pyromancer/fire/fire-mastery.c",
            "name": "Fire Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/pyromancer/fire/inferno-mastery.c",
            "name": "Inferno Mastery",
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

    addSpecification("cooldown", 150);
    addSpecification("event handler", "witheringFlamesEvent");
    addSpecification("command template", "withering flames");
    addSpecification("use ability message", "Withering flames consume "
        "everything in the area as ##InitiatorName## ##Infinitive::gesture##.");
}