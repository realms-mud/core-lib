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
        addSpecification("name", "Glacial Brand");
        addSpecification("source", "Scion of Dhuras Guild");
        addSpecification("description", "This research provides the user with the "
            "knowledge of the glacial brand technique. By means of this, the "
            "Scion is able to emit a strong, constant frigid energy from their "
            "weapon. Doing so is wearying and will decrease available stamina.");
        Setup();

        addPrerequisite(sprintf("guilds/scion/paths/%s/root.c", WeaponType),
            (["type":"research"]));
        addPrerequisite(sprintf("guilds/scion/paths/%s/ice/frost-brand.c", WeaponType),
            (["type":"research"]));
        addPrerequisite("level",
            (["type":"level",
                "guild": "Scion of Dhuras",
                "value": 25
            ]));

        addSpecification("modifiers", ({ 
            ([
                "type":"research",
                "research item": sprintf("guilds/scion/paths/%s/ice/sweeping-frost.c", WeaponType),
                "name" : "sweeping frost",
                "formula" : "additive",
                "base value" : 3,
                "rate": 1.0
            ]),
            ([
                "type":"research",
                "research item": sprintf("guilds/scion/paths/%s/ice/freezing-brand.c", WeaponType),
                "name" : "freezing brand",
                "formula" : "additive",
                "base value" : 3,
                "rate": 1.0
            ]),
            ([
                "type":"research",
                "research item": sprintf("guilds/scion/paths/%s/ice/frigid-strike.c", WeaponType),
                "name" : "frigid strike",
                "formula" : "additive",
                "base value" : 3,
                "rate": 1.0
            ]),
            ([
                "type":"research",
                "research item": sprintf("guilds/scion/paths/%s/ice/icy-edge.c", WeaponType),
                "name" : "icy edge",
                "formula" : "additive",
                "base value" : 3,
                "rate": 1.0
            ]),
            ([
                "type":"research",
                "research item": sprintf("guilds/scion/paths/%s/ice/winters-boon.c", WeaponType),
                "name" : "Winter's Boon",
                "formula" : "additive",
                "base value" : 5,
                "rate": 1.0
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
}
