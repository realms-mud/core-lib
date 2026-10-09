//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Shadow Strike");
    addSpecification("source", "Disciple of Argloth");
    addSpecification("description", "This research teaches the Disciple to strike from within shadow, a blow that carries the cold of the void.");

    addPrerequisite(
        "/guilds/disciple-of-argloth/shadow/shadow-step.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
          "guild": "Disciple of Argloth",
          "value": 7
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 60);
    addSpecification("damage hit points", ({
        ([
            "probability": 90,
            "base damage": 15,
            "range": 25
        ]),
        ([
            "probability": 10,
            "base damage": 30,
            "range": 50
        ]),
    }));
    addSpecification("damage type", "magical");

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item":
                "/guilds/disciple-of-argloth/shadow/shadow-amplification.c",
            "name": "Shadow Amplification",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/disciple-of-argloth/shadow/umbral-theory.c",
            "name": "Umbral Theory",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/disciple-of-argloth/death/death-amplification.c",
            "name": "Death Amplification",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/disciple-of-argloth/necromancy/necromantic-surge.c",
            "name": "Necromantic Surge",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/disciple-of-argloth/necromancy/necrotic-amplification.c",
            "name": "Necrotic Amplification",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "skill",
            "name": "willpower",
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
            "name": "evocation",
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

    addSpecification("cooldown", 30);
    addSpecification("command template", "shadow strike [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## strike##InitiatorReflexive## from within shadow, a blow carrying the chill of the void at ##TargetName##.");
}
