//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Scythe of Argloth");
    addSpecification("source", "Disciple of Argloth");
    addSpecification("description", "This research teaches the Disciple to call down the scythe of Argloth himself - a sweeping strike of pure death energy that reaps all it touches.");

    addPrerequisite(
        "/guilds/disciple-of-argloth/death/annihilate.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
          "guild": "Disciple of Argloth",
          "value": 50
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 220);
    addSpecification("hit point cost", 40);
    addSpecification("damage hit points", ({
        ([
            "probability": 65,
            "base damage": 60,
            "range": 100
        ]),
        ([
            "probability": 35,
            "base damage": 120,
            "range": 200
        ]),
    }));
    addSpecification("damage type", "physical");

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item":
                "/guilds/disciple-of-argloth/death/death-amplification.c",
            "name": "Death Amplification",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/disciple-of-argloth/death/death-amplification-ii.c",
            "name": "Greater Death Amplification",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
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
                "/guilds/disciple-of-argloth/death/final-passage.c",
            "name": "Final Passage",
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
            "name": "magical essence",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
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

    addSpecification("cooldown", 60);
    addSpecification("command template", "scythe of argloth [at ##Target##]");
    addSpecification("use ability message",
        "##InitiatorName## call##InitiatorReflexive## down the scythe of "
        "Argloth himself, reaping ##TargetName## with pure death energy.");
}
