//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Dark Offering");
    addSpecification("source", "Disciple of Argloth");
    addSpecification("description", "This research teaches the Disciple to make a dark offering - sacrificing their own blood in an offering to Argloth that returns as devastating necrotic force upon a target.");

    addPrerequisite(
        "/guilds/disciple-of-argloth/forbidden/necrotic-sacrifice.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
          "guild": "Disciple of Argloth",
          "value": 26
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 120);
    addSpecification("hit point cost", 30);
    addSpecification("damage hit points", ({
        ([
            "probability": 75,
            "base damage": 30,
            "range": 50
        ]),
        ([
            "probability": 25,
            "base damage": 60,
            "range": 100
        ]),
    }));
    addSpecification("damage type", "magical");

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item":
                "/guilds/disciple-of-argloth/forbidden/dark-ritual.c",
            "name": "Dark Ritual",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
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
                "/guilds/disciple-of-argloth/death/ending-amplification.c",
            "name": "Ending Amplification",
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
            "rate": 1.30
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
            "name": "destruction",
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

    addSpecification("cooldown", 40);
    addSpecification("command template", "dark offering [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## make##InitiatorReflexive## a dark offering of ##InitiatorPossessive## blood, unleashing it upon ##TargetName##.");
}
