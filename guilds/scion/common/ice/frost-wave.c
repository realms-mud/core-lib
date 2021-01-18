//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

protected string WeaponType = "ERROR";
protected string WeaponSkill = "unarmed";
protected string *ValidWeaponTypes = ({ });

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
        addSpecification("name", "Frost Wave");
        addSpecification("source", "Scion of Dhuras Guild");
        addSpecification("description", "This research provides the user with the "
            "knowledge of the frost wave technique. By means of this, the "
            "Scion is able to use their weapon as a conduit for emitting a blast "
            "of frigid mist at all foes in the area.");
        Setup();

        addPrerequisite(sprintf("guilds/scion/paths/%s/root.c", WeaponType),
            (["type":"research"]));
        addPrerequisite(sprintf("guilds/scion/paths/%s/ice/ice-javelin.c", WeaponType),
            (["type":"research"]));
        addPrerequisite("level",
            (["type":"level",
                "guild": "Scion of Dhuras",
                "value": 17
            ]));

        addSpecification("scope", "area");
        addSpecification("research type", "points");
        addSpecification("research cost", 1);
        addSpecification("spell point cost", 150);

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
        addSpecification("damage spell points", ({ ([
                "probability":90,
                "base damage" : 10,
                "range" : 25
            ]),
            ([
                "probability": 10,
                "base damage": 25,
                "range" : 50
            ])
        }));
        addSpecification("damage type", "cold");

        addSpecification("modifiers", ({ 
            ([
                "type":"research",
                "research item": sprintf("guilds/scion/paths/%s/ice/chill-the-blood.c", WeaponType),
                "name" : "Chill the Blood",
                "formula" : "multiplicative",
                "base value" : 1,
                "rate": 1.25
            ]),
            ([
                "type":"research",
                "research item": sprintf("guilds/scion/paths/%s/ice/freezing-mark.c", WeaponType),
                "name" : "Freezing Mark",
                "formula" : "multiplicative",
                "base value" : 1,
                "rate": 1.25
            ]),
            ([
                "type":"research",
                "research item": sprintf("guilds/scion/paths/%s/ice/winters-rage.c", WeaponType),
                "name" : "Winter's Rage",
                "formula" : "multiplicative",
                "base value" : 1,
                "rate": 1.25
            ]),
            ([
                "type":"research",
                "research item": sprintf("guilds/scion/paths/%s/ice/wind-chill.c", WeaponType),
                "name" : "Wind Chill",
                "formula" : "multiplicative",
                "base value" : 1,
                "rate": 1.35
            ]),
            ([
                "type":"research",
                "research item": sprintf("guilds/scion/paths/%s/ice/icy-mark.c", WeaponType),
                "name" : "Icy Mark",
                "formula" : "multiplicative",
                "base value" : 1,
                "rate": 1.4
            ]),
            ([
                "type": "weapon damage",
                "name": WeaponSkill,
                "types": ValidWeaponTypes,
                "formula": "additive",
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

        addSpecification("cooldown", 100);
        addSpecification("event handler", "frostWaveEvent");
        addSpecification("command template", "frost wave");
        addSpecification("use ability message",  "An intense blast of frigid "
            " mist erupts from ##InitiatorPossessive::Name## ##InitiatorWeapon##.");
    }
}
