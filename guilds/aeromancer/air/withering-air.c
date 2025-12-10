//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Withering Air");
    addSpecification("source", "aeromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the withering air spell. The aeromancer creates a zone "
        "of desiccating wind that strips moisture from everything it touches. "
        "Enemies caught within feel their strength drain away as the parched "
        "air saps their vitality, leaving them weakened and vulnerable.");

    addPrerequisite("/guilds/aeromancer/air/whirling-wind.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "aeromancer",
            "value": 57
        ]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 200);

    addSpecification("damage hit points", ({ ([
            "probability": 80,
            "base damage": 55,
            "range": 90
        ]),
        ([
            "probability": 20,
            "base damage": 90,
            "range": 140
        ])
    }));
    addSpecification("damage stamina points", ({ ([
            "probability": 80,
            "base damage": 40,
            "range": 65
        ]),
        ([
            "probability": 20,
            "base damage": 65,
            "range": 100
        ])
    }));
    addSpecification("damage spell points", ({ ([
            "probability": 80,
            "base damage": 30,
            "range": 50
        ]),
        ([
            "probability": 20,
            "base damage": 50,
            "range": 80
        ])
    }));
    addSpecification("damage type", "air");

    addSpecification("apply enfeebled", 1);
    addSpecification("penalty to attack", 10);
    addSpecification("penalty to defense", 10);
    addSpecification("penalty to soak", 8);
    addSpecification("duration", 60);

    addSpecification("modifiers", ({ 
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
            "research item": "/guilds/aeromancer/air/air-channeling.c",
            "name": "Air Channeling",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/aeromancer/air/zephyric-flow.c",
            "name": "Zephyric Flow",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/aeromancer/air/eye-of-the-tempest.c",
            "name": "Eye of the Tempest",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/aeromancer/air/elemental-attunement.c",
            "name": "Elemental Attunement",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/aeromancer/air/tempest-mastery.c",
            "name": "Tempest Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/aeromancer/air/aeromantic-insight.c",
            "name": "Aeromantic Insight",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/aeromancer/air/air-dominion.c",
            "name": "Air Dominion",
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

    addSpecification("cooldown", 85);
    addSpecification("event handler", "witheringAirEvent");
    addSpecification("command template", "withering air");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::spread## ##InitiatorPossessive## arms and a wave "
        "of desiccating air radiates outward, draining the life force "
        "from all nearby foes.");
}
