//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Soul Rend (Form)");
    addSpecification("source", "Disciple of Argloth");
    addSpecification("description", "The Disciple tears directly at the soul "
        "of a foe, rending it from the body with the raw power of Argloth's "
        "death energy. The pinnacle offensive ability of the Lich Form.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/disciple-of-argloth/lich-form/lich-form-root.c"
        })
    ]));

    addPrerequisite(
        "/guilds/disciple-of-argloth/lich-form/phylactery-theory.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
          "guild": "Disciple of Argloth",
          "value": 41
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 250);
    addSpecification("hit point cost", 30);
    addSpecification("cooldown", 60);

    addSpecification("siphon hit points", ({
        ([
            "probability": 70,
            "base damage": 70,
            "range": 130
        ]),
        ([
            "probability": 30,
            "base damage": 140,
            "range": 260
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
                "/guilds/disciple-of-argloth/lich-form/lich-conduit-knowledge.c",
            "name": "Lich Conduit Knowledge",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/disciple-of-argloth/lich-form/phylactery-theory.c",
            "name": "Phylactery Theory",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
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
            "type": "research",
            "research item":
                "/guilds/disciple-of-argloth/lich-form/deathly-insight.c",
            "name": "Deathly Insight",
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

    addSpecification("command template", "soul rend [at ##Target##]");
    addSpecification("use ability message",
        "##InitiatorName## drive##InitiatorReflexive## ethereal claws into "
        "##TargetName## and ##Infinitive::rend## at the soul within, drawing "
        "life back into ##InitiatorPossessive## own form!");
}
