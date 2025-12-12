//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Riptide");
    addSpecification("source", "aquamancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the riptide spell. The aquamancer creates a powerful "
        "undercurrent that yanks a target off balance while simultaneously "
        "battering them with crushing water pressure. The disorienting force "
        "leaves victims vulnerable.");

    addPrerequisite("/guilds/aquamancer/water/current.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "aquamancer",
            "value": 21
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 60);

    addSpecification("damage hit points", ({ ([
            "probability": 80,
            "base damage": 35,
            "range": 50
        ]),
        ([
            "probability": 20,
            "base damage": 55,
            "range": 75
        ])
    }));
    addSpecification("damage type", "water");

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/aquamancer/water/water-blast.c",
            "name": "Water Blast",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/aquamancer/water/water-mastery.c",
            "name": "Water Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/aquamancer/water/water-channeling.c",
            "name": "Water Channeling",
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
            "name": "elemental water",
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

    addSpecification("cooldown", 16);
    addSpecification("event handler", "riptideEvent");
    addSpecification("command template", "riptide [at ##Target##]");
    addSpecification("use ability message", "A powerful riptide yanks at "
        "##TargetName## as ##InitiatorName## ##Infinitive::pull## "
        "##InitiatorPossessive## hand back sharply, crushing water following "
        "in its wake.");
}
