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
    addSpecification("name", "Soul Spike");
    addSpecification("source", "Scion of Dhuras");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the soul spike technique. By means of this, the "
        "Scion is able to use their weapon as a conduit for emitting a negative energy "
        "discharge at a foe.");
    SetupResearch();

    addPrerequisite(sprintf("/guilds/scion/paths/%s/root.c", WeaponType),
        (["type":"research"]));
    addPrerequisite(sprintf("/guilds/scion/paths/%s/blood/root.c", WeaponType),
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
    addSpecification("damage type", "undead");

    addSpecification("modifiers", ({ 
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/blood/parasitic-charge.c", WeaponType),
            "name" : "Parasitic Charge",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.5
        ]),
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/blood/leechs-promise.c", WeaponType),
            "name" : "The Leech's Promise",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 2.0
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

    addSpecification("cooldown", 4);
    addSpecification("event handler", "soulSpikeEvent");
    addSpecification("command template", "soul spike [at ##Target##]");
    addSpecification("use ability message",  "A fog of sickly purple hue "
        "flies from ##InitiatorPossessive::Name## ##InitiatorWeapon## "
        "into ##TargetName##.");
}
