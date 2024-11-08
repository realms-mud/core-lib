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
    addSpecification("name", "Searing Brand");
    addSpecification("source", "Scion of Dhuras");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the searing brand technique. By means of this, the "
        "Scion is able to emit a strong, constant fiery current from their "
        "weapon. Doing so is wearying and will decrease available stamina.");
    SetupResearch();

    addPrerequisite(sprintf("/guilds/scion/paths/%s/root.c", WeaponType),
        (["type":"research"]));
    addPrerequisite(sprintf("/guilds/scion/paths/%s/flame/fire-brand.c", WeaponType),
        (["type":"research"]));
    addPrerequisite("level",
        (["type":"level",
            "guild": "Scion of Dhuras",
            "value": 25
        ]));

    addSpecification("modifiers", ({ 
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/flame/sweeping-flames.c", WeaponType),
            "name" : "Sweeping Flames",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.3
        ]),
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/flame/burning-brand.c", WeaponType),
            "name" : "Burning Brand",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.3
        ]),
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/flame/inferno-strike.c", WeaponType),
            "name" : "Inferno Strike",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.3
        ]),
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/flame/blazing-edge.c", WeaponType),
            "name" : "blazing edge",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.3
        ]),
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/flame/ferianths-boon.c", WeaponType),
            "name" : "Ferianth's Boon",
            "formula" : "multiplicative",
            "base value": 1,
            "rate": 1.75
        ]),
    }));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 180);
    addSpecification("spell point cost", 50);
    addSpecification("stamina point cost", 200);
    addSpecification("command template", "searing brand");
    addSpecification("bonus fire enchantment", 10);
    addSpecification("bonus resist fire", 25);

    addSpecification("use ability activate message", "Crawling tendrils of "
        "flame wrap around ##InitiatorPossessive::Name## ##InitiatorWeapon##.");
    addSpecification("use ability deactivate message", "The tendrils of "
        "flame around ##InitiatorPossessive::Name## ##InitiatorWeapon## subside.");
}
