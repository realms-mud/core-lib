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
    addSpecification("name", "Argloth's Wrath");
    addSpecification("source", "Disciple of Argloth");
    addSpecification("description", "This research is the pinnacle of the "
        "Disciple's blood magic. Channeling every ounce of Argloth's "
        "corrupted power through their weapon, they unleash a devastating "
        "torrent of sanguine annihilation at all foes in the area - "
        "the same power that razed Mirost.");
    SetupResearch();

    addPrerequisite(sprintf(
        "/guilds/disciple-of-argloth/paths/%s/blood/crimson-devastation.c",
        WeaponType), (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
          "guild": "Disciple of Argloth",
          "value": 39 ]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 220);
    addSpecification("spell point cost modifiers", ([
        sprintf("/guilds/disciple-of-argloth/paths/%s/blood/argloths-reserve.c",
            WeaponType): 10,
        sprintf("/guilds/disciple-of-argloth/paths/%s/blood/argloths-call.c",
            WeaponType): 10,
        sprintf("/guilds/disciple-of-argloth/paths/%s/blood/argloths-might.c",
            WeaponType): 10,
        sprintf("/guilds/disciple-of-argloth/paths/%s/blood/argloths-fury.c",
            WeaponType): 10,
    ]));

    addSpecification("damage hit points", ({ ([
            "probability": 90,
            "base damage": 70,
            "range": 130
        ]),
        ([
            "probability": 10,
            "base damage": 140,
            "range": 260
        ])
    }));
    addSpecification("damage stamina points", ({ ([
            "probability": 90,
            "base damage": 30,
            "range": 60
        ]),
        ([
            "probability": 10,
            "base damage": 60,
            "range": 120
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
        sprintf("/guilds/disciple-of-argloth/paths/%s/blood/argloths-boon.c",
            WeaponType): 10,
        sprintf("/guilds/disciple-of-argloth/paths/%s/blood/argloths-endurance.c",
            WeaponType): 10,
        sprintf("/guilds/disciple-of-argloth/paths/%s/blood/argloths-finess.c",
            WeaponType): 10,
        sprintf("/guilds/disciple-of-argloth/paths/%s/blood/argloths-strength.c",
            WeaponType): 10,
    ]));

    addSpecification("event handler", "argloths-wrathEvent");
    addSpecification("command template", "argloth's wrath");
    addSpecification("use ability message",
        "##InitiatorName## raise##InitiatorReflexive## ##InitiatorPossessive## "
        "##InitiatorWeapon## to the heavens and unleash##InitiatorReflexive## "
        "Argloth's wrath - a cataclysmic wave of blood magic that tears "
        "through all nearby foes.");
}
