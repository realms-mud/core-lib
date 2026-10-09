//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
// See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

protected void Setup()
{
    addSpecification("name", "Precision Strike");
    addSpecification("source", "League of Assassins");
    addSpecification("description", "This research provides the assassin with "
        "a precisely aimed attack that finds gaps in the target's guard, "
        "bypassing armor to strike directly at vulnerable tissue.");
    addPrerequisite("level",
        (["type":"level","guild":"League of Assassins","value":25]));
    addPrerequisite(
        "/guilds/league-of-assassins/assassin-path/root.c",
        (["type":"research"]));
    addSpecification("limited by", (["equipment": ({
        "dagger",
        "short sword"
    })]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 20);
    addSpecification("cooldown", 12);
    addSpecification("command template", "precision strike ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::drive## a precisely aimed "
        "blade into a gap in ##TargetName##'s defenses.");
    addSpecification("damage hit points", ({
        (["probability": 80, "base damage": 10, "range": 8]),
        (["probability": 20, "base damage": 18, "range": 14])
    }));
    addSpecification("damage type", "physical");
    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item":
                "/guilds/league-of-assassins/assassin-path/"
                "improved-precision-strike.c",
            "name": "Improved Precision Strike",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/league-of-assassins/assassin-path/"
                "perfect-precision-strike.c",
            "name": "Perfect Precision Strike",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/league-of-assassins/assassin-path/"
                "assassins-precision.c",
            "name": "Assassin's Precision",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/league-of-assassins/assassin-path/"
                "assassins-swiftness.c",
            "name": "Assassin's Swiftness",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/league-of-assassins/assassin-path/"
                "assassins-economy.c",
            "name": "Assassin's Economy",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "weapon damage",
            "name": "blade",
            "types": ({
                "dagger",
                "short sword"
            }),
            "formula": "additive",
            "rate": 0.75
        ]),
        ([
            "type": "highest skill",
            "name": "blade skills",
            "skills": ({
                "dagger",
                "short sword"
            }),
            "formula": "additive",
            "rate": 0.5
        ]),
        ([
            "type": "skill",
            "name": "anatomy and physiology",
            "formula": "additive",
            "rate": 0.20
        ]),
        ([
            "type": "attribute",
            "name": "dexterity",
            "formula": "additive",
            "rate": 0.25
        ]),
        ([
            "type": "level",
            "name": "League of Assassins",
            "formula": "additive",
            "rate": 0.50
        ])
    }));
}
