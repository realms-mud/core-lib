//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Inferno");
    addSpecification("source", "pyromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the inferno spell. The pyromancer unleashes a massive "
        "explosion of flame that engulfs all enemies in the area.");

    addPrerequisite("/guilds/pyromancer/fire/fire-blast.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "pyromancer",
            "value": 13
        ]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 75);

    addSpecification("damage hit points", ({ ([
            "probability": 80,
            "base damage": 35,
            "range": 50
        ]),
        ([
            "probability": 20,
            "base damage": 55,
            "range": 80
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
            "research item": "/guilds/pyromancer/fire/infernal-force.c",
            "name": "Infernal Force",
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
    addSpecification("event handler", "infernoEvent");
    addSpecification("command template", "inferno");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::unleash## a massive inferno that engulfs everything nearby.");
}
