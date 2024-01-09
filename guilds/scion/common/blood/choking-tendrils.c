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
    addSpecification("name", "Choking Tendrils");
    addSpecification("source", "Scion of Dhuras Guild");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the choking tendrils technique. By means of this, the "
        "Scion is able to use their weapon as a conduit for emitting negative energy "
        "energy that swarms around a foe.");
    SetupResearch();

    addPrerequisite(sprintf("/guilds/scion/paths/%s/root.c", WeaponType),
        (["type":"research"]));
    addPrerequisite(sprintf("/guilds/scion/paths/%s/blood/soulstrike.c", WeaponType),
        (["type":"research"]));
    addPrerequisite("level",
        (["type":"level",
            "guild": "Scion of Dhuras",
            "value": 5
        ]));

    addSpecification("modifiers", ({ 
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/blood/malefic-barrier.c", WeaponType),
            "name" : "Malefic Barrier",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.25
        ]),
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/blood/corrupting-barrier.c", WeaponType),
            "name" : "Corrupting Barrier",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.25
        ]),
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/blood/nefarious-barrier.c", WeaponType),
            "name" : "Nefarious Barrier",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.25
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
            "type":"skill",
            "name" : "spellcraft",
            "formula" : "logarithmic",
            "rate" : 1.10
        ]),
        ([
            "type":"level",
            "name" : "level",
            "formula" : "logarithmic",
            "rate" : 1.10
        ]),
        ([
            "type":"attribute",
            "name" : "intelligence",
            "formula" : "additive",
            "rate" : 0.05
        ]) 
    }));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 120);
    addSpecification("duration", 60);
    addSpecification("spell point cost", 35);
    addSpecification("event handler", "chokingTendrilsEvent");
    addSpecification("command template", "choking tendrils [at ##Target##]");
    addSpecification("penalty to resist evil", 10);
    addSpecification("penalty to resist physical", 5);

    addSpecification("use ability message", "Sinuous tendrils of "
        "black energy spray from ##InitiatorPossessive::Name## "
        "##InitiatorWeapon##, engulfing ##TargetName##.");
}
