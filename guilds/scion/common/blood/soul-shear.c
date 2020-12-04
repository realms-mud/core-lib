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
        addSpecification("name", "Soul Shear");
        addSpecification("source", "Scion of Dhuras Guild");
        addSpecification("description", "This research provides the user with the "
            "knowledge of the lightning bolt technique. By means of this, the "
            "Scion is able to use their weapon as a conduit for emitting a bolt "
            "of negative energy at a foe.");
        Setup();

        addPrerequisite(sprintf("guilds/scion/paths/%s/root.c", WeaponType),
            (["type":"research"]));
        addPrerequisite(sprintf("guilds/scion/paths/%s/electricity/sparks.c", WeaponType),
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

        addSpecification("damage type", "undead");

        addSpecification("modifiers", ({ 
            ([
                "type":"research",
                "research item": sprintf("guilds/scion/paths/%s/blood/parasitic-charge.c", WeaponType),
                "name" : "Parasitic Charge",
                "formula" : "multiplicative",
                "base value" : 1,
                "rate": 1.25
            ]),
            ([
                "type":"research",
                "research item": sprintf("guilds/scion/paths/%s/blood/leechs-promise.c", WeaponType),
                "name" : "The Leech's Promise",
                "formula" : "multiplicative",
                "base value" : 1,
                "rate": 1.25
            ]),
            ([
                "type":"research",
                "research item": sprintf("guilds/scion/paths/%s/blood/enervation.c", WeaponType),
                "name" : "Enervation",
                "formula" : "multiplicative",
                "base value" : 1,
                "rate": 1.25
            ]),
            ([
                "type":"research",
                "research item": sprintf("guilds/scion/paths/%s/blood/malefic-discharge.c", WeaponType),
                "name" : "Malefic Discharge",
                "formula" : "multiplicative",
                "base value" : 1,
                "rate": 1.35
            ]),
            ([
                "type":"research",
                "research item": sprintf("guilds/scion/paths/%s/blood/crimson-eruption.c", WeaponType),
                "name" : "Crimson Eruption",
                "formula" : "multiplicative",
                "base value" : 1,
                "rate": 1.4
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
        addSpecification("event handler", "soulShearEvent");
        addSpecification("command template", "soul shear [at ##Target##]");
        addSpecification("use ability message",  "An intense bolt of crimson "
            "energy flies from ##InitiatorPossessive::Name## "
            "##InitiatorWeapon## into ##TargetName##.");
    }
}
