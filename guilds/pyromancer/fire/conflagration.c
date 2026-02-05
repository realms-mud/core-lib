//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Conflagration");
    addSpecification("source", "pyromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the conflagration spell. The pyromancer ignites the "
        "very air around the target, creating an explosive burst of flame.");

    addPrerequisite("/guilds/pyromancer/fire/blazing-focus.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "pyromancer",
            "value": 15
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 65);

    addSpecification("damage hit points", ({ ([
            "probability": 80,
            "base damage": 40,
            "range": 55
        ]),
        ([
            "probability": 20,
            "base damage": 60,
            "range": 85
        ])
    }));
    addSpecification("damage type", "fire");

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/pyromancer/fire/blazing-focus.c",
            "name": "Blazing Focus",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
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
            "research item": "/guilds/pyromancer/fire/fire-channeling.c",
            "name": "Fire Channeling",
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

    addSpecification("cooldown", 35);
    addSpecification("event handler", "conflagrationEvent");
    addSpecification("command template", "conflagration [at ##Target##]");
    addSpecification("use ability message", "The air around ##TargetName## "
        "ignites in a sudden conflagration as ##InitiatorName## ##Infinitive::gesture##.");
}
