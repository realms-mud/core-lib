//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Cataclysmic Tempest");
    addSpecification("source", "aeromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the cataclysmic tempest spell - the ultimate expression "
        "of aeromantic power. The aeromancer tears open a rift to the elemental "
        "plane of air, releasing a catastrophic storm of impossible fury. Winds "
        "that could shatter mountains howl across the battlefield, striking "
        "again and again until nothing remains standing.");

    addPrerequisite("/guilds/aeromancer/air/withering-air.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "aeromancer",
            "value": 67
        ]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 350);
    addSpecification("repeat effect", 6);

    addSpecification("damage hit points", ({ ([
            "probability": 80,
            "base damage": 60,
            "range": 100
        ]),
        ([
            "probability": 15,
            "base damage": 100,
            "range": 160
        ]),
        ([
            "probability": 5,
            "base damage": 160,
            "range": 250
        ])
    }));
    addSpecification("damage stamina points", ({ ([
            "probability": 80,
            "base damage": 35,
            "range": 55
        ]),
        ([
            "probability": 20,
            "base damage": 55,
            "range": 90
        ])
    }));
    addSpecification("damage spell points", ({ ([
            "probability": 80,
            "base damage": 25,
            "range": 40
        ]),
        ([
            "probability": 20,
            "base damage": 40,
            "range": 70
        ])
    }));
    addSpecification("damage type", "air");

    addSpecification("apply enfeebled", 1);
    addSpecification("apply slow", 1);
    addSpecification("penalty to attack", 15);
    addSpecification("penalty to defense", 15);
    addSpecification("penalty to soak", 10);
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
            "rate": 1.25
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

    addSpecification("cooldown", 180);
    addSpecification("event handler", "cataclysmicTempestEvent");
    addSpecification("command template", "cataclysmic tempest");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::raise## ##InitiatorPossessive## arms to the sky and "
        "##Infinitive::unleash## a cataclysmic tempest. The very air itself "
        "seems to scream as winds of impossible fury tear through the area.");
    addSpecification("repeated ability message", "The cataclysmic tempest "
        "continues its devastating assault, waves of destructive wind "
        "relentlessly battering ##InitiatorPossessive::Name## foes.");
}
