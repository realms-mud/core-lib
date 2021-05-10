//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Shocking Lash");
    addSpecification("source", "aeromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the shocking lash spell. By means of this, the "
        "aeromancer is able to target an enemy with a whip-like tendril of "
        "electrical energy that damage hit, spell, and stamina points. The "
        "whip is 'vampiric' in nature and the damage done in turn restores "
        "the caster's vitals.");

    addPrerequisite("/guilds/aeromancer/lightning/root.c",
        (["type":"research"]));

    addPrerequisite("level", 
        (["type": "level", 
          "guild": "aeromancer",
          "value": 3 ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 25);

    addSpecification("siphon hit points", ({ ([
            "probability": 100,
            "base damage": 5,
            "range": 15
        ]),
    }));
    addSpecification("siphon spell points", ({ ([
            "probability": 100,
            "base damage": 5,
            "range": 15
        ]),
    }));
    addSpecification("siphon stamina points", ({ ([
            "probability": 100,
            "base damage": 5,
            "range": 15
        ]),
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

    addSpecification("cooldown", 20);
    addSpecification("event handler", "shockingLashEvent");
    addSpecification("command template", "shocking lash [at ##Target##]");
    addSpecification("use ability message",  "##InitiatorName## "
        "##Infinitive::utter## words of power and a whip-like tendril "
        "of electricity erupts from ##InitiatorPossessive## "
        "##InitiatorWeapon## into ##TargetName##.");
}
