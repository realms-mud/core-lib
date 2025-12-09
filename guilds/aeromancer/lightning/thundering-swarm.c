//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Thundering Swarm");
    addSpecification("source", "aeromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the thundering swarm spell. By means of this, the "
        "aeromancer unleashes a devastating swarm of electrically-charged "
        "projectiles that bombard all foes in the area with tremendous force, "
        "leaving them staggered, slowed, and weakened.");

    addPrerequisite("/guilds/aeromancer/lightning/raging-tempest.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "aeromancer",
            "value": 67
        ]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("repeat effect", 6);

    addSpecification("damage hit points", ({ ([
            "probability": 80,
            "base damage": 75,
            "range": 150
        ]),
        ([
            "probability": 15,
            "base damage": 150,
            "range": 250
        ]),
        ([
            "probability": 5,
            "base damage": 250,
            "range": 400
        ])
    }));
    addSpecification("damage spell points", ({ ([
            "probability": 80,
            "base damage": 30,
            "range": 60
        ]),
        ([
            "probability": 20,
            "base damage": 60,
            "range": 100
        ])
    }));
    addSpecification("damage stamina points", ({ ([
            "probability": 80,
            "base damage": 25,
            "range": 50
        ]),
        ([
            "probability": 20,
            "base damage": 50,
            "range": 80
        ])
    }));

    addSpecification("damage type", "electricity");

    addSpecification("penalty to attack", 10);
    addSpecification("penalty to defense", 10);
    addSpecification("apply slow", 1);
    addSpecification("apply enfeebled", 1);
    addSpecification("duration", 45);

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
            "rate" : 1.25
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
            "rate" : 0.15
        ]),
        ([
            "type": "level",
            "name": "level",
            "formula": "logarithmic",
            "rate": 1.10
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.30
        ]),
        ([
            "type":"skill",
            "name": "magical essence",
            "formula": "logarithmic",
            "rate": 1.30
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

    addSpecification("spell point cost", 450);
    addSpecification("spell point cost modifiers", ([
        "/guilds/aeromancer/lightning/boltmasters-reserve.c": 10,
        "/guilds/aeromancer/lightning/boltmasters-call.c": 10,
        "/guilds/aeromancer/lightning/boltmasters-might.c": 10,
        "/guilds/aeromancer/lightning/boltmasters-fury.c": 10
    ]));

    addSpecification("cooldown", 180);
    addSpecification("cooldown modifiers", ([
        "/guilds/aeromancer/lightning/boltmasters-boon.c": 10,
        "/guilds/aeromancer/lightning/boltmasters-finess.c": 10,
        "/guilds/aeromancer/lightning/boltmasters-endurance.c": 10,
        "/guilds/aeromancer/lightning/boltmasters-strength.c": 10,
    ]));

    addSpecification("event handler", "thunderingSwarmEvent");
    addSpecification("command template", "thundering swarm");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::thrust## ##InitiatorPossessive## arms skyward as "
        "crackling energy coalesces above ##InitiatorObjective##. A "
        "thundering swarm of electrically-charged projectiles erupts "
        "outward, bombarding everything in sight.");
    addSpecification("repeated ability message", "The thundering swarm "
        "continues its assault as crackling bolts of energy relentlessly "
        "##Infinitive::strike## ##InitiatorPossessive::Name## foes.");
}
