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
    addSpecification("name", "Magical Strike");
    addSpecification("source", "Scion of Dhuras");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the magical strike technique. By means of this, the "
        "Scion is able to emit a constant magical current from their "
        "weapon. Doing so is wearying and will decrease available stamina.");
    SetupResearch();

    addPrerequisite(sprintf("/guilds/scion/paths/%s/root.c", WeaponType),
        (["type":"research"]));
    addPrerequisite(sprintf("/guilds/scion/paths/%s/evocation/root.c", WeaponType),
        (["type":"research"]));

    addSpecification("modifiers", ({ 
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/evocation/sweeping-energy.c", WeaponType),
            "name" : "sweeping energy",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.67
        ]),
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/evocation/mystic-brand.c", WeaponType),
            "name" : "mystic brand",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.4
        ]),
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/evocation/energized-strike.c", WeaponType),
            "name" : "energized strike",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.4
        ]),
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/evocation/magical-edge.c", WeaponType),
            "name" : "shocking edge",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.4
        ]),
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/evocation/dalreths-might.c", WeaponType),
            "name" : "Dalreth's Might",
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
    addSpecification("command template", "magical strike");

    addSpecification("bonus magical enchantment", 3);
    addSpecification("bonus resist magical", 3);

    addSpecification("use ability activate message", "Thin tendrils of "
        "magical energy wrap around ##InitiatorPossessive::Name## "
        "##InitiatorWeapon##.");
    addSpecification("use ability deactivate message", "The thin tendrils of "
        "magical energy around ##InitiatorPossessive::Name## "
        "##InitiatorWeapon## subside.");
}
