//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
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
    addSpecification("name", "Sylthasis Strike");
    addSpecification("source", "Disciple of Argloth");
    addSpecification("description", "This research recovers the killing "
        "technique of Sylthasis the Hollow, the most feared of Argloth's "
        "servants. The Sylthasis Strike drives all the blood covenant "
        "into a single blow of absolute devastation.");
    SetupResearch();

    addPrerequisite(sprintf(
        "/guilds/disciple-of-argloth/paths/%s/blood/zhardegs-lash.c",
        WeaponType), (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
          "guild": "Disciple of Argloth",
          "value": 67
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 350);
    addSpecification("hit point cost", 70);
    addSpecification("spell point cost modifiers", ([
        sprintf(
            "/guilds/disciple-of-argloth/paths/%s/blood/argloths-reserve.c",
            WeaponType): 10,
        sprintf(
            "/guilds/disciple-of-argloth/paths/%s/blood/argloths-call.c",
            WeaponType): 10,
        sprintf(
            "/guilds/disciple-of-argloth/paths/%s/blood/argloths-might.c",
            WeaponType): 10,
    ]));

    addSpecification("damage hit points", ({
        ([
            "probability": 65,
            "base damage": 90,
            "range": 150
        ]),
        ([
            "probability": 35,
            "base damage": 180,
            "range": 300
        ])
    }));
    addSpecification("damage spell points", ({
        ([
            "probability": 100,
            "base damage": 50,
            "range": 80
        ])
    }));
    addSpecification("damage stamina points", ({
        ([
            "probability": 100,
            "base damage": 30,
            "range": 50
        ])
    }));
    addSpecification("damage type", "undead");

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item":
                "/guilds/disciple-of-argloth/blood/sanguine-mastery.c",
            "name": "Sanguine Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/disciple-of-argloth/blood/crimson-precision.c",
            "name": "Crimson Precision",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/disciple-of-argloth/blood/dark-potency.c",
            "name": "Dark Potency",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/disciple-of-argloth/blood/hemorrhagic-mastery.c",
            "name": "Hemorrhagic Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/disciple-of-argloth/blood/ruinous-potential.c",
            "name": "Ruinous Potential",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "skill",
            "name": "blood",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "skill",
            "name": "magical essence",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "skill",
            "name": "body",
            "formula": "additive",
            "rate": 0.05
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.50
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.25
        ]),
        ([
            "type": "level",
            "name": "Disciple of Argloth",
            "formula": "additive",
            "rate": 0.50
        ]),
    }));

    addSpecification("cooldown", 90);
    addSpecification("cooldown modifiers", ([
        sprintf(
            "/guilds/disciple-of-argloth/paths/%s/blood/argloths-boon.c",
            WeaponType): 10,
        sprintf(
            "/guilds/disciple-of-argloth/paths/%s/blood/"
            "argloths-endurance.c",
            WeaponType): 10,
    ]));

    addSpecification("command template",
        "sylthasis strike [at ##Target##]");
    addSpecification("use ability message",
        "##InitiatorName## channel##InitiatorReflexive## the full power "
        "of the blood covenant into the Sylthasis Strike upon ##TargetName##.");
}
