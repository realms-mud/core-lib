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
    addSpecification("name", "Shocking Barrier");
    addSpecification("source", "Scion of Dhuras Guild");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the shocking barrier technique. By means of this, the "
        "Scion is able to use their weapon as a conduit for emitting electric "
        "energy that swarms around and harries a foe.");
    SetupResearch();

    addPrerequisite(sprintf("/guilds/scion/paths/%s/root.c", WeaponType),
        (["type":"research"]));
    addPrerequisite(sprintf("/guilds/scion/paths/%s/electricity/shocking-tendrils.c", WeaponType),
        (["type":"research"]));
    addPrerequisite("level",
        (["type":"level",
            "guild": "Scion of Dhuras",
            "value": 13
        ]));

    addSpecification("modifiers", ({ 
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/electricity/static-barrier.c", WeaponType),
            "name" : "Static Barrier",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.25
        ]),
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/electricity/ionized-barrier.c", WeaponType),
            "name" : "Ionized Barrier",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.25
        ]),
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/electricity/plasma-barrier.c", WeaponType),
            "name" : "Plasma Barrier",
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
            "name" : "elemental air",
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
    addSpecification("spell point cost", 75);
    addSpecification("event handler", "shockingBarrierEvent");
    addSpecification("command template", "shocking barrier [at ##Target##]");
    addSpecification("penalty to resist electricity", 10);
    addSpecification("penalty to resist physical", 10);
    addSpecification("apply enfeebled", 1);

    addSpecification("use ability message", "A wave of electricity flies "
        "from ##InitiatorPossessive::Name## ##InitiatorWeapon## and engulfs "
        "##TargetName##.");
}
