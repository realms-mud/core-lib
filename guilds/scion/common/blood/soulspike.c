//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

protected string WeaponType = "ERROR";
protected string WeaponSkill = "unarmed";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
}

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        instantaneousActiveResearchItem::reset(arg);
        addSpecification("name", "Soul Spike");
        addSpecification("source", "Scion of Dhuras Guild");
        addSpecification("description", "This research provides the user with the "
            "knowledge of the soul spike technique. By means of this, the "
            "Scion is able to use their weapon as a conduit for emitting a negative energy "
            "discharge at a foe.");
        Setup();

        addPrerequisite(sprintf("lib/guilds/scion/paths/%s/root.c", WeaponType),
            (["type":"research"]));
        addPrerequisite(sprintf("lib/guilds/scion/paths/%s/blood/root.c", WeaponType),
            (["type":"research"]));

        addSpecification("scope", "targeted");
        addSpecification("research type", "points");
        addSpecification("research cost", 1);
        addSpecification("spell point cost", 10);

        addSpecification("damage hit points", ({ ([
                "probability":80,
                "base damage" : 5,
                "range" : 5
            ]),
            ([
                "probability":20,
                "base damage" : 10,
                "range" : 10
            ])
        }));
        addSpecification("damage type", "undead");

        addSpecification("modifiers", ({ 
            ([
                "type":"research",
                "research item": sprintf("lib/guilds/scion/paths/%s/blood/parasitic-charge.c", WeaponType),
                "name" : "Parasitic Charge",
                "formula" : "additive",
                "base value" : 5,
                "rate": 1.0
            ]),
            ([
                "type":"research",
                "research item": sprintf("lib/guilds/scion/paths/%s/blood/leechs-promise.c", WeaponType),
                "name" : "The Leech's Promise",
                "formula" : "additive",
                "base value" : 5,
                "rate": 1.0
            ]),
            ([
                "type":"skill",
                "name" : WeaponSkill,
                "formula" : "additive",
                "rate" : 1.05
            ]),
            ([
                "type":"skill",
                "name" : "blood",
                "formula" : "additive",
                "rate" : 1.10
            ]),
            ([
                "type":"attribute",
                "name" : "intelligence",
                "formula" : "additive",
                "rate" : 1.05
            ]) 
        }));

        addSpecification("cooldown", 4);
        addSpecification("event handler", "soulSpikeEvent");
        addSpecification("command template", "soul spike [at ##Target##]");
        addSpecification("use ability message",  "A fog of sickly purple hue "
            "flies from ##InitiatorPossessive::Name## ##InitiatorWeapon## "
            "into ##TargetName##.");
    }
}
