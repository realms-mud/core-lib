//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Corrosive Grit");
    addSpecification("source", "geomancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the corrosive grit spell. The geomancer conjures a blast "
        "of magically-charged abrasive grit that scours armor and flesh alike.");

    addPrerequisite("/guilds/geomancer/earth/dust-storm.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "geomancer",
            "value": 17
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 90);

    addSpecification("damage hit points", ({ ([
            "probability": 80,
            "base damage": 50,
            "range": 80
        ]),
        ([
            "probability": 20,
            "base damage": 80,
            "range": 120
        ])
    }));
    addSpecification("damage type", "acid");

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/geomancer/earth/earthen-convergence.c",
            "name": "Earthen Convergence",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/geomancer/earth/molten-depths.c",
            "name": "Molten Depths",
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
            "name": "elemental earth",
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

    addSpecification("cooldown", 40);
    addSpecification("event handler", "corrosiveGritEvent");
    addSpecification("command template", "corrosive grit [at ##Target##]");
    addSpecification("use ability message", "A blast of corrosive grit erupts "
        "from ##InitiatorPossessive::Name## hands, scouring ##TargetName##.");
}
