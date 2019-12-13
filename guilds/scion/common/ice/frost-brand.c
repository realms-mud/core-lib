//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

protected string WeaponType = "ERROR";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
}

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        sustainedResearchItem::reset(arg);
        addSpecification("name", "Frost Brand");
        addSpecification("source", "Scion of Dhuras Guild");
        addSpecification("description", "This research provides the user with the "
            "knowledge of the frost brand technique. By means of this, the "
            "Scion is able to emit frigid energy from their "
            "weapon. Doing so is wearying and will decrease available stamina.");
        Setup();

        addPrerequisite(sprintf("lib/guilds/scion/paths/%s/root.c", WeaponType),
            (["type":"research"]));
        addPrerequisite(sprintf("lib/guilds/scion/paths/%s/ice/root.c", WeaponType),
            (["type":"research"]));

        addSpecification("modifiers", ({ 
            ([
                "type":"research",
                "research item": sprintf("lib/guilds/scion/paths/%s/ice/sweeping-frost.c", WeaponType),
                "name" : "sweeping frost",
                "formula" : "additive",
                "base value" : 2,
                "rate": 1.0
            ]),
            ([
                "type":"research",
                "research item": sprintf("lib/guilds/scion/paths/%s/ice/freezing-brand.c", WeaponType),
                "name" : "freezing brand",
                "formula" : "additive",
                "base value" : 2,
                "rate": 1.0
            ]),
            ([
                "type":"research",
                "research item": sprintf("lib/guilds/scion/paths/%s/ice/frigid-strike.c", WeaponType),
                "name" : "frigid strike",
                "formula" : "additive",
                "base value" : 2,
                "rate": 1.0
            ]),
            ([
                "type":"research",
                "research item": sprintf("lib/guilds/scion/paths/%s/ice/icy-edge.c", WeaponType),
                "name" : "icy edge",
                "formula" : "additive",
                "base value" : 2,
                "rate": 1.0
            ]),
            ([
                "type":"research",
                "research item": sprintf("lib/guilds/scion/paths/%s/ice/winters-boon.c", WeaponType),
                "name" : "Winter's Boon",
                "formula" : "additive",
                "base value" : 5,
                "rate": 1.0
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
}
