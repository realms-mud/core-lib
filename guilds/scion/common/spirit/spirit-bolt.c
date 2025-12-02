//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
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
    addSpecification("name", "Spirit Bolt");
    addSpecification("source", "Scion of Dhuras");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the spirit bolt technique. By means of this, the "
        "Scion is able to use their weapon as a conduit for emitting a spirit-damaging "
        "discharge at a foe.");
    SetupResearch();

    addPrerequisite(sprintf("/guilds/scion/paths/%s/root.c", WeaponType),
        (["type":"research"]));
    addPrerequisite(sprintf("/guilds/scion/paths/%s/spirit/root.c", WeaponType),
        (["type":"research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 10);

    addSpecification("damage hit points", ({ ([
            "probability": 80,
            "base damage": 5,
            "range": 10
        ]),
        ([
            "probability": 20,
            "base damage": 10,
            "range": 20
        ])
    }));
    addSpecification("damage type", "magical");

    addSpecification("modifiers", ({ 
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/spirit/chill-the-blood.c", WeaponType),
            "name" : "Chill the Blood",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.5
        ]),
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/spirit/spirit-mark.c", WeaponType),
            "name" : "Spirit Mark",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 2.0
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
            "name" : "spirit",
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

    addSpecification("cooldown", 6);
    addSpecification("event handler", "spiritBoltEvent");
    addSpecification("command template", "spirit bolt [at ##Target##]");
    addSpecification("use ability message",  "Small shards of crimson energy "
        "fly from ##InitiatorPossessive::Name## "
        "##InitiatorWeapon## into ##TargetName##.");
}
