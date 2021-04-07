//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

protected string WeaponType = "ERROR";

/////////////////////////////////////////////////////////////////////////////
protected void SetupResearch()
{
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Soul Strike");
    addSpecification("source", "Scion of Dhuras Guild");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the soul strike technique. By means of this, the "
        "Scion is able to emit constant negative energy from their "
        "weapon. Doing so is wearying and will decrease available stamina.");
    SetupResearch();

    addPrerequisite(sprintf("guilds/scion/paths/%s/root.c", WeaponType),
        (["type":"research"]));
    addPrerequisite(sprintf("guilds/scion/paths/%s/blood/root.c", WeaponType),
        (["type":"research"]));

    addSpecification("modifiers", ({ 
        ([
            "type":"research",
            "research item": sprintf("guilds/scion/paths/%s/blood/sweeping-torment.c", WeaponType),
            "name" : "sweeping torment",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.67
        ]),
        ([
            "type":"research",
            "research item": sprintf("guilds/scion/paths/%s/blood/soul-brand.c", WeaponType),
            "name" : "soul brand",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.4
        ]),
        ([
            "type":"research",
            "research item": sprintf("guilds/scion/paths/%s/blood/scourge-strike.c", WeaponType),
            "name" : "scourge strike",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.4
        ]),
        ([
            "type":"research",
            "research item": sprintf("guilds/scion/paths/%s/blood/wicked-edge.c", WeaponType),
            "name" : "wicked edge",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.4
        ]),
        ([
            "type":"research",
            "research item": sprintf("guilds/scion/paths/%s/blood/tortured-curse.c", WeaponType),
            "name" : "tortured curse",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 2.0
        ]),
    }));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 4);
    addSpecification("spell point cost", 10);
    addSpecification("stamina point cost", 50);
    addSpecification("command template", "soul strike");
    addSpecification("bonus undead enchantment", 3);
    addSpecification("bonus resist magical", 3);

    addSpecification("use ability activate message", "Thin tendrils of "
        "crimson energy wrap around ##InitiatorPossessive::Name## "
        "##InitiatorWeapon##.");
    addSpecification("use ability deactivate message", "Thin tendrils of "
        "crimson energy around ##InitiatorPossessive::Name## "
        "##InitiatorWeapon## subside.");
}
