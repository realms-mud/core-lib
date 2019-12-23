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
        addSpecification("name", "Energy Shard");
        addSpecification("source", "Scion of Dhuras Guild");
        addSpecification("description", "This research provides the user with the "
            "knowledge of the energy missiles technique. By means of this, the "
            "Scion is able to use their weapon as a conduit for emitting a shard "
            "of magical energy at a foe.");
        Setup();

        addPrerequisite(sprintf("guilds/scion/paths/%s/root.c", WeaponType),
            (["type":"research"]));
        addPrerequisite(sprintf("guilds/scion/paths/%s/evocation/root.c", WeaponType),
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
        addSpecification("damage type", "energy");

        addSpecification("modifiers", ({ 
            ([
                "type":"research",
                "research item": sprintf("guilds/scion/paths/%s/evocation/mystic-charge.c", WeaponType),
                "name" : "Mystic Charge",
                "formula" : "additive",
                "base value" : 5,
                "rate": 1.0
            ]),
            ([
                "type":"research",
                "research item": sprintf("guilds/scion/paths/%s/evocation/magical-conduit.c", WeaponType),
                "name" : "Magical Conduit",
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
                "name" : "evocation",
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
        addSpecification("event handler", "energyShardEvent");
        addSpecification("command template", "energy shard [at ##Target##]");
        addSpecification("use ability message",  "Small shards of magical energy "
            "fly from ##InitiatorPossessive::Name## "
            "##InitiatorWeapon## into ##TargetName##.");
    }
}
