//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
// See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

protected void Setup()
{
    addSpecification("name", "Crippling Blow");
    addSpecification("source", "League of Assassins");
    addSpecification("description", "This research provides the assassin with "
        "a strike designed to hamper the target's movement and combat "
        "effectiveness, targeting tendons, joints, and muscle groups.");
    addPrerequisite("level",
        (["type":"level","guild":"League of Assassins","value":35]));
    addPrerequisite(
        "/guilds/league-of-assassins/assassin-path/exploit-weakness.c",
        (["type":"research"]));
    addSpecification("limited by", (["equipment": ({
        "dagger",
        "short sword"
    })]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 30);
    addSpecification("cooldown", 16);
    addSpecification("command template", "crippling blow ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::deliver## a calculated "
        "crippling blow to ##TargetName##.");
    addSpecification("damage hit points", ({
        (["probability": 75, "base damage": 14, "range": 12]),
        (["probability": 25, "base damage": 26, "range": 18])
    }));
    addSpecification("damage type", "physical");
    addSpecification("apply enfeebled", 1);
    addSpecification("duration", 12);
    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item":
                "/guilds/league-of-assassins/assassin-path/"
                "improved-crippling-blow.c",
            "name": "Improved Crippling Blow",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/league-of-assassins/assassin-path/"
                "perfect-crippling-blow.c",
            "name": "Perfect Crippling Blow",
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
            "name": "strength",
            "formula": "additive",
            "rate": 0.20
        ]),
        ([
            "type": "level",
            "name": "League of Assassins",
            "formula": "additive",
            "rate": 0.52
        ])
    }));
}
