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
    addSpecification("name", "Soul Brand");
    addSpecification("source", "Scion of Dhuras Guild");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the soul brand technique. By means of this, the "
        "Scion is able to emit spirit-damaging energy from their "
        "weapon. Doing so is wearying and will decrease available stamina.");
    SetupResearch();

    addPrerequisite(sprintf("/guilds/scion/paths/%s/root.c", WeaponType),
        (["type":"research"]));
    addPrerequisite(sprintf("/guilds/scion/paths/%s/spirit/root.c", WeaponType),
        (["type":"research"]));

    addSpecification("modifiers", ({ 
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/spirit/sweeping-caress.c", WeaponType),
            "name" : "sweeping caress",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.67
        ]),
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/spirit/spectral-brand.c", WeaponType),
            "name" : "freezing brand",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.4
        ]),
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/spirit/soul-strike.c", WeaponType),
            "name" : "soul strike",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.4
        ]),
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/spirit/spectral-edge.c", WeaponType),
            "name" : "spectral edge",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.4
        ]),
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/spirit/nienwyns-boon.c", WeaponType),
            "name" : "Nienwyn's Boon",
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
    addSpecification("command template", "soul brand");

    addSpecification("bonus magical enchantment", 3);
    addSpecification("bonus resist magical", 3);

    addSpecification("use ability activate message", "Thin tendrils of "
        "wispy energy wrap around ##InitiatorPossessive::Name## "
        "##InitiatorWeapon##.");
    addSpecification("use ability deactivate message", "The thin tendrils of "
        "energy around ##InitiatorPossessive::Name## "
        "##InitiatorWeapon## subside.");
}
