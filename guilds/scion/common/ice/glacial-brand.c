//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
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
    addSpecification("name", "Glacial Brand");
    addSpecification("source", "Scion of Dhuras Guild");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the glacial brand technique. By means of this, the "
        "Scion is able to emit a strong, constant frigid energy from their "
        "weapon. Doing so is wearying and will decrease available stamina.");
    SetupResearch();

    addPrerequisite(sprintf("/guilds/scion/paths/%s/root.c", WeaponType),
        (["type":"research"]));
    addPrerequisite(sprintf("/guilds/scion/paths/%s/ice/frost-brand.c", WeaponType),
        (["type":"research"]));
    addPrerequisite("level",
        (["type":"level",
            "guild": "Scion of Dhuras",
            "value": 25
        ]));

    addSpecification("modifiers", ({ 
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/ice/sweeping-frost.c", WeaponType),
            "name" : "Sweeping Frost",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.3
        ]),
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/ice/freezing-brand.c", WeaponType),
            "name" : "Freezing Brand",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.3
        ]),
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/ice/frigid-strike.c", WeaponType),
            "name" : "Frigid Strike",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.3
        ]),
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/ice/icy-edge.c", WeaponType),
            "name" : "Icy Edge",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.3
        ]),
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/ice/winters-boon.c", WeaponType),
            "name" : "Winter's Boon",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.75
        ]),
    }));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 180);
    addSpecification("spell point cost", 50);
    addSpecification("stamina point cost", 200);
    addSpecification("command template", "glacial brand");
    addSpecification("bonus cold enchantment", 10);
    addSpecification("bonus resist fire", 25);

    addSpecification("use ability activate message", "Crawling tendrils of "
        "ice wrap around ##InitiatorPossessive::Name## ##InitiatorWeapon##.");
    addSpecification("use ability deactivate message", "The tendrils of "
        "ice around ##InitiatorPossessive::Name## ##InitiatorWeapon## subside.");
}
