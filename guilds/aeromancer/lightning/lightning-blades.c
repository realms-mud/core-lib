//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Lightning Blades");
    addSpecification("source", "aeromancer");

    addSpecification("description", "This provides the user with the ability "
        "to call forth two claw-like, three foot arcs of electrical energy "
        "that sweep out with the same motion as your weapon to attack a foe.");

    addPrerequisite("level", 
        (["type": "level", 
          "guild": "aeromancer",
          "value": 9 ]));

    addPrerequisite("/guilds/aeromancer/lightning/root.c",
        (["type":"research"]));

    addSpecification("modifiers", ({ 
        ([
            "type":"research",
            "research item": "/guilds/aeromancer/lightning/discharge.c",
            "name" : "discharge",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.25
        ]),
        ([
            "type":"research",
            "research item": "/guilds/aeromancer/lightning/electrostatics.c",
            "name": "electrostatics",
            "formula": "multiplicative",
            "base value" : 1,
            "rate": 1.25
        ]),
        ([
            "type":"research",
            "research item": "/guilds/aeromancer/lightning/ionization.c",
            "name" : "ionization",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.25
        ]),
        ([
            "type":"research",
            "research item": "/guilds/aeromancer/lightning/enhanced-discharge.c",
            "name": "enhanced-discharge",
            "formula": "multiplicative",
            "base value" : 1,
            "rate": 1.25
        ]),
        ([
            "type":"research",
            "research item": "/guilds/aeromancer/lightning/electrostatic-induction.c",
            "name" : "electrostatic-induction",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.25
        ]),
        ([
            "type":"research",
            "research item": "/guilds/aeromancer/lightning/enhanced-conductivity.c",
            "name": "enhanced-conductivity",
            "formula": "multiplicative",
            "base value" : 1,
            "rate": 1.25
        ]),
        ([
            "type":"research",
            "research item": "/guilds/aeromancer/lightning/electrostatic-condenser.c",
            "name" : "electrostatic-condenser",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.25
        ]),
        ([
            "type":"research",
            "research item": "/guilds/aeromancer/lightning/corona-discharge.c",
            "name": "corona-discharge",
            "formula": "multiplicative",
            "base value" : 1,
            "rate": 1.25
        ]),
        ([
            "type":"research",
            "research item": "/guilds/aeromancer/lightning/plasma-eruption.c",
            "name" : "plasma-eruption",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.25
        ]),
        ([
            "type":"research",
            "research item": "/guilds/aeromancer/lightning/flux-condenser.c",
            "name": "flux-condenser",
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

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 30);

    addSpecification("spell point cost", 50);

    addSpecification("bonus attack", 10);
    addSpecification("bonus electricity attack", 10);
    addSpecification("bonus electricity attack", 10);
    addSpecification("duration", 2);

    addSpecification("event handler", "lightningBladesEvent");
    addSpecification("command template", "lightning blades");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::raise## ##InitiatorPossessive## hand and "
        "##Infinitive::say## a word of power. Two blades of electrical "
        "energy jut out of ##InitiatorPossessive## hand.");
}
