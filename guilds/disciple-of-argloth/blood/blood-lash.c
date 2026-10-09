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
    addSpecification("name", "Blood Lash");
    addSpecification("source", "Disciple of Argloth");
    addSpecification("description", "This research provides the Disciple "
        "with the knowledge of the blood lash technique. By drawing their "
        "own blood across their weapon, they unleash a whip of sanguine "
        "energy at a single foe.");
    SetupResearch();

    addPrerequisite(sprintf("/guilds/disciple-of-argloth/paths/%s/blood/root.c",
        WeaponType), (["type": "research"]));

    addPrerequisite("level",
        (["type": "level",
          "guild": "Disciple of Argloth",
          "value": 1 ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 40);
    addSpecification("spell point cost modifiers", ([
        sprintf("/guilds/disciple-of-argloth/paths/%s/blood/argloths-reserve.c",
            WeaponType): 10,
        sprintf("/guilds/disciple-of-argloth/paths/%s/blood/argloths-call.c",
            WeaponType): 10,
    ]));

    addSpecification("damage hit points", ({ ([
            "probability": 90,
            "base damage": 10,
            "range": 20
        ]),
        ([
            "probability": 10,
            "base damage": 20,
            "range": 40
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

    addSpecification("cooldown", 6);
    addSpecification("event handler", "bloodLashEvent");
    addSpecification("command template",
        "blood lash [at ##Target##]");
    addSpecification("use ability message",
        "##InitiatorName## draw##InitiatorReflexive## blood across "
        "##InitiatorPossessive## ##InitiatorWeapon## and lash##InitiatorReflexive## "
        "it toward ##TargetName##.");
}
