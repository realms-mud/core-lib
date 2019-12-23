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
        addSpecification("name", "Fire Brand");
        addSpecification("source", "Scion of Dhuras Guild");
        addSpecification("description", "This research provides the user with the "
            "knowledge of the fire brand technique. By means of this, the "
            "Scion is able to emit flaming energy from their "
            "weapon. Doing so is wearying and will decrease available stamina.");
        Setup();

        addPrerequisite(sprintf("guilds/scion/paths/%s/root.c", WeaponType),
            (["type":"research"]));
        addPrerequisite(sprintf("guilds/scion/paths/%s/flame/root.c", WeaponType),
            (["type":"research"]));

        addSpecification("modifiers", ({ 
            ([
                "type":"research",
                "research item": sprintf("guilds/scion/paths/%s/flame/sweeping-flames.c", WeaponType),
                "name" : "sweeping flames",
                "formula" : "additive",
                "base value" : 2,
                "rate": 1.0
            ]),
            ([
                "type":"research",
                "research item": sprintf("guilds/scion/paths/%s/flame/burning-brand.c", WeaponType),
                "name" : "burning brand",
                "formula" : "additive",
                "base value" : 2,
                "rate": 1.0
            ]),
            ([
                "type":"research",
                "research item": sprintf("guilds/scion/paths/%s/flame/inferno-strike.c", WeaponType),
                "name" : "inferno strike",
                "formula" : "additive",
                "base value" : 2,
                "rate": 1.0
            ]),
            ([
                "type":"research",
                "research item": sprintf("guilds/scion/paths/%s/flame/blazing-edge.c", WeaponType),
                "name" : "blazing edge",
                "formula" : "additive",
                "base value" : 2,
                "rate": 1.0
            ]),
            ([
                "type":"research",
                "research item": sprintf("guilds/scion/paths/%s/flame/ferianths-boon.c", WeaponType),
                "name" : "Ferianth's Boon",
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
        addSpecification("command template", "fire brand");

        addSpecification("bonus fire enchantment", 3);
        addSpecification("bonus resist fire", 3);

        addSpecification("use ability activate message", "Thin tendrils of "
            "fire wrap around ##InitiatorPossessive::Name## "
            "##InitiatorWeapon##.");
        addSpecification("use ability deactivate message", "The thin tendrils of "
            "fire around ##InitiatorPossessive::Name## "
            "##InitiatorWeapon## subside.");
    }
}
