//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
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
    addSpecification("name", "Frost Wave");
    addSpecification("source", "Scion of Dhuras");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the frost wave technique. By means of this, the "
        "Scion is able to use their weapon as a conduit for emitting a blast "
        "of frigid mist at all foes in the area.");
    SetupResearch();

    addPrerequisite(sprintf("/guilds/scion/paths/%s/root.c", WeaponType),
        (["type":"research"]));
    addPrerequisite(sprintf("/guilds/scion/paths/%s/ice/ice-javelin.c", WeaponType),
        (["type":"research"]));
    addPrerequisite("level",
        (["type":"level",
            "guild": "Scion of Dhuras",
            "value": 17
        ]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 150);
    addSpecification("spell point cost modifiers", ([
        sprintf("/guilds/scion/paths/%s/ice/scions-reserve.c", WeaponType): 10,
        sprintf("/guilds/scion/paths/%s/ice/scions-call.c", WeaponType): 10,
        sprintf("/guilds/scion/paths/%s/ice/scions-might.c", WeaponType): 10,
        sprintf("/guilds/scion/paths/%s/ice/scions-fury.c", WeaponType): 10,
    ]));

    addSpecification("damage hit points", ({ ([
            "probability": 90,
            "base damage": 40,
            "range": 80
        ]),
        ([
            "probability": 10,
            "base damage": 80,
            "range": 160
        ])
    }));
    addSpecification("damage stamina points", ({ ([
            "probability": 90,
            "base damage": 20,
            "range": 40
        ]),
        ([
            "probability": 10,
            "base damage": 40,
            "range": 80
        ])
    }));

    addSpecification("damage type", "cold");

    addSpecification("modifiers", ({ 
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/ice/chill-the-blood.c", WeaponType),
            "name" : "Chill the Blood",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.25
        ]),
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/ice/freezing-mark.c", WeaponType),
            "name" : "Freezing Mark",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.25
        ]),
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/ice/winters-rage.c", WeaponType),
            "name" : "Winter's Rage",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.25
        ]),
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/ice/wind-chill.c", WeaponType),
            "name" : "Wind Chill",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.35
        ]),
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/ice/icy-mark.c", WeaponType),
            "name" : "Icy Mark",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.4
        ]),
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/ice/arctic-rage.c", WeaponType),
            "name" : "Arctic Rage",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.25
        ]),
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/ice/frigid-blast.c", WeaponType),
            "name" : "Frigid Blast",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.25
        ]),
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/ice/bitter-frost.c", WeaponType),
            "name" : "Bitter Frost",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.25
        ]),
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/ice/crushing-chill.c", WeaponType),
            "name" : "Crushing Chill",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.5
        ]),
        ([
            "type": "weapon damage",
            "name": WeaponSkill,
            "types": ValidWeaponTypes,
            "formula": "additive",
            "rate": 1.0
        ]),
        ([
            "type":"skill",
            "name" : WeaponSkill,
            "formula" : "additive",
            "rate" : 0.05
        ]),
        ([
            "type":"skill",
            "name" : "elemental water",
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
        sprintf("/guilds/scion/paths/%s/ice/scions-boon.c", WeaponType): 10,
        sprintf("/guilds/scion/paths/%s/ice/scions-finess.c", WeaponType): 10,
        sprintf("/guilds/scion/paths/%s/ice/scions-endurance.c", WeaponType): 10,
        sprintf("/guilds/scion/paths/%s/ice/scions-strength.c", WeaponType): 10,
    ]));

    addSpecification("event handler", "frostWaveEvent");
    addSpecification("command template", "frost wave");
    addSpecification("use ability message",  "An intense blast of frigid "
        " mist erupts from ##InitiatorPossessive::Name## ##InitiatorWeapon##.");
}
