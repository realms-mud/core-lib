//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Adept Strike");
    addSpecification("source", "Disciple of Argloth");
    addSpecification("description", "The blood strike of the necromancer adept - a powerful ability that draws on accumulated dark energy.");

    addPrerequisite("guild rank",
        (["type": "guild rank",
          "guild": "Disciple of Argloth",
          "value": "necromancer adept"
        ]));
    addPrerequisite("level",
        (["type": "level",
          "guild": "Disciple of Argloth",
          "value": 25
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 130);
    addSpecification("hit point cost", 20);
    addSpecification("damage hit points", ({
        ([
            "probability": 75,
            "base damage": 40,
            "range": 65
        ]),
        ([
            "probability": 25,
            "base damage": 80,
            "range": 130
        ]),
    }));
    addSpecification("siphon hit points", ({
        ([
            "probability": 100,
            "base damage": 25,
            "range": 40
        ])
    }));
    addSpecification("damage type", "magical");

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item":
                "/guilds/disciple-of-argloth/necromancy/necrotic-amplification.c",
            "name": "Necrotic Amplification",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/disciple-of-argloth/death/ending-amplification.c",
            "name": "Ending Amplification",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/disciple-of-argloth/forbidden/ritual-mastery.c",
            "name": "Ritual Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/disciple-of-argloth/forbidden/forbidden-amplification.c",
            "name": "Forbidden Amplification",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/disciple-of-argloth/shadow/shadow-amplification.c",
            "name": "Shadow Amplification",
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
    addSpecification("command template", "adept strike [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## deliver##InitiatorReflexive## an adept strike upon ##TargetName##.");
}
