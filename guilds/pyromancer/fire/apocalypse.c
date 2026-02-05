//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Apocalypse");
    addSpecification("source", "pyromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the apocalypse spell. The pyromancer unleashes the "
        "ultimate expression of fire magic - a cataclysmic firestorm that "
        "incinerates everything in its path.");

    addPrerequisite("/guilds/pyromancer/fire/withering-flames.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "pyromancer",
            "value": 67
        ]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 300);

    addSpecification("damage hit points", ({ ([
            "probability": 80,
            "base damage": 100,
            "range": 150
        ]),
        ([
            "probability": 20,
            "base damage": 175,
            "range": 250
        ])
    }));
    addSpecification("damage type", "fire");

    addSpecification("repeat effect", 5);
    addSpecification("repeat effect modifiers", ([
        "/guilds/pyromancer/fire/apocalypse-intensity.c": 2
    ]));

    addSpecification("modifiers", ({
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
            "research item": "/guilds/pyromancer/fire/inferno-mastery.c",
            "name": "Inferno Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/pyromancer/fire/pyromantic-insight.c",
            "name": "Pyromantic Insight",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/pyromancer/fire/fire-dominion.c",
            "name": "Fire Dominion",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.35
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

    addSpecification("cooldown", 300);
    addSpecification("event handler", "apocalypseEvent");
    addSpecification("command template", "apocalypse");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::unleash## a cataclysmic apocalypse of fire that "
        "incinerates everything in the area.");
}