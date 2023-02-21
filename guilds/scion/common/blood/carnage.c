//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

protected string WeaponType = "ERROR";
protected string WeaponSkill = "unarmed";
protected string *ValidWeaponTypes = ({ });

/////////////////////////////////////////////////////////////////////////////
protected void SetupResearch()
{
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Carnage");
    addSpecification("source", "Scion of Dhuras Guild");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the carnage technique. By means of this, the "
        "Scion is able to use their weapon as a conduit for emitting a searing "
        "wave of negative energy at a foe.");
    SetupResearch();

    addPrerequisite(sprintf("/guilds/scion/paths/%s/root.c", WeaponType),
        (["type":"research"]));
    addPrerequisite(sprintf("/guilds/scion/paths/%s/blood/sanguine-blast.c", WeaponType),
        (["type":"research"]));
    addPrerequisite("level",
        (["type":"level",
            "guild": "Scion of Dhuras",
            "value": 29
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 200);
    addSpecification("spell point cost modifiers", ([
        sprintf("/guilds/scion/paths/%s/blood/scions-reserve.c", WeaponType): 10,
        sprintf("/guilds/scion/paths/%s/blood/scions-call.c", WeaponType): 10,
        sprintf("/guilds/scion/paths/%s/blood/scions-might.c", WeaponType): 10,
        sprintf("/guilds/scion/paths/%s/blood/scions-fury.c", WeaponType): 10,
    ]));

    addSpecification("damage hit points", ({ ([
            "probability":90,
            "base damage" : 100,
            "range" : 200
        ]),
        ([
            "probability":10,
            "base damage" : 200,
            "range" : 500
        ])
    }));
    addSpecification("damage spell points", ({ ([
            "probability":90,
            "base damage" : 50,
            "range" : 100
        ]),
        ([
            "probability": 10,
            "base damage": 100,
            "range" : 200
        ])
    }));

    addSpecification("damage type", "undead");

    addSpecification("modifiers", ({ 
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/blood/parasitic-charge.c", WeaponType),
            "name" : "Parasitic Charge",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.25
        ]),
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/blood/leechs-promise.c", WeaponType),
            "name" : "The Leech's Promise",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.25
        ]),
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/blood/enervation.c", WeaponType),
            "name" : "Enervation",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.25
        ]),
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/blood/malefic-discharge.c", WeaponType),
            "name" : "Malefic Discharge",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.35
        ]),
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/blood/crimson-eruption.c", WeaponType),
            "name" : "Crimson Eruption",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.4
        ]),
        ([
            "type": "research",
            "research item": sprintf("/guilds/scion/paths/%s/blood/metastasis.c", WeaponType),
            "name": "Metastasis",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": sprintf("/guilds/scion/paths/%s/blood/infectious-miasma.c", WeaponType),
            "name": "Infectious Miasma",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": sprintf("/guilds/scion/paths/%s/blood/septicemic-strike.c", WeaponType),
            "name": "Septicemic Strike",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": sprintf("/guilds/scion/paths/%s/blood/ulcerative-blight.c", WeaponType),
            "name": "Ulcerative Blight",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.5
        ]),
        ([
            "type": "weapon damage",
            "name" : WeaponSkill,
            "types" : ValidWeaponTypes,
            "formula" : "additive",
            "rate" : 1.0
        ]),
        ([
            "type":"skill",
            "name" : WeaponSkill,
            "formula" : "additive",
            "rate" : 0.05
        ]),
        ([
            "type":"skill",
            "name" : "blood",
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

    addSpecification("cooldown", 100);
    addSpecification("cooldown modifiers", ([
        sprintf("/guilds/scion/paths/%s/blood/scions-boon.c", WeaponType): 10,
        sprintf("/guilds/scion/paths/%s/blood/scions-finess.c", WeaponType): 10,
        sprintf("/guilds/scion/paths/%s/blood/scions-endurance.c", WeaponType): 10,
        sprintf("/guilds/scion/paths/%s/blood/scions-strength.c", WeaponType): 10,
    ]));

    addSpecification("event handler", "plasmaBallEvent");
    addSpecification("command template", "carnage [at ##Target##]");
    addSpecification("use ability message",  "A powerful, churning wave "
        "of lurid energy erupts from ##InitiatorPossessive::Name## "
        "##InitiatorWeapon## and flies into ##TargetName##.");
}
