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
    addSpecification("name", "Blood Obliteration");
    addSpecification("source", "Disciple of Argloth");
    addSpecification("description", "This research contains the ultimate "
        "expression of Argloth's blood covenant - an absolute obliteration "
        "of a target's vitality. The technique consumes a significant "
        "portion of the Disciple's own blood to achieve its devastating "
        "effect, and cannot be used lightly.");
    SetupResearch();

    addPrerequisite(sprintf(
        "/guilds/disciple-of-argloth/paths/%s/blood/sylthasis-strike.c",
        WeaponType), (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
          "guild": "Disciple of Argloth",
          "value": 70
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 400);
    addSpecification("hit point cost", 100);
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
            "probability": 60,
            "base damage": 120,
            "range": 200
        ]),
        ([
            "probability": 40,
            "base damage": 240,
            "range": 400
        ])
    }));
    addSpecification("damage spell points", ({
        ([
            "probability": 100,
            "base damage": 60,
            "range": 100
        ])
    }));
    addSpecification("damage stamina points", ({
        ([
            "probability": 100,
            "base damage": 40,
            "range": 70
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

    addSpecification("cooldown", 120);
    addSpecification("cooldown modifiers", ([
        sprintf(
            "/guilds/disciple-of-argloth/paths/%s/blood/argloths-boon.c",
            WeaponType): 15,
        sprintf(
            "/guilds/disciple-of-argloth/paths/%s/blood/"
            "argloths-endurance.c",
            WeaponType): 15,
    ]));

    addSpecification("command template",
        "blood obliteration [at ##Target##]");
    addSpecification("use ability message",
        "##InitiatorName## sacrifice##InitiatorReflexive## "
        "##InitiatorPossessive## own blood to fuel a total obliteration "
        "of ##TargetName##.");
}
