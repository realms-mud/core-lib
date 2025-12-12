//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Frost Discharge");
    addSpecification("source", "aquamancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the frost discharge spell. By means of this, the "
        "aquamancer releases a massive discharge of freezing energy at a foe.");

    addPrerequisite("/guilds/aquamancer/ice/ice-bolt.c",
        (["type":"research"]));

    addPrerequisite("level", 
        (["type": "level", 
          "guild": "aquamancer",
          "value": 19 ]));

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
            "research item": "/guilds/aquamancer/ice/cryostatics.c",
            "name": "Cryostatics",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/aquamancer/ice/crystallization.c",
            "name": "Crystallization",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/aquamancer/ice/enhanced-frost.c",
            "name": "Enhanced Frost",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/aquamancer/ice/cryogenic-induction.c",
            "name": "Cryogenic Induction",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/aquamancer/ice/enhanced-freezing.c",
            "name": "Enhanced Freezing",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/aquamancer/ice/cryogenic-condenser.c",
            "name": "Cryogenic Condenser",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/aquamancer/ice/glacial-burst.c",
            "name": "Glacial Burst",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/aquamancer/ice/permafrost-eruption.c",
            "name": "Permafrost Eruption",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/aquamancer/ice/glacier-condenser.c",
            "name": "Glacier Condenser",
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

    addSpecification("cooldown", 90);
    addSpecification("cooldown modifiers", ([
        "/guilds/aquamancer/ice/frostmasters-boon.c": 10,
        "/guilds/aquamancer/ice/frostmasters-finesse.c": 10,
        "/guilds/aquamancer/ice/frostmasters-endurance.c": 10,
        "/guilds/aquamancer/ice/frostmasters-strength.c": 10,
    ]));

    addSpecification("spell point cost modifiers", ([
        "/guilds/aquamancer/ice/frostmasters-reserve.c": 10,
        "/guilds/aquamancer/ice/frostmasters-call.c": 10,
        "/guilds/aquamancer/ice/frostmasters-might.c": 10,
        "/guilds/aquamancer/ice/frostmasters-fury.c": 10
    ]));

    addSpecification("event handler", "frostDischargeEvent");
    addSpecification("command template", "frost discharge [at ##Target##]");
    addSpecification("use ability message", "A massive discharge of "
        "freezing energy erupts from ##InitiatorPossessive::Name## "
        "outstretched hands into ##TargetName##.");
}
