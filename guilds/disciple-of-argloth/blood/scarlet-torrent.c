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
    addSpecification("name", "Scarlet Torrent");
    addSpecification("source", "Disciple of Argloth");
    addSpecification("description", "This research teaches the Disciple "
        "to unleash a torrent of blade-borne blood energy in rapid "
        "succession, lashing the same target with three sanguine strikes "
        "in a single fluid motion.");
    SetupResearch();

    addPrerequisite(sprintf(
        "/guilds/disciple-of-argloth/paths/%s/blood/blood-tide.c",
        WeaponType), (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
          "guild": "Disciple of Argloth",
          "value": 28
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 160);
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
            "probability": 100,
            "base damage": 25,
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

    addSpecification("cooldown", 50);
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
        "scarlet torrent [at ##Target##]");
    addSpecification("use ability message",
        "##InitiatorName## unleash##InitiatorReflexive## a scarlet torrent "
        "of blood strikes at ##TargetName##.");
}
