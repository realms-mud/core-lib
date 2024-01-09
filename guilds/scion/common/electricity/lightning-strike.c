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
    addSpecification("name", "Lightning Strike");
    addSpecification("source", "Scion of Dhuras Guild");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the lightning strike technique. By means of this, the "
        "Scion is able to emit a strong, constant electrical current from their "
        "weapon. Doing so is wearying and will decrease available stamina.");
    SetupResearch();

    addPrerequisite(sprintf("/guilds/scion/paths/%s/root.c", WeaponType),
        (["type":"research"]));
    addPrerequisite(sprintf("/guilds/scion/paths/%s/electricity/shockstrike.c", WeaponType),
        (["type":"research"]));
    addPrerequisite("level",
        (["type":"level",
            "guild": "Scion of Dhuras",
            "value": 25
        ]));

    addSpecification("modifiers", ({ 
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/electricity/sweeping-shock.c", WeaponType),
            "name" : "Sweeping Shock",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.3
        ]),
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/electricity/shock-brand.c", WeaponType),
            "name" : "Shock Brand",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.3
        ]),
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/electricity/energized-strike.c", WeaponType),
            "name" : "Energized Strike",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.3
        ]),
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/electricity/shocking-edge.c", WeaponType),
            "name" : "shocking edge",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.3
        ]),
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/electricity/thunders-boon.c", WeaponType),
            "name" : "Thunder's Boon",
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
    addSpecification("command template", "lightning strike");
    addSpecification("bonus electricity enchantment", 10);
    addSpecification("bonus resist electricity", 25);

    addSpecification("use ability activate message", "Crawling tendrils of "
        "lightning wrap around ##InitiatorPossessive::Name## ##InitiatorWeapon##.");
    addSpecification("use ability deactivate message", "The tendrils of "
        "lightning around ##InitiatorPossessive::Name## ##InitiatorWeapon## subside.");
}
