//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
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
    addSpecification("name", "Malefic Strike");
    addSpecification("source", "Scion of Dhuras");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the malefic strike technique. By means of this, the "
        "Scion is able to emit a strong, constant negative energy current "
        "from their weapon. Doing so is wearying and will decrease "
        "available stamina.");
    SetupResearch();

    addPrerequisite(sprintf("/guilds/scion/paths/%s/root.c", WeaponType),
        (["type":"research"]));
    addPrerequisite(sprintf("/guilds/scion/paths/%s/blood/shockstrike.c", WeaponType),
        (["type":"research"]));
    addPrerequisite("level",
        (["type":"level",
            "guild": "Scion of Dhuras",
            "value": 25
        ]));

    addSpecification("modifiers", ({ 
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/blood/sweeping-torment.c", WeaponType),
            "name" : "Sweeping Torment",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.3
        ]),
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/blood/soul-brand.c", WeaponType),
            "name" : "Soul Brand",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.3
        ]),
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/blood/scourge-strike.c", WeaponType),
            "name" : "Scourge Strike",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.3
        ]),
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/blood/wicked-edge.c", WeaponType),
            "name" : "Wicked Edge",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.3
        ]),
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/blood/tortured-curse.c", WeaponType),
            "name" : "Tortured Curse",
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
    addSpecification("command template", "malefic strike");
    addSpecification("bonus undead enchantment", 10);
    addSpecification("bonus resist magical", 25);

    addSpecification("use ability activate message", "Crawling tendrils of "
        "garish energy wrap around ##InitiatorPossessive::Name## ##InitiatorWeapon##.");
    addSpecification("use ability deactivate message", "The tendrils of "
        "garish energy around ##InitiatorPossessive::Name## ##InitiatorWeapon## subside.");
}
