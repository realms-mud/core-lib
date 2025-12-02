//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Shocking Wave");
    addSpecification("source", "aeromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the shocking wave spell. By means of this, the "
        "aeromancer releases a series of electrical waves into all foes, "
        "causing serious damage.");

    addPrerequisite("/guilds/aeromancer/lightning/shocking-mist.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "aeromancer",
            "value": 17
        ]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("damage hit points", ({ ([
            "probability": 90,
            "base damage": 40,
            "range": 80
        ]),
        ([
            "probability": 10,
            "base damage": 80,
            "range": 160
        ])
    }));
    addSpecification("damage spell points", ({ ([
            "probability": 90,
            "base damage": 20,
            "range": 40
        ]),
        ([
            "probability": 10,
            "base damage": 40,
            "range": 80
        ])
    }));

    addSpecification("damage type", "electricity");

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/aeromancer/lightning/discharge.c",
            "name" : "Discharge",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.25
        ]),
        ([
            "type":"research",
            "research item": "/guilds/aeromancer/lightning/electrostatics.c",
            "name": "Electrostatics",
            "formula": "multiplicative",
            "base value" : 1,
            "rate": 1.25
        ]),
        ([
            "type":"research",
            "research item": "/guilds/aeromancer/lightning/ionization.c",
            "name" : "Ionization",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.25
        ]),
        ([
            "type":"research",
            "research item": "/guilds/aeromancer/lightning/enhanced-discharge.c",
            "name": "Enhanced Discharge",
            "formula": "multiplicative",
            "base value" : 1,
            "rate": 1.25
        ]),
        ([
            "type":"research",
            "research item": "/guilds/aeromancer/lightning/electrostatic-induction.c",
            "name" : "Electrostatic Induction",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.25
        ]),
        ([
            "type":"research",
            "research item": "/guilds/aeromancer/lightning/enhanced-conductivity.c",
            "name": "Enhanced Conductivity",
            "formula": "multiplicative",
            "base value" : 1,
            "rate": 1.25
        ]),
        ([
            "type":"research",
            "research item": "/guilds/aeromancer/lightning/electrostatic-condenser.c",
            "name" : "Electrostatic Condenser",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.25
        ]),
        ([
            "type":"research",
            "research item": "/guilds/aeromancer/lightning/corona-discharge.c",
            "name": "Corona Discharge",
            "formula": "multiplicative",
            "base value" : 1,
            "rate": 1.25
        ]),
        ([
            "type":"research",
            "research item": "/guilds/aeromancer/lightning/plasma-eruption.c",
            "name" : "Plasma Eruption",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.25
        ]),
        ([
            "type":"research",
            "research item": "/guilds/aeromancer/lightning/flux-condenser.c",
            "name": "Flux Condenser",
            "formula": "multiplicative",
            "base value" : 1,
            "rate": 1.25
        ]),
        ([
            "type": "weapon damage",
            "name" : "staff",
            "types" : ({ "staff" }),
            "formula" : "additive",
            "rate" : 1.0
        ]),
        ([
            "type": "weapon damage",
            "name": "not a staff",
            "types": ({ "dagger", "short sword", "long sword", "bow", "axe",
                "hand and a half sword", "two-handed sword", "crossbow", 
                "sling", "thrown", "pole arm", "mace", "hammer", "flail" }),
            "formula": "subtractive",
            "rate": 1.25
        ]),
        ([
            "type":"skill",
            "name" : "elemental air",
            "formula" : "additive",
            "rate" : 0.10
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
            "type":"skill",
            "name": "magical essence",
            "formula": "logarithmic",
            "rate": 1.25
        ]),
        ([
            "type":"skill",
            "name" : "physics",
            "formula" : "additive",
            "rate" : 0.10
        ]),
        ([
            "type": "skill",
            "name": "mathematics",
            "formula": "additive",
            "rate": 0.05
        ]),
        ([
            "type": "skill",
            "name": "chemistry",
            "formula": "additive",
            "rate": 0.05
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.05
        ]), 
        ([
            "type": "attribute",
            "name": "dexterity",
            "formula": "additive",
            "rate": 0.025
        ]), 
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.025
        ]), 
    }));

    addSpecification("spell point cost", 150);
    addSpecification("spell point cost modifiers", ([
        "/guilds/aeromancer/lightning/boltmasters-reserve.c": 10,
        "/guilds/aeromancer/lightning/boltmasters-call.c": 10,
        "/guilds/aeromancer/lightning/boltmasters-might.c": 10,
        "/guilds/aeromancer/lightning/boltmasters-fury.c": 10
    ]));

    addSpecification("cooldown", 100);
    addSpecification("cooldown modifiers", ([
        "/guilds/aeromancer/lightning/boltmasters-boon.c": 10,
        "/guilds/aeromancer/lightning/boltmasters-finess.c": 10,
        "/guilds/aeromancer/lightning/boltmasters-endurance.c": 10,
        "/guilds/aeromancer/lightning/boltmasters-strength.c": 10,
    ]));

    addSpecification("event handler", "shockingWaveEvent");
    addSpecification("command template", "shocking wave");
    addSpecification("use ability message",  "An overwhelming wave of "
        "electrical energy flies from ##InitiatorPossessive::Name## "
        "outstretched arm.");
}
