//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Updraft");
    addSpecification("source", "aeromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the updraft spell. By means of this, the aeromancer "
        "creates a powerful upward blast of wind that lifts and slams enemies.");

    addPrerequisite("/guilds/aeromancer/air/air-barrier.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "aeromancer",
            "value": 27
        ]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 100);

    addSpecification("damage hit points", ({ ([
            "probability": 80,
            "base damage": 45,
            "range": 70
        ]),
        ([
            "probability": 20,
            "base damage": 70,
            "range": 100
        ])
    }));
    addSpecification("damage type", "air");

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/aeromancer/air/blast-of-wind.c",
            "name": "Blast of Wind",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/aeromancer/air/gale-force.c",
            "name": "Gale Force",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/aeromancer/air/wind-mastery.c",
            "name": "Wind Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/aeromancer/air/whirlwind.c",
            "name": "Whirlwind",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ])
    }));
}
