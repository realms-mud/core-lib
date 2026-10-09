//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Bone Lance");
    addSpecification("source", "Disciple of Argloth");
    addSpecification("description", "The Disciple wrenches bone from the dead "
        "and hurls it as a lance of sharp death at a foe. Available only "
        "while in the Lich Form.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/disciple-of-argloth/lich-form/lich-form-root.c"
        })
    ]));

    addPrerequisite(
        "/guilds/disciple-of-argloth/lich-form/bone-resonance.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
          "guild": "Disciple of Argloth",
          "value": 10
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 65);
    addSpecification("cooldown", 30);

    addSpecification("damage hit points", ({
        ([
            "probability": 80,
            "base damage": 18,
            "range": 32
        ]),
        ([
            "probability": 20,
            "base damage": 38,
            "range": 64
        ]),
    }));
    addSpecification("damage type", "magical");

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item":
                "/guilds/disciple-of-argloth/lich-form/bone-resonance.c",
            "name": "Bone Resonance",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/disciple-of-argloth/lich-form/lich-attunement.c",
            "name": "Lich Attunement",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/disciple-of-argloth/lich-form/deathly-insight.c",
            "name": "Deathly Insight",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
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
            "name": "spellcraft",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "skill",
            "name": "spirit",
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

    addSpecification("command template", "bone lance [at ##Target##]");
    addSpecification("use ability message",
        "##InitiatorName## hurl##InitiatorReflexive## a lance of bone and "
        "death energy at ##TargetName##.");
}
