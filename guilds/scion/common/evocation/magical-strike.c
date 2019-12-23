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
        addSpecification("name", "Magical Strike");
        addSpecification("source", "Scion of Dhuras Guild");
        addSpecification("description", "This research provides the user with the "
            "knowledge of the magical strike technique. By means of this, the "
            "Scion is able to emit a constant magical current from their "
            "weapon. Doing so is wearying and will decrease available stamina.");
        Setup();

        addPrerequisite(sprintf("guilds/scion/paths/%s/root.c", WeaponType),
            (["type":"research"]));
        addPrerequisite(sprintf("guilds/scion/paths/%s/evocation/root.c", WeaponType),
            (["type":"research"]));

        addSpecification("modifiers", ({ 
            ([
                "type":"research",
                "research item": sprintf("guilds/scion/paths/%s/evocation/sweeping-energy.c", WeaponType),
                "name" : "sweeping energy",
                "formula" : "additive",
                "base value" : 2,
                "rate": 1.0
            ]),
            ([
                "type":"research",
                "research item": sprintf("guilds/scion/paths/%s/evocation/mystic-brand.c", WeaponType),
                "name" : "mystic brand",
                "formula" : "additive",
                "base value" : 2,
                "rate": 1.0
            ]),
            ([
                "type":"research",
                "research item": sprintf("guilds/scion/paths/%s/evocation/energized-strike.c", WeaponType),
                "name" : "energized strike",
                "formula" : "additive",
                "base value" : 2,
                "rate": 1.0
            ]),
            ([
                "type":"research",
                "research item": sprintf("guilds/scion/paths/%s/evocation/magical-edge.c", WeaponType),
                "name" : "shocking edge",
                "formula" : "additive",
                "base value" : 2,
                "rate": 1.0
            ]),
            ([
                "type":"research",
                "research item": sprintf("guilds/scion/paths/%s/evocation/dalreths-might.c", WeaponType),
                "name" : "Dalreth's Might",
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
}
