//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Void Strike");
    addSpecification("source", "necromancer");
    addSpecification("description", "This research provides the user with "
        "knowledge of the void strike spell. The necromancer channels the "
        "void itself into a devastating strike of pure annihilating energy.");

    addPrerequisite("/guilds/necromancer/death/shadow-storm.c",
        (["type": "research"]));

    addPrerequisite("level",
        (["type": "level",
            "guild": "necromancer",
            "value": 23
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("damage hit points", ({ ([
            "probability": 80,
            "base damage": 40,
            "range": 70
        ]),
        ([
            "probability": 20,
            "base damage": 80,
            "range": 140
        ])
    }));

    addSpecification("damage type", "energy");

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/necromancer/death/entropy-wave.c",
            "name": "Entropy Wave",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/necromancer/death/shadow-tempest.c",
            "name": "Shadow Tempest",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
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

    addSpecification("spell point cost", 110);
    addSpecification("cooldown", 55);
    addSpecification("event handler", "voidStrikeEvent");
    addSpecification("command template", "void strike [at ##Target##]");
    addSpecification("use ability message", "The air tears open as "
        "##InitiatorName## ##Infinitive::channel## the void into a "
        "single annihilating strike upon ##TargetName##.");
}
