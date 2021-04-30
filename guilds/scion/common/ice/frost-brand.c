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
    addSpecification("name", "Frost Brand");
    addSpecification("source", "Scion of Dhuras Guild");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the frost brand technique. By means of this, the "
        "Scion is able to emit frigid energy from their "
        "weapon. Doing so is wearying and will decrease available stamina.");
    SetupResearch();

    addPrerequisite(sprintf("/guilds/scion/paths/%s/root.c", WeaponType),
        (["type":"research"]));
    addPrerequisite(sprintf("/guilds/scion/paths/%s/ice/root.c", WeaponType),
        (["type":"research"]));

    addSpecification("modifiers", ({ 
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/ice/sweeping-frost.c", WeaponType),
            "name" : "Sweeping Frost",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.67
        ]),
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/ice/freezing-brand.c", WeaponType),
            "name" : "Freezing Brand",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.4
        ]),
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/ice/frigid-strike.c", WeaponType),
            "name" : "Frigid Strike",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.4
        ]),
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/ice/icy-edge.c", WeaponType),
            "name" : "Icy Edge",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.4
        ]),
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/ice/winters-boon.c", WeaponType),
            "name" : "Winter's Boon",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 2.0
        ]),
    }));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 30);
    addSpecification("spell point cost", 10);
    addSpecification("stamina point cost", 50);
    addSpecification("command template", "frost brand");

    addSpecification("bonus cold enchantment", 3);
    addSpecification("bonus resist cold", 3);

    addSpecification("use ability activate message", "Thin tendrils of "
        "wispy frost wrap around ##InitiatorPossessive::Name## "
        "##InitiatorWeapon##.");
    addSpecification("use ability deactivate message", "The thin tendrils of "
        "frost around ##InitiatorPossessive::Name## "
        "##InitiatorWeapon## subside.");
}
