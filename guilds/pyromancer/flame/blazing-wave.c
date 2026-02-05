//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Blazing Wave");
    addSpecification("source", "pyromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the blazing wave spell. By means of this, the "
        "pyromancer unleashes a wave of intense flames that burns all nearby.");

    addPrerequisite("/guilds/pyromancer/flame/scorching-mist.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "pyromancer",
            "value": 17
        ]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 75);

    addSpecification("damage hit points", ({ ([
            "probability": 80,
            "base damage": 35,
            "range": 60
        ]),
        ([
            "probability": 20,
            "base damage": 60,
            "range": 100
        ])
    }));
    addSpecification("damage type", "fire");

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/pyromancer/flame/pyrostatics.c",
            "name": "Pyrostatics",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/pyromancer/flame/combustion.c",
            "name": "Combustion",
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

    addSpecification("cooldown", 60);
    addSpecification("cooldown modifiers", ([
        "/guilds/pyromancer/flame/flamemasters-boon.c": 10,
        "/guilds/pyromancer/flame/flamemasters-finesse.c": 10,
        "/guilds/pyromancer/flame/flamemasters-endurance.c": 10,
        "/guilds/pyromancer/flame/flamemasters-strength.c": 10,
    ]));

    addSpecification("spell point cost modifiers", ([
        "/guilds/pyromancer/flame/flamemasters-reserve.c": 10,
        "/guilds/pyromancer/flame/flamemasters-call.c": 10,
        "/guilds/pyromancer/flame/flamemasters-might.c": 10,
        "/guilds/pyromancer/flame/flamemasters-fury.c": 10
    ]));

    addSpecification("event handler", "blazingWaveEvent");
    addSpecification("command template", "blazing wave");
    addSpecification("use ability message", "A blazing wave of fire erupts "
        "from ##InitiatorName## and washes over the area.");
}
