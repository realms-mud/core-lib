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
        addSpecification("name", "Maelstrom");
        addSpecification("source", "Scion of Dhuras Guild");
        addSpecification("description", "This research provides the user with the "
            "knowledge of the maelstrom technique. By means of this, the "
            "Scion is able to use their weapon as a conduit for sending balls "
            "of plasma at all foes in the area.");
        Setup();

        addPrerequisite(sprintf("guilds/scion/paths/%s/root.c", WeaponType),
            (["type":"research"]));
        addPrerequisite(sprintf("guilds/scion/paths/%s/evocation/energy-storm.c", WeaponType),
            (["type":"research"]));
        addPrerequisite("level",
            (["type":"level",
                "guild": "Scion of Dhuras",
                "value": 37
            ]));

        addSpecification("scope", "area");
        addSpecification("research type", "points");
        addSpecification("research cost", 1);
        addSpecification("spell point cost", 250);

        addSpecification("damage hit points", ({ ([
                "probability":90,
                "base damage" : 100,
                "range" : 200
            ]),
            ([
                "probability":10,
                "base damage" : 200,
                "range" : 500
            ])
        }));
        addSpecification("damage spell points", ({ ([
                "probability":90,
                "base damage" : 50,
                "range" : 100
            ]),
            ([
                "probability": 10,
                "base damage": 100,
                "range" : 200
            ])
        }));
        addSpecification("damage type", "magical");

        addSpecification("modifiers", ({ 
            ([
                "type":"research",
                "research item": sprintf("guilds/scion/paths/%s/evocation/mystic-charge.c", WeaponType),
                "name" : "Mystic Charge",
                "formula" : "multiplicative",
                "base value" : 1,
                "rate": 1.25
            ]),
            ([
                "type":"research",
                "research item": sprintf("guilds/scion/paths/%s/evocation/magical-conduit.c", WeaponType),
                "name" : "Magical Conduit",
                "formula" : "multiplicative",
                "base value" : 1,
                "rate": 1.25
            ]),
            ([
                "type":"research",
                "research item": sprintf("guilds/scion/paths/%s/evocation/ionization.c", WeaponType),
                "name" : "Ionization",
                "formula" : "multiplicative",
                "base value" : 1,
                "rate": 1.25
            ]),
            ([
                "type":"research",
                "research item": sprintf("guilds/scion/paths/%s/evocation/kinetic-discharge.c", WeaponType),
                "name" : "Kinetic Discharge",
                "formula" : "multiplicative",
                "base value" : 1,
                "rate": 1.35
            ]),
            ([
                "type":"research",
                "research item": sprintf("guilds/scion/paths/%s/evocation/plasma-eruption.c", WeaponType),
                "name" : "Plasma Eruption",
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
                "name" : "evocation",
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

        addSpecification("cooldown", 180);
        addSpecification("event handler", "maelstromEvent");
        addSpecification("command template", "maelstrom");
        addSpecification("use ability message",  "Intense balls of plasma "
            "erupt from ##InitiatorPossessive::Name## ##InitiatorWeapon##.");
    }
}
