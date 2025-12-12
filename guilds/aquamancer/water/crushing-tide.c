//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Crushing Tide");
    addSpecification("source", "aquamancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the crushing tide spell. The aquamancer summons the "
        "full weight of the ocean's depths, bringing crushing pressure to bear "
        "on a single target. The victim feels as though the entire sea is "
        "pressing down upon them.");

    addPrerequisite("/guilds/aquamancer/water/frozen-depths.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "aquamancer",
            "value": 37
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 95);

    addSpecification("damage hit points", ({ ([
            "probability": 80,
            "base damage": 65,
            "range": 90
        ]),
        ([
            "probability": 20,
            "base damage": 100,
            "range": 140
        ])
    }));
    addSpecification("damage type", "water");

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/aquamancer/water/boiling-convergence.c",
            "name": "Boiling Convergence",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/aquamancer/water/frozen-depths.c",
            "name": "Frozen Depths",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/aquamancer/water/ocean-mastery.c",
            "name": "Ocean Mastery",
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

    addSpecification("cooldown", 25);
    addSpecification("event handler", "crushingTideEvent");
    addSpecification("command template", "crushing tide [at ##Target##]");
    addSpecification("use ability message", "The crushing weight of the "
        "ocean's depths descends upon ##TargetName## as ##InitiatorName## "
        "##Infinitive::press## ##InitiatorPossessive## palms together.");
}
