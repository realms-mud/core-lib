//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Ice Whip");
    addSpecification("source", "aquamancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the ice whip spell. By means of this, the "
        "aquamancer conjures a powerful whip of solid ice that lashes "
        "enemies, draining their vitals and restoring the caster's.");

    addPrerequisite("/guilds/aquamancer/ice/ice-lash.c",
        (["type":"research"]));

    addPrerequisite("level", 
        (["type": "level", 
          "guild": "aquamancer",
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

    addSpecification("cooldown", 45);
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

    addSpecification("event handler", "iceWhipEvent");
    addSpecification("command template", "ice whip [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::conjure## a whip of solid ice that lashes out "
        "at ##TargetName##, draining ##TargetPossessive## vitality.");
}
