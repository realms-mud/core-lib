//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

protected string WeaponType = "ERROR";
protected string WeaponSkill = "unarmed";
protected string *ValidWeaponTypes = ({ });

/////////////////////////////////////////////////////////////////////////////
protected void SetupResearch()
{
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Soul Shard");
    addSpecification("source", "Scion of Dhuras Guild");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the soul shard technique. By means of this, the "
        "Scion is able to use their weapon as a conduit for emitting a shard "
        "of super-cooled ice at a foe.");
    SetupResearch();

    addPrerequisite(sprintf("/guilds/scion/paths/%s/root.c", WeaponType),
        (["type":"research"]));
    addPrerequisite(sprintf("/guilds/scion/paths/%s/spirit/spirit-bolt.c", WeaponType),
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
    addSpecification("spell point cost modifiers", ([
        sprintf("/guilds/scion/paths/%s/spirit/scions-reserve.c", WeaponType): 10,
        sprintf("/guilds/scion/paths/%s/spirit/scions-call.c", WeaponType): 10,
        sprintf("/guilds/scion/paths/%s/spirit/scions-might.c", WeaponType): 10,
        sprintf("/guilds/scion/paths/%s/spirit/scions-fury.c", WeaponType): 10,
    ]));

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

    addSpecification("damage type", "magical");

    addSpecification("modifiers", ({ 
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/spirit/chill-the-blood.c", WeaponType),
            "name" : "Chill the Blood",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.25
        ]),
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/spirit/spirit-mark.c", WeaponType),
            "name" : "Spirit Mark",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.25
        ]),
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/spirit/spectral-rage.c", WeaponType),
            "name" : "Spectral Rage",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.25
        ]),
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/spirit/nienwyns-kiss.c", WeaponType),
            "name" : "Nienwyn's Kiss",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.35
        ]),
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/spirit/laiwyths-mark.c", WeaponType),
            "name" : "Laiwyth's Mark",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.4
        ]),
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/spirit/spirit-shear.c", WeaponType),
            "name" : "Spirit Shear",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.25
        ]),
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/spirit/laiwyths-lament.c", WeaponType),
            "name" : "Laiwyth's Lament",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.25
        ]),
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/spirit/flay-the-soul.c", WeaponType),
            "name" : "Flay the Soul",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.25
        ]),
        ([
            "type":"research",
            "research item": sprintf("/guilds/scion/paths/%s/spirit/soul-scourge.c", WeaponType),
            "name" : "Soul Scourge",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate": 1.5
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
            "rate" : 0.05
        ]),
        ([
            "type":"skill",
            "name" : "spirit",
            "formula" : "additive",
            "rate" : 0.10
        ]),
        ([
            "type": "level",
            "name": "level",
            "formula": "logarithmic",
            "rate": 1.05
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.25
        ]),
        ([
            "type":"skill",
            "name": "magical essence",
            "formula": "logarithmic",
            "rate": 1.25
        ]),
        ([
            "type":"skill",
            "name" : "physics",
            "formula" : "additive",
            "rate" : 0.10
        ]),
        ([
            "type": "skill",
            "name": "mathematics",
            "formula": "additive",
            "rate": 0.05
        ]),
        ([
            "type": "skill",
            "name": "chemistry",
            "formula": "additive",
            "rate": 0.05
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.05
        ]), 
        ([
            "type": "attribute",
            "name": "dexterity",
            "formula": "additive",
            "rate": 0.025
        ]), 
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.025
        ]), 
    }));

    addSpecification("cooldown", 60);
    addSpecification("cooldown modifiers", ([
        sprintf("/guilds/scion/paths/%s/spirit/scions-boon.c", WeaponType): 10,
        sprintf("/guilds/scion/paths/%s/spirit/scions-finess.c", WeaponType): 10,
        sprintf("/guilds/scion/paths/%s/spirit/scions-endurance.c", WeaponType): 10,
        sprintf("/guilds/scion/paths/%s/spirit/scions-strength.c", WeaponType): 10,
    ]));

    addSpecification("event handler", "soulShardEvent");
    addSpecification("command template", "soul shard [at ##Target##]");
    addSpecification("use ability message",  "An intensly powerful shard of glistening white energy "
        "flies from ##InitiatorPossessive::Name## ##InitiatorWeapon## into ##TargetName##.");
}
