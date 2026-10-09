//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Soul Rend");
    addSpecification("source", "necromancer");
    addSpecification("description", "This research provides the user with "
        "knowledge of the soul rend spell. The necromancer tears at the "
        "very soul of a foe, dealing shadow damage that bypasses mundane "
        "protections.");

    addPrerequisite("/guilds/necromancer/death/shadow-bolt.c",
        (["type": "research"]));

    addPrerequisite("level",
        (["type": "level",
            "guild": "necromancer",
            "value": 13
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("damage hit points", ({ ([
            "probability": 80,
            "base damage": 28,
            "range": 50
        ]),
        ([
            "probability": 20,
            "base damage": 55,
            "range": 100
        ])
    }));

    addSpecification("damage type", "shadow");

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/necromancer/death/death-trance.c",
            "name": "Death Trance",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/necromancer/death/void-strike.c",
            "name": "Void Strike",
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

    addSpecification("spell point cost", 80);
    addSpecification("cooldown", 40);
    addSpecification("event handler", "soulRendEvent");
    addSpecification("command template", "soul rend [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::plunge## a hand of crackling shadow into "
        "##TargetName##, ##Infinitive::rend## at ##TargetPossessive## "
        "very soul.");
}
