//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Entropic Eruption");
    addSpecification("source", "necromancer");
    addSpecification("description", "This research provides the user with "
        "knowledge of the entropic eruption spell. The necromancer causes "
        "a massive eruption of entropic energy, obliterating targets.");

    addPrerequisite("/guilds/necromancer/death/death-absolute.c",
        (["type": "research"]));

    addPrerequisite("level",
        (["type": "level",
            "guild": "necromancer",
            "value": 57
        ]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("damage hit points", ({ ([
            "probability": 80,
            "base damage": 120,
            "range": 220
        ]),
        ([
            "probability": 20,
            "base damage": 240,
            "range": 440
        ])
    }));

    addSpecification("damage type", "energy");

    addSpecification("modifiers", ({
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

    addSpecification("spell point cost", 200);
    addSpecification("cooldown", 130);
    addSpecification("event handler", "entropicEruptionEvent");
    addSpecification("command template", "entropic eruption");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::tear## open a rift of entropy that "
        "##Infinitive::erupt## in a catastrophic explosion of "
        "annihilating energy.");
}
