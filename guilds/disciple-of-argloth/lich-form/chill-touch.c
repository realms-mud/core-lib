//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Chill Touch");
    addSpecification("source", "Disciple of Argloth");
    addSpecification("description", "This research teaches the Disciple to "
        "channel the cold of the grave through a touch, sapping the life from "
        "a foe. Available only while in the Lich Form.");

    addPrerequisite(
        "/guilds/disciple-of-argloth/lich-form/bone-resonance.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
          "guild": "Disciple of Argloth",
          "value": 8
        ]));

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/disciple-of-argloth/lich-form/lich-form-root.c"
        })
    ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 50);
    addSpecification("cooldown", 20);

    addSpecification("damage hit points", ({
        ([
            "probability": 85,
            "base damage": 14,
            "range": 22
        ]),
        ([
            "probability": 15,
            "base damage": 28,
            "range": 44
        ]),
    }));
    addSpecification("damage type", "cold");

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
            "name": "willpower",
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

    addSpecification("command template", "chill touch [at ##Target##]");
    addSpecification("use ability message",
        "##InitiatorName## extend##InitiatorReflexive## ##InitiatorPossessive## "
        "withered hand, channeling the cold of the grave into ##TargetName##.");
}
