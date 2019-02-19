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
        addSpecification("name", "Fire Bolt");
        addSpecification("source", "Scion of Dhuras Guild");
        addSpecification("description", "This research provides the user with the "
            "knowledge of the fire bolt technique. By means of this, the "
            "Scion is able to use their weapon as a conduit for emitting a bolt "
            "of searing fire at a foe.");
        Setup();

        addPrerequisite(sprintf("lib/guilds/scion/paths/%s/root.c", WeaponType),
            (["type":"research"]));
        addPrerequisite(sprintf("lib/guilds/scion/paths/%s/flame/flame-bolt.c", WeaponType),
            (["type":"research"]));
        addPrerequisite("level",
            (["type":"level",
                "guild": "Scion of Dhuras",
                "value": 9
            ]));

        addSpecification("scope", "targeted");
        addSpecification("research type", "points");
        addSpecification("research cost", 1);
        addSpecification("spell point cost", 100);

        addSpecification("damage hit points", ({ ([
                "probability":90,
                "base damage" : 25,
                "range" : 50
            ]),
            ([
                "probability": 10,
                "base damage": 50,
                "range" : 100
            ])
        }));

        addSpecification("damage type", "fire");

        addSpecification("modifiers", ({ 
            ([
                "type":"research",
                "research item": sprintf("lib/guilds/scion/paths/%s/flame/fuel-the-flames.c", WeaponType),
                "name" : "Fuel the Flames",
                "formula" : "additive",
                "base value" : 5,
                "rate": 1.0
            ]),
            ([
                "type":"research",
                "research item": sprintf("lib/guilds/scion/paths/%s/flame/scorching-mark.c", WeaponType),
                "name" : "Scorching Mark",
                "formula" : "additive",
                "base value" : 5,
                "rate": 1.0
            ]),
            ([
                "type":"research",
                "research item": sprintf("lib/guilds/scion/paths/%s/flame/stoking-rage.c", WeaponType),
                "name" : "Stoking Rage",
                "formula" : "additive",
                "base value" : 5,
                "rate": 1.0
            ]),
            ([
                "type":"research",
                "research item": sprintf("lib/guilds/scion/paths/%s/flame/enhanced-blaze.c", WeaponType),
                "name" : "Enhanced Blaze",
                "formula" : "additive",
                "base value" : 10,
                "rate": 1.0
            ]),
            ([
                "type":"research",
                "research item": sprintf("lib/guilds/scion/paths/%s/flame/inferno-mark.c", WeaponType),
                "name" : "Inferno Mark",
                "formula" : "additive",
                "base value" : 10,
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
                "name" : "elemental fire",
                "formula" : "additive",
                "rate" : 1.10
            ]),
            ([
                "type":"skill",
                "name" : "spellcraft",
                "formula" : "logarithmic",
                "rate" : 1.05
            ]),
            ([
                "type":"level",
                "name" : "level",
                "formula" : "logarithmic",
                "rate" : 1.05
            ]),
            ([
                "type":"attribute",
                "name" : "intelligence",
                "formula" : "additive",
                "rate" : 1.05
            ]) 
        }));

        addSpecification("cooldown", 60);
        addSpecification("event handler", "fireBoltEvent");
        addSpecification("command template", "fire bolt [at ##Target##]");
        addSpecification("use ability message",  "An intense spear-shaped bolt of fire "
            "flies from ##InitiatorPossessive::Name## ##InitiatorWeapon## into ##TargetName##.");
    }
}
