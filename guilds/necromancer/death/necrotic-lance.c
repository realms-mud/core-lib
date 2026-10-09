//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Necrotic Lance");
    addSpecification("source", "necromancer");
    addSpecification("description", "This research provides the user with "
        "knowledge of the necrotic lance spell. The necromancer conjures "
        "a piercing lance of necrotic energy that tears through a foe's "
        "life force.");

    addPrerequisite("/guilds/necromancer/death/root.c",
        (["type": "research"]));

    addPrerequisite("level",
        (["type": "level",
            "guild": "necromancer",
            "value": 5
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("damage hit points", ({ ([
            "probability": 80,
            "base damage": 12,
            "range": 20
        ]),
        ([
            "probability": 20,
            "base damage": 24,
            "range": 40
        ])
    }));

    addSpecification("damage type", "energy");

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
            "research item": "/guilds/necromancer/death/necrotic-induction.c",
            "name": "Necrotic Induction",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/necromancer/death/deep-void.c",
            "name": "Deep Void",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/necromancer/death/death-absolute.c",
            "name": "Death Absolute",
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

    addSpecification("spell point cost", 35);
    addSpecification("cooldown", 18);
    addSpecification("event handler", "necroticLanceEvent");
    addSpecification("command template", "necrotic lance [at ##Target##]");
    addSpecification("use ability message", "A lance of sickly green-black "
        "energy materializes in ##InitiatorPossessive::Name## grip and "
        "##Infinitive::hurl## it through ##TargetName##.");
}
