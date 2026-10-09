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
    addSpecification("name", "Zhardeg's Lash");
    addSpecification("source", "Disciple of Argloth");
    addSpecification("description", "This research recovers the chain "
        "technique of Zhardeg the Reaper, who served Argloth in the Age "
        "of Ruin. Zhardeg's Lash drives a single strike through multiple "
        "foes in sequence, each blow fueled by the blood of the last.");
    SetupResearch();

    addPrerequisite(sprintf(
        "/guilds/disciple-of-argloth/paths/%s/blood/mirosts-ruin.c",
        WeaponType), (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
          "guild": "Disciple of Argloth",
          "value": 63
        ]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 310);
    addSpecification("hit point cost", 55);
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
            "probability": 80,
            "base damage": 55,
            "range": 95
        ]),
        ([
            "probability": 20,
            "base damage": 110,
            "range": 190
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

    addSpecification("cooldown", 80);
    addSpecification("cooldown modifiers", ([
        sprintf(
            "/guilds/disciple-of-argloth/paths/%s/blood/argloths-boon.c",
            WeaponType): 10,
        sprintf(
            "/guilds/disciple-of-argloth/paths/%s/blood/"
            "argloths-endurance.c",
            WeaponType): 10,
    ]));

    addSpecification("command template", "zhardegs lash");
    addSpecification("use ability message",
        "##InitiatorName## invoke##InitiatorReflexive## Zhardeg's Lash, "
        "driving blood-fueled strikes through all nearby foes.");
}
