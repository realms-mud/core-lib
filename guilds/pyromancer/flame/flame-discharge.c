//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Flame Discharge");
    addSpecification("source", "pyromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the flame discharge spell. By means of this, the "
        "pyromancer releases a massive discharge of flame energy.");

    addPrerequisite("/guilds/pyromancer/flame/flame-bolt.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "pyromancer",
            "value": 19
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 125);

    addSpecification("damage hit points", ({ ([
            "probability": 80,
            "base damage": 50,
            "range": 100
        ]),
        ([
            "probability": 20,
            "base damage": 100,
            "range": 200
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
            "type": "research",
            "research item": "/guilds/pyromancer/flame/enhanced-blaze.c",
            "name": "Enhanced Blaze",
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

    addSpecification("cooldown", 90);
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

    addSpecification("event handler", "flameDischargeEvent");
    addSpecification("command template", "flame discharge [at ##Target##]");
    addSpecification("use ability message", "A massive discharge of flame "
        "erupts from ##InitiatorPossessive::Name## outstretched hand into "
        "##TargetName##.");
}
