//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Absolute Darkness");
    addSpecification("source", "rogue");
    addSpecification("description", "This research provides the rogue with "
        "the Absolute Darkness shadow technique.");

    addPrerequisite("/guilds/rogue/shadow-arts/shadow-mastery.c",
        (["type": "research"]));

    addPrerequisite("level",
        (["type": "level",
            "guild": "rogue",
            "value": 33
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 115);
    addSpecification("cooldown", 26);
    addSpecification("command template", "absolute darkness [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::unleash## absolute darkness "
        "upon ##TargetName##.");

    addSpecification("damage hit points", ({
        ([
            "probability": 80,
            "base damage": 120,
            "range": 78
        ]),
        ([
            "probability": 20,
            "base damage": 192,
            "range": 117
        ])
    }));

    addSpecification("damage type", "shadow");

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/rogue/shadow-arts/shadow-weaving.c",
            "name": "Shadow Weaving",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/rogue/shadow-arts/shadow-mastery.c",
            "name": "Shadow Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/rogue/shadow-arts/shadow-mastery-ii.c",
            "name": "Shadow Mastery II",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.05
        ]),
        ([
            "type": "skill",
            "name": "hide",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "skill",
            "name": "move silently",
            "formula": "additive",
            "rate": 0.08
        ]),
        ([
            "type": "skill",
            "name": "perception",
            "formula": "additive",
            "rate": 0.05
        ]),
        ([
            "type": "skill",
            "name": "concentration",
            "formula": "additive",
            "rate": 0.05
        ]),
        ([
            "type": "attribute",
            "name": "dexterity",
            "formula": "additive",
            "rate": 0.20
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "level",
            "name": "rogue",
            "formula": "logarithmic",
            "rate": 1.05
        ])
    }));
}
