//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Frost Discharge");
    addSpecification("source", "cryomancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the frost discharge spell. By means of this, the "
        "cryomancer releases a massive discharge of freezing energy at a foe.");

    addPrerequisite("/guilds/cryomancer/frost/frost-bolt.c",
        (["type": "research"]));

    addPrerequisite("level",
        (["type": "level",
            "guild": "cryomancer",
            "value": 19
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 150);

    addSpecification("damage hit points", ({ ([
            "probability": 80,
            "base damage": 75,
            "range": 150
        ]),
        ([
            "probability": 20,
            "base damage": 150,
            "range": 300
        ])
    }));
    addSpecification("damage type", "cold");

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/cryomancer/frost/cryostasis.c",
            "name": "Cryostasis",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/cryomancer/frost/crystalline-focus.c",
            "name": "Crystalline Focus",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/cryomancer/frost/enhanced-rime.c",
            "name": "Enhanced Rime",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/cryomancer/frost/glacial-induction.c",
            "name": "Glacial Induction",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/cryomancer/frost/blizzard.c",
            "name": "Blizzard",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/cryomancer/frost/arctic-tempest.c",
            "name": "Arctic Tempest",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/cryomancer/frost/absolute-zero.c",
            "name": "Absolute Zero",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/cryomancer/frost/permafrost-eruption.c",
            "name": "Permafrost Eruption",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/cryomancer/frost/polar-vortex.c",
            "name": "Polar Vortex",
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
            "type": "skill",
            "name": "elemental water",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "level",
            "name": "cryomancer",
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
            "type": "skill",
            "name": "physics",
            "formula": "additive",
            "rate": 0.10
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

    addSpecification("spell point cost modifiers", ([
        "/guilds/cryomancer/frost/wintermasters-reserve.c": 10,
        "/guilds/cryomancer/frost/wintermasters-call.c": 10,
        "/guilds/cryomancer/frost/wintermasters-might.c": 10,
        "/guilds/cryomancer/frost/wintermasters-fury.c": 10
    ]));

    addSpecification("cooldown", 90);
    addSpecification("cooldown modifiers", ([
        "/guilds/cryomancer/frost/wintermasters-boon.c": 10,
        "/guilds/cryomancer/frost/wintermasters-finesse.c": 10,
        "/guilds/cryomancer/frost/wintermasters-endurance.c": 10,
        "/guilds/cryomancer/frost/wintermasters-strength.c": 10,
    ]));

    addSpecification("event handler", "frostDischargeEvent");
    addSpecification("command template", "frost discharge [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::release## a massive discharge of freezing energy "
        "from ##InitiatorPossessive## outstretched arm into ##TargetName##.");
}
