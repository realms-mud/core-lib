//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
// See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Perfect Wasting Blight");
    addSpecification("source", "League of Assassins");
    addSpecification("description", "This research provides the user with "
        "the perfected wasting blight technique. The compound is so "
        "thoroughly optimized that it overwhelms the target's immune "
        "system almost instantly, causing massive disease damage, "
        "enfeebling, and slowing the target as their body collapses.");

    addPrerequisite("level",
        (["type": "level",
            "guild": "League of Assassins",
            "value": 41
        ]));
    addPrerequisite("/guilds/league-of-assassins/poison-craft/"
        "improved-wasting-blight.c",
        (["type": "research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 80);
    addSpecification("cooldown", 15);
    addSpecification("command template",
        "perfect wasting blight ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## unleash##InitiatorReflexive## a perfected "
        "wasting blight that consumes ##TargetName## from within.");

    addSpecification("damage hit points", ({ ([
            "probability": 60,
            "base damage": 75,
            "range": 70
        ]),
        ([
            "probability": 40,
            "base damage": 120,
            "range": 110
        ])
    }));
    addSpecification("damage type", "poison");

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item":
                "/guilds/league-of-assassins/poison-craft/"
                "blight-mastery.c",
            "name": "Blight Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/league-of-assassins/poison-craft/"
                "toxicology.c",
            "name": "Toxicology",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/league-of-assassins/poison-craft/"
                "assassins-poison-mastery.c",
            "name": "Assassin's Poison Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.5
        ]),
        ([
            "type": "skill",
            "name": "chemistry",
            "formula": "additive",
            "rate": 0.35
        ]),
        ([
            "type": "skill",
            "name": "herbalism",
            "formula": "additive",
            "rate": 0.3
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.35
        ]),
        ([
            "type": "level",
            "name": "League of Assassins",
            "formula": "additive",
            "rate": 1.0
        ])
    }));

    addSpecification("apply disease", 1);
    addSpecification("apply enfeebled", 1);
    addSpecification("apply slow", 1);
    addSpecification("duration", 40);
    addSpecification("consumables", (["vial of wasting blight": 1]));
}
