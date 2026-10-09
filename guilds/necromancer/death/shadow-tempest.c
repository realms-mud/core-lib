//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Shadow Tempest");
    addSpecification("source", "necromancer");
    addSpecification("description", "This research provides the user with "
        "knowledge of the shadow tempest spell. The necromancer calls a "
        "howling tempest of shadow energy that tears apart all it touches.");

    addPrerequisite("/guilds/necromancer/death/entropy-wave.c",
        (["type": "research"]));

    addPrerequisite("level",
        (["type": "level",
            "guild": "necromancer",
            "value": 37
        ]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("damage hit points", ({ ([
            "probability": 80,
            "base damage": 65,
            "range": 120
        ]),
        ([
            "probability": 20,
            "base damage": 130,
            "range": 240
        ])
    }));

    addSpecification("damage type", "shadow");

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/necromancer/death/death-incarnate.c",
            "name": "Death Incarnate",
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

    addSpecification("spell point cost", 150);
    addSpecification("cooldown", 70);
    addSpecification("event handler", "shadowTempestEvent");
    addSpecification("command template", "shadow tempest");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::raise## ##InitiatorPossessive## arms and "
        "##Infinitive::call## a tempest of howling shadow that "
        "##Infinitive::tear## across the area.");
}
