//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
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
        addSpecification("name", "Searing Brand");
        addSpecification("source", "Scion of Dhuras Guild");
        addSpecification("description", "This research provides the user with the "
            "knowledge of the searing brand technique. By means of this, the "
            "Scion is able to emit a strong, constant electrical current from their "
            "weapon. Doing so is wearying and will decrease available stamina.");
        Setup();

        addPrerequisite(sprintf("lib/guilds/scion/paths/%s/root.c", WeaponType),
            (["type":"research"]));
        addPrerequisite(sprintf("lib/guilds/scion/paths/%s/flame/fire-brand.c", WeaponType),
            (["type":"research"]));
        addPrerequisite("level",
            (["type":"level",
                "guild": "Scion of Dhuras",
                "value": 25
            ]));

        addSpecification("modifiers", ({ 
            ([
                "type":"research",
                "research item": sprintf("lib/guilds/scion/paths/%s/flame/sweeping-shock.c", WeaponType),
                "name" : "sweeping shock",
                "formula" : "additive",
                "base value" : 3,
                "rate": 1.0
            ]),
            ([
                "type":"research",
                "research item": sprintf("lib/guilds/scion/paths/%s/flame/shock-brand.c", WeaponType),
                "name" : "shock brand",
                "formula" : "additive",
                "base value" : 3,
                "rate": 1.0
            ]),
            ([
                "type":"research",
                "research item": sprintf("lib/guilds/scion/paths/%s/flame/energized-strike.c", WeaponType),
                "name" : "energized strike",
                "formula" : "additive",
                "base value" : 3,
                "rate": 1.0
            ]),
            ([
                "type":"research",
                "research item": sprintf("lib/guilds/scion/paths/%s/flame/shocking-edge.c", WeaponType),
                "name" : "shocking edge",
                "formula" : "additive",
                "base value" : 3,
                "rate": 1.0
            ]),
            ([
                "type":"research",
                "research item": sprintf("lib/guilds/scion/paths/%s/flame/thunders-boon.c", WeaponType),
                "name" : "Thunder's Boon",
                "formula" : "additive",
                "base value" : 6,
                "rate": 1.0
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
}
