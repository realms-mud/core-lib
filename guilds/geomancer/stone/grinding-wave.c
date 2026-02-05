//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Grinding Wave");
    addSpecification("source", "geomancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the grinding wave spell. By means of this, the "
        "geomancer unleashes a powerful wave of abrasive stone that "
        "engulfs all nearby foes.");

    addPrerequisite("/guilds/geomancer/stone/dust-cloud.c",
        (["type":"research"]));

    addPrerequisite("level", 
        (["type": "level", 
          "guild": "geomancer",
          "value": 17 ]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 100);

    addSpecification("damage hit points", ({ ([
            "probability": 80,
            "base damage": 50,
            "range": 100
        ]),
        ([
            "probability": 20,
            "base damage": 100,
            "range": 200
        ])
    }));
    addSpecification("damage type", "physical");

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/geomancer/stone/petrification.c",
            "name": "Petrification",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/geomancer/stone/ite.c",
            "name": "ite",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/geomancer/stone/enhanced-stone.c",
            "name": "Enhanced Stone",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/geomancer/stone/geological-induction.c",
            "name": "Geological Induction",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/geomancer/stone/enhanced-crushing.c",
            "name": "Enhanced Crushing",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/geomancer/stone/tectonic-condenser.c",
            "name": "Tectonic Condenser",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/geomancer/stone/seismic-burst.c",
            "name": "Seismic Burst",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/geomancer/stone/tectonic-eruption.c",
            "name": "Tectonic Eruption",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/geomancer/stone/mountain-condenser.c",
            "name": "Mountain Condenser",
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

    addSpecification("cooldown", 120);
    addSpecification("cooldown modifiers", ([
        "/guilds/geomancer/stone/stonemasters-boon.c": 10,
        "/guilds/geomancer/stone/stonemasters-finesse.c": 10,
        "/guilds/geomancer/stone/stonemasters-endurance.c": 10,
        "/guilds/geomancer/stone/stonemasters-strength.c": 10,
    ]));

    addSpecification("spell point cost modifiers", ([
        "/guilds/geomancer/stone/stonemasters-reserve.c": 10,
        "/guilds/geomancer/stone/stonemasters-call.c": 10,
        "/guilds/geomancer/stone/stonemasters-might.c": 10,
        "/guilds/geomancer/stone/stonemasters-fury.c": 10
    ]));

    addSpecification("event handler", "grindingWaveEvent");
    addSpecification("command template", "grinding wave");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::unleash## a powerful wave of grinding stone that "
        "sweeps across the area.");
}
