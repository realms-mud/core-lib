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
    addSpecification("name", "Fire Brand");
    addSpecification("source", "Scion of Dhuras Guild");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the fire brand technique. By means of this, the "
        "Scion is able to emit flaming energy from their "
        "weapon. Doing so is wearying and will decrease available stamina.");
    SetupResearch();

    addPrerequisite(sprintf("/guilds/scion/paths/%s/root.c", WeaponType),
        (["type":"research"]));
    addPrerequisite(sprintf("/guilds/scion/paths/%s/flame/root.c", WeaponType),
        (["type":"research"]));

    addSpecification("modifiers", ({ 
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/flame/sweeping-flames.c", WeaponType),
            "name" : "sweeping flames",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.67
        ]),
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/flame/burning-brand.c", WeaponType),
            "name" : "burning brand",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.4
        ]),
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/flame/inferno-strike.c", WeaponType),
            "name" : "inferno strike",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.4
        ]),
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/flame/blazing-edge.c", WeaponType),
            "name" : "blazing edge",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.4
        ]),
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/flame/ferianths-boon.c", WeaponType),
            "name" : "Ferianth's Boon",
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
    addSpecification("command template", "fire brand");

    addSpecification("bonus fire enchantment", 3);
    addSpecification("bonus resist fire", 3);

    addSpecification("use ability activate message", "Thin tendrils of "
        "fire wrap around ##InitiatorPossessive::Name## "
        "##InitiatorWeapon##.");
    addSpecification("use ability deactivate message", "The thin tendrils of "
        "fire around ##InitiatorPossessive::Name## "
        "##InitiatorWeapon## subside.");
}
