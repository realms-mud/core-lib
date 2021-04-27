//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
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
    addSpecification("name", "Destruction");
    addSpecification("source", "Scion of Dhuras Guild");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the destruction technique. By means of this, the "
        "Scion is able to use their weapon as a conduit for sending waves "
        "of negative energy at all foes in the area.");
    SetupResearch();

    addPrerequisite(sprintf("/guilds/scion/paths/%s/root.c", WeaponType),
        (["type":"research"]));
    addPrerequisite(sprintf("/guilds/scion/paths/%s/blood/sanguine-blast.c", WeaponType),
        (["type":"research"]));
    addPrerequisite("level",
        (["type":"level",
            "guild": "Scion of Dhuras",
            "value": 37
        ]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 250);

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
            "rate" : 1.05
        ]),
        ([
            "type":"skill",
            "name" : "blood",
            "formula" : "additive",
            "rate" : 1.10
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
            "rate" : 1.10
        ]),
        ([
            "type": "skill",
            "name": "mathematics",
            "formula": "additive",
            "rate": 1.05
        ]),
        ([
            "type": "skill",
            "name": "chemistry",
            "formula": "additive",
            "rate": 1.05
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 1.05
        ]), 
        ([
            "type": "attribute",
            "name": "dexterity",
            "formula": "additive",
            "rate": 1.025
        ]), 
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 1.025
        ]), 
    }));

    addSpecification("cooldown", 180);
    addSpecification("event handler", "destructionEvent");
    addSpecification("command template", "destruction");
    addSpecification("use ability message",  "Intense waves of purple "
        "negative energy erupt from ##InitiatorPossessive::Name## ##InitiatorWeapon##.");
}
