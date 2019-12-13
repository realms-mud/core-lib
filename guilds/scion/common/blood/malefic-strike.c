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
        addSpecification("name", "Malefic Strike");
        addSpecification("source", "Scion of Dhuras Guild");
        addSpecification("description", "This research provides the user with the "
            "knowledge of the malefic strike technique. By means of this, the "
            "Scion is able to emit a strong, constant negative energy current "
            "from their weapon. Doing so is wearying and will decrease "
            "available stamina.");
        Setup();

        addPrerequisite(sprintf("lib/guilds/scion/paths/%s/root.c", WeaponType),
            (["type":"research"]));
        addPrerequisite(sprintf("lib/guilds/scion/paths/%s/blood/shockstrike.c", WeaponType),
            (["type":"research"]));
        addPrerequisite("level",
            (["type":"level",
                "guild": "Scion of Dhuras",
                "value": 25
            ]));

        addSpecification("modifiers", ({ 
            ([
                "type":"research",
                "research item": sprintf("lib/guilds/scion/paths/%s/blood/sweeping-torment.c", WeaponType),
                "name" : "sweeping torment",
                "formula" : "additive",
                "base value" : 2,
                "rate": 1.0
            ]),
            ([
                "type":"research",
                "research item": sprintf("lib/guilds/scion/paths/%s/blood/soul-brand.c", WeaponType),
                "name" : "soul brand",
                "formula" : "additive",
                "base value" : 2,
                "rate": 1.0
            ]),
            ([
                "type":"research",
                "research item": sprintf("lib/guilds/scion/paths/%s/blood/scourge-strike.c", WeaponType),
                "name" : "scourge strike",
                "formula" : "additive",
                "base value" : 2,
                "rate": 1.0
            ]),
            ([
                "type":"research",
                "research item": sprintf("lib/guilds/scion/paths/%s/blood/wicked-edge.c", WeaponType),
                "name" : "wicked edge",
                "formula" : "additive",
                "base value" : 2,
                "rate": 1.0
            ]),
            ([
                "type":"research",
                "research item": sprintf("lib/guilds/scion/paths/%s/blood/tortured-curse.c", WeaponType),
                "name" : "tortured curse",
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
        addSpecification("command template", "malefic strike");
        addSpecification("bonus undead enchantment", 10);
        addSpecification("bonus resist magical", 25);

        addSpecification("use ability activate message", "Crawling tendrils of "
            "garish energy wrap around ##InitiatorPossessive::Name## ##InitiatorWeapon##.");
        addSpecification("use ability deactivate message", "The tendrils of "
            "garish energy around ##InitiatorPossessive::Name## ##InitiatorWeapon## subside.");
    }
}
