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
    addSpecification("name", "Energy Blast");
    addSpecification("source", "Scion of Dhuras");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the energy blast technique. By means of this, the "
        "Scion is able to use their weapon as a conduit for emitting a beam "
        "of deadly energy at a foe.");
    SetupResearch();

    addPrerequisite(sprintf("/guilds/scion/paths/%s/root.c", WeaponType),
        (["type":"research"]));
    addPrerequisite(sprintf("/guilds/scion/paths/%s/evocation/energy-shard.c", WeaponType),
        (["type":"research"]));
    addPrerequisite("level",
        (["type":"level",
            "guild": "Scion of Dhuras",
            "value": 9
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 100);
    addSpecification("spell point cost modifiers", ([
        sprintf("/guilds/scion/paths/%s/evocation/scions-reserve.c", WeaponType): 10,
        sprintf("/guilds/scion/paths/%s/evocation/scions-call.c", WeaponType): 10,
        sprintf("/guilds/scion/paths/%s/evocation/scions-might.c", WeaponType): 10,
        sprintf("/guilds/scion/paths/%s/evocation/scions-fury.c", WeaponType): 10,
    ]));

    addSpecification("damage hit points", ({ ([
            "probability":90,
            "base damage" : 25,
            "range" : 50
        ]),
        ([
            "probability": 10,
            "base damage": 50,
            "range" : 100
        ])
    }));

    addSpecification("damage type", "energy");

    addSpecification("modifiers", ({ 
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/evocation/mystic-charge.c", WeaponType),
            "name" : "Mystic Charge",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.25
        ]),
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/evocation/magical-conduit.c", WeaponType),
            "name" : "Magical Conduit",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.25
        ]),
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/evocation/ionization.c", WeaponType),
            "name" : "Ionization",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.25
        ]),
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/evocation/kinetic-discharge.c", WeaponType),
            "name" : "Kinetic Discharge",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.35
        ]),
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/evocation/plasma-eruption.c", WeaponType),
            "name" : "Plasma Eruption",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.4
        ]),
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/evocation/magical-condenser.c", WeaponType),
            "name" : "Magical Condenser",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": sprintf("/guilds/scion/paths/%s/evocation/magical-inductance.c", WeaponType),
            "name": "Magical Inductance",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/evocation/kinetic-blast.c", WeaponType),
            "name" : "Kinetic Blast",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.25
        ]),
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/evocation/plasma-condenser.c", WeaponType),
            "name" : "Plasma Condenser",
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
            "name" : "evocation",
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

    addSpecification("cooldown", 60);
    addSpecification("cooldown modifiers", ([
        sprintf("/guilds/scion/paths/%s/evocation/scions-boon.c", WeaponType): 10,
        sprintf("/guilds/scion/paths/%s/evocation/scions-finess.c", WeaponType): 10,
        sprintf("/guilds/scion/paths/%s/evocation/scions-endurance.c", WeaponType): 10,
        sprintf("/guilds/scion/paths/%s/evocation/scions-strength.c", WeaponType): 10,
    ]));

    addSpecification("event handler", "energyBlastEvent");
    addSpecification("command template", "energy blast [at ##Target##]");
    addSpecification("use ability message",  "An intense beam of energy "
        "flies from ##InitiatorPossessive::Name## ##InitiatorWeapon## into ##TargetName##.");
}
