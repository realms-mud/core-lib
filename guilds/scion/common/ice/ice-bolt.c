//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
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
        addSpecification("name", "Ice Bolt");
        addSpecification("source", "Scion of Dhuras Guild");
        addSpecification("description", "This research provides the user with the "
            "knowledge of the ice bolt technique. By means of this, the "
            "Scion is able to use their weapon as a conduit for emitting a freezing "
            "discharge at a foe.");
        Setup();

        addPrerequisite(sprintf("lib/guilds/scion/paths/%s/root.c", WeaponType),
            (["type":"research"]));
        addPrerequisite(sprintf("lib/guilds/scion/paths/%s/ice/root.c", WeaponType),
            (["type":"research"]));

        addSpecification("scope", "targeted");
        addSpecification("research type", "points");
        addSpecification("research cost", 1);
        addSpecification("spell point cost", 15);

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
        addSpecification("damage type", "cold");

        addSpecification("modifiers", ({ 
            ([
                "type":"research",
                "research item": sprintf("lib/guilds/scion/paths/%s/ice/chill-the-blood.c", WeaponType),
                "name" : "Chill the Blood",
                "formula" : "additive",
                "base value" : 5,
                "rate": 1.0
            ]),
            ([
                "type":"research",
                "research item": sprintf("lib/guilds/scion/paths/%s/ice/freezing-mark.c", WeaponType),
                "name" : "Freezing Mark",
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
                "name" : "elemental water",
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

        addSpecification("cooldown", 6);
        addSpecification("event handler", "iceBoltEvent");
        addSpecification("command template", "ice bolt [at ##Target##]");
        addSpecification("use ability message",  "Small shards of ice "
            "fly from ##InitiatorPossessive::Name## "
            "##InitiatorWeapon## into ##TargetName##.");
    }
}
