//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Gust");
    addSpecification("source", "aeromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the gust spell. By means of this, the "
        "aeromancer is able to unleash a powerful blast of wind at a foe.");

    addPrerequisite("/guilds/aeromancer/air/root.c",
        (["type":"research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 10);

    addSpecification("damage hit points", ({ ([
            "probability":80,
            "base damage" : 5,
            "range" : 10
        ]),
        ([
            "probability":20,
            "base damage" : 10,
            "range" : 20
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
            "research item": "/guilds/aeromancer/air/arctic-focus.c",
            "name": "Arctic Focus",
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
            "type":"weapon damage",
            "name" : "staff",
            "types" : ({ "staff" }),
            "formula" : "additive",
            "rate" : 1.0
        ]),
        ([
            "type":"weapon damage",
            "name" : "not a staff",
            "types" : ({ "dagger", "short sword", "long sword", "bow", "axe",
                "hand and a half sword", "two-handed sword", "crossbow",
                "sling", "thrown", "pole arm", "mace", "hammer", "flail" }),
            "formula" : "subtractive",
            "rate" : 1.25
        ]),
        ([
            "type":"skill",
            "name" : "elemental air",
            "formula" : "additive",
            "rate" : 0.10
        ]),
        ([
            "type":"level",
            "name" : "level",
            "formula" : "logarithmic",
            "rate" : 1.05
        ]),
        ([
            "type":"skill",
            "name" : "spellcraft",
            "formula" : "logarithmic",
            "rate" : 1.25
        ]),
        ([
            "type":"skill",
            "name" : "magical essence",
            "formula" : "logarithmic",
            "rate" : 1.25
        ]),
        ([
            "type":"skill",
            "name" : "physics",
            "formula" : "additive",
            "rate" : 0.10
        ]),
        ([
            "type":"skill",
            "name" : "mathematics",
            "formula" : "additive",
            "rate" : 0.05
        ]),
        ([
            "type":"skill",
            "name" : "chemistry",
            "formula" : "additive",
            "rate" : 0.05
        ]),
        ([
            "type":"attribute",
            "name" : "intelligence",
            "formula" : "additive",
            "rate" : 0.05
        ]),
        ([
            "type":"attribute",
            "name" : "dexterity",
            "formula" : "additive",
            "rate" : 0.025
        ]),
        ([
            "type":"attribute",
            "name" : "wisdom",
            "formula" : "additive",
            "rate" : 0.025
        ]),
        }));

    addSpecification("cooldown", 6);
    addSpecification("event handler", "gustEvent");
    addSpecification("command template", "gust [at ##Target##]");
    addSpecification("use ability message", "A roaring blast of wind erupts from "
        "##InitiatorPossessive::Name## outstretched hand, slamming into ##TargetName##.");
}
