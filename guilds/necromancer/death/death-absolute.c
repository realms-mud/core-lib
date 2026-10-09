//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Death Absolute");
    addSpecification("source", "necromancer");
    addSpecification("description", "This research provides the user with "
        "knowledge of the death absolute spell. The necromancer channels "
        "the absolute essence of death itself into a devastating strike.");

    addPrerequisite("/guilds/necromancer/death/void-condenser.c",
        (["type": "research"]));

    addPrerequisite("level",
        (["type": "level",
            "guild": "necromancer",
            "value": 51
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("damage hit points", ({ ([
            "probability": 80,
            "base damage": 100,
            "range": 180
        ]),
        ([
            "probability": 20,
            "base damage": 200,
            "range": 360
        ])
    }));

    addSpecification("damage type", "energy");

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/necromancer/death/necrotic-induction.c",
            "name": "Necrotic Induction",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/necromancer/death/void-condenser.c",
            "name": "Void Condenser",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/necromancer/death/entropic-eruption.c",
            "name": "Entropic Eruption",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/necromancer/death/void-vortex.c",
            "name": "Void Vortex",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
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
            "type": "skill",
            "name": "evocation",
            "formula": "additive",
            "rate": 0.05
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
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.025
        ]),
    }));

    addSpecification("spell point cost", 180);
    addSpecification("spell point cost modifiers", ([
        "/guilds/necromancer/death/deathweavers-reserve.c": 10,
        "/guilds/necromancer/death/deathweavers-call.c": 10,
        "/guilds/necromancer/death/deathweavers-might.c": 10,
        "/guilds/necromancer/death/deathweavers-fury.c": 10
    ]));

    addSpecification("cooldown", 120);
    addSpecification("cooldown modifiers", ([
        "/guilds/necromancer/death/deathweavers-boon.c": 10,
        "/guilds/necromancer/death/deathweavers-finesse.c": 10,
        "/guilds/necromancer/death/deathweavers-endurance.c": 10,
        "/guilds/necromancer/death/deathweavers-strength.c": 10,
    ]));

    addSpecification("event handler", "deathAbsoluteEvent");
    addSpecification("command template", "death absolute [at ##Target##]");
    addSpecification("use ability message", "The world ##Infinitive::dim## "
        "as ##InitiatorName## ##Infinitive::channel## the absolute "
        "essence of death and ##Infinitive::hurl## it at ##TargetName##.");
}
