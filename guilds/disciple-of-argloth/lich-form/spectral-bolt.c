//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Spectral Bolt");
    addSpecification("source", "Disciple of Argloth");
    addSpecification("description", "The Disciple hurls a bolt of spectral "
        "death energy that passes through armor and tears at the soul itself. "
        "Available only while in the Lich Form.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/disciple-of-argloth/lich-form/lich-form-root.c"
        })
    ]));

    addPrerequisite(
        "/guilds/disciple-of-argloth/lich-form/sepulchral-mastery.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
          "guild": "Disciple of Argloth",
          "value": 27
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 150);
    addSpecification("cooldown", 40);

    addSpecification("damage hit points", ({
        ([
            "probability": 75,
            "base damage": 40,
            "range": 75
        ]),
        ([
            "probability": 25,
            "base damage": 80,
            "range": 150
        ]),
    }));
    addSpecification("damage type", "magical");

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item":
                "/guilds/disciple-of-argloth/lich-form/deathly-insight.c",
            "name": "Deathly Insight",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/disciple-of-argloth/lich-form/sepulchral-mastery.c",
            "name": "Sepulchral Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
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
            "type": "research",
            "research item":
                "/guilds/disciple-of-argloth/lich-form/undying-focus.c",
            "name": "Undying Focus",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "skill",
            "name": "body",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "skill",
            "name": "spirit",
            "formula": "additive",
            "rate": 0.10
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

    addSpecification("command template", "spectral bolt [at ##Target##]");
    addSpecification("use ability message",
        "##InitiatorName## hurl##InitiatorReflexive## a bolt of spectral "
        "death energy at ##TargetName##, passing through armor to tear "
        "at the soul within.");
}
