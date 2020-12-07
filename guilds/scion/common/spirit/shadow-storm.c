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
        addSpecification("name", "Shadow Storm");
        addSpecification("source", "Scion of Dhuras Guild");
        addSpecification("description", "This research provides the user with the "
            "knowledge of the shadow storm technique. By means of this, the "
            "Scion is able to use their weapon as a conduit for emitting a blast "
            "of spirit-damaging mist at all foes in the area.");
        Setup();

        addPrerequisite(sprintf("guilds/scion/paths/%s/root.c", WeaponType),
            (["type":"research"]));
        addPrerequisite(sprintf("guilds/scion/paths/%s/spirit/soul-shard.c", WeaponType),
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
                "probability": 90,
                "base damage": 25,
                "range": 50
            ]),
            ([
                "probability": 10,
                "base damage": 50,
                "range": 100
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
        addSpecification("damage type", "magical");

        addSpecification("modifiers", ({ 
            ([
                "type":"research",
                "research item": sprintf("guilds/scion/paths/%s/spirit/chill-the-blood.c", WeaponType),
                "name" : "Chill the Blood",
                "formula" : "multiplicative",
                "base value" : 1,
                "rate": 1.25
            ]),
            ([
                "type":"research",
                "research item": sprintf("guilds/scion/paths/%s/spirit/spirit-mark.c", WeaponType),
                "name" : "Spirit Mark",
                "formula" : "multiplicative",
                "base value" : 1,
                "rate": 1.25
            ]),
            ([
                "type":"research",
                "research item": sprintf("guilds/scion/paths/%s/spirit/spectral-rage.c", WeaponType),
                "name" : "Spectral Rage",
                "formula" : "multiplicative",
                "base value" : 1,
                "rate": 1.25
            ]),
            ([
                "type":"research",
                "research item": sprintf("guilds/scion/paths/%s/spirit/nienwyns-kiss.c", WeaponType),
                "name" : "Nienwyn's Kiss",
                "formula" : "multiplicative",
                "base value" : 1,
                "rate": 1.35
            ]),
            ([
                "type":"research",
                "research item": sprintf("guilds/scion/paths/%s/spirit/laiwyths-mark.c", WeaponType),
                "name" : "Laiwyth's Mark",
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
                "name" : "spirit",
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
        addSpecification("event handler", "shadowStormEvent");
        addSpecification("command template", "shadow storm");
        addSpecification("use ability message",  "An intense blast of wispy white "
            " mist erupts from ##InitiatorPossessive::Name## ##InitiatorWeapon##.");
    }
}
