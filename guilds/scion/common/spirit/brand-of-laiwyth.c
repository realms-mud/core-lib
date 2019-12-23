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
        addSpecification("name", "Brand of Laiwyth");
        addSpecification("source", "Scion of Dhuras Guild");
        addSpecification("description", "This research provides the user with the "
            "knowledge of the Brand of Laiwyth technique. By means of this, the "
            "Scion is able to emit a strong, constant frigid energy from their "
            "weapon. Doing so is wearying and will decrease available stamina.");
        Setup();

        addPrerequisite(sprintf("guilds/scion/paths/%s/root.c", WeaponType),
            (["type":"research"]));
        addPrerequisite(sprintf("guilds/scion/paths/%s/spirit/soul-brand.c", WeaponType),
            (["type":"research"]));
        addPrerequisite("level",
            (["type":"level",
                "guild": "Scion of Dhuras",
                "value": 25
            ]));

        addSpecification("modifiers", ({ 
            ([
                "type":"research",
                "research item": sprintf("guilds/scion/paths/%s/spirit/sweeping-caress.c", WeaponType),
                "name" : "sweeping caress",
                "formula" : "additive",
                "base value" : 3,
                "rate": 1.0
            ]),
            ([
                "type":"research",
                "research item": sprintf("guilds/scion/paths/%s/spirit/spectral-brand.c", WeaponType),
                "name" : "freezing brand",
                "formula" : "additive",
                "base value" : 3,
                "rate": 1.0
            ]),
            ([
                "type":"research",
                "research item": sprintf("guilds/scion/paths/%s/spirit/soul-strike.c", WeaponType),
                "name" : "soul strike",
                "formula" : "additive",
                "base value" : 3,
                "rate": 1.0
            ]),
            ([
                "type":"research",
                "research item": sprintf("guilds/scion/paths/%s/spirit/spectral-edge.c", WeaponType),
                "name" : "spectral edge",
                "formula" : "additive",
                "base value" : 3,
                "rate": 1.0
            ]),
            ([
                "type":"research",
                "research item": sprintf("guilds/scion/paths/%s/spirit/nienwyns-boon.c", WeaponType),
                "name" : "Nienwyn's Boon",
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
        addSpecification("command template", "brand of laiwyth");
        addSpecification("bonus magical enchantment", 10);
        addSpecification("bonus resist magical", 25);

        addSpecification("use ability activate message", "Crawling tendrils of "
            "white mist wrap around ##InitiatorPossessive::Name## ##InitiatorWeapon##.");
        addSpecification("use ability deactivate message", "The tendrils of "
            "mist around ##InitiatorPossessive::Name## ##InitiatorWeapon## subside.");
    }
}
