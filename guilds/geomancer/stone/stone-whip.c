//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Stone Whip");
    addSpecification("source", "geomancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the stone whip spell. By means of this, the "
        "geomancer conjures a powerful whip of solid stone that lashes "
        "enemies, draining their vitals and restoring the caster's.");

    addPrerequisite("/guilds/geomancer/stone/stone-lash.c",
        (["type":"research"]));

    addPrerequisite("level", 
        (["type": "level", 
          "guild": "geomancer",
          "value": 13 ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 75);

    addSpecification("siphon hit points", ({ ([
            "probability": 100,
            "base damage": 25,
            "range": 50
        ]),
    }));
    addSpecification("siphon spell points", ({ ([
            "probability": 100,
            "base damage": 15,
            "range": 30
        ]),
    }));
    addSpecification("siphon stamina points", ({ ([
            "probability": 100,
            "base damage": 15,
            "range": 30
        ]),
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
            "name": "geology",
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

    addSpecification("cooldown", 45);
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

    addSpecification("event handler", "stoneWhipEvent");
    addSpecification("command template", "stone whip [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::conjure## a whip of solid stone that lashes out "
        "at ##TargetName##, draining ##TargetPossessive## vitality.");
}
