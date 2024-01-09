//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

protected string WeaponType = "ERROR";
protected string WeaponSkill = "unarmed";

/////////////////////////////////////////////////////////////////////////////
protected void SetupResearch()
{
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Raging Tempest");
    addSpecification("source", "Scion of Dhuras Guild");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the tempest technique. By means of this, the "
        "Scion is able to use their weapon as a conduit for emitting a "
        "powerful magical storm that harries a foe.");
    SetupResearch();

    addPrerequisite(sprintf("/guilds/scion/paths/%s/root.c", WeaponType),
        (["type":"research"]));
    addPrerequisite(sprintf("/guilds/scion/paths/%s/evocation/magical-barrier.c", WeaponType),
        (["type":"research"]));
    addPrerequisite("level",
        (["type":"level",
            "guild": "Scion of Dhuras",
            "value": 33
        ]));

    addSpecification("modifiers", ({ 
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/evocation/static-barrier.c", WeaponType),
            "name" : "Static Barrier",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.25
        ]),
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/evocation/kinetic-barrier.c", WeaponType),
            "name" : "Kinetic Barrier",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.25
        ]),
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/evocation/energy-barrier.c", WeaponType),
            "name" : "Energy Barrier",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.5
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

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 240);
    addSpecification("spell point cost", 175);
    addSpecification("duration", 90);
    addSpecification("event handler", "tempestEvent");
    addSpecification("command template", "tempest [at ##Target##]");
    addSpecification("penalty to resist energy", 50);
    addSpecification("penalty to resist physical", 25);
    addSpecification("apply enfeebled", 1);
    addSpecification("apply slow", 1);

    addSpecification("use ability message", "A wave of plasma and piercing energy erupts "
        "from ##InitiatorPossessive::Name## ##InitiatorWeapon## and engulfs "
        "##TargetName##.");
}
