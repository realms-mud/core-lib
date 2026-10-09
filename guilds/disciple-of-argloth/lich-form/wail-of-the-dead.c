//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Wail of the Dead");
    addSpecification("source", "Disciple of Argloth");
    addSpecification("description", "The Disciple opens their mouth and releases "
        "a wail of pure death energy that hammers all nearby foes. Available "
        "only while in the Lich Form.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/disciple-of-argloth/lich-form/lich-form-root.c"
        })
    ]));

    addPrerequisite(
        "/guilds/disciple-of-argloth/lich-form/deathly-insight.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
          "guild": "Disciple of Argloth",
          "value": 20
        ]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 120);
    addSpecification("cooldown", 50);

    addSpecification("damage hit points", ({
        ([
            "probability": 75,
            "base damage": 28,
            "range": 52
        ]),
        ([
            "probability": 25,
            "base damage": 56,
            "range": 100
        ]),
    }));
    addSpecification("damage type", "magical");

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item":
                "/guilds/disciple-of-argloth/lich-form/lich-attunement.c",
            "name": "Lich Attunement",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/disciple-of-argloth/lich-form/deathly-insight.c",
            "name": "Deathly Insight",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/disciple-of-argloth/lich-form/sepulchral-mastery.c",
            "name": "Sepulchral Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/disciple-of-argloth/lich-form/lich-conduit-knowledge.c",
            "name": "Lich Conduit Knowledge",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/disciple-of-argloth/lich-form/phylactery-theory.c",
            "name": "Phylactery Theory",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.30
        ]),
        ([
            "type": "skill",
            "name": "body",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "skill",
            "name": "evocation",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "skill",
            "name": "magical essence",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "skill",
            "name": "destruction",
            "formula": "additive",
            "rate": 0.10
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

    addSpecification("command template", "wail of the dead");
    addSpecification("use ability message",
        "##InitiatorName## open##InitiatorReflexive## ##InitiatorPossessive## "
        "jaws and release##InitiatorReflexive## a wail of death that tears "
        "at all nearby foes!");
}
