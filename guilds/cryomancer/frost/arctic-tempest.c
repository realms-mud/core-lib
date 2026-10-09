//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Arctic Tempest");
    addSpecification("source", "cryomancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the arctic tempest spell. By means of this, the "
        "cryomancer unleashes a howling arctic tempest that devastates all "
        "foes in the area with extreme cold and driving sleet.");

    addPrerequisite("/guilds/cryomancer/frost/blizzard.c",
        (["type": "research"]));

    addPrerequisite("level",
        (["type": "level",
            "guild": "cryomancer",
            "value": 37
        ]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 350);
    addSpecification("cooldown", 180);

    addSpecification("damage hit points", ({ ([
            "probability": 80,
            "base damage": 200,
            "range": 400
        ]),
        ([
            "probability": 20,
            "base damage": 400,
            "range": 800
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
            "type": "research",
            "research item":
                "/guilds/cryomancer/frost/frozen-apocalypse.c",
            "name": "Frozen Apocalypse",
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

    addSpecification("event handler", "arcticTempestEvent");
    addSpecification("command template", "arctic tempest");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::unleash## a howling arctic tempest of devastating "
        "fury that engulfs the area in driving sleet and ice.");
}
