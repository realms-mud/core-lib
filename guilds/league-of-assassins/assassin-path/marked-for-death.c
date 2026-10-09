//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
// See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

protected void Setup()
{
    addSpecification("name", "Marked for Death");
    addSpecification("source", "League of Assassins");
    addSpecification("description", "This research provides the assassin with "
        "a technique that marks the target's most vulnerable points, "
        "making them significantly easier to hit and damage in "
        "subsequent strikes.");
    addPrerequisite("level",
        (["type":"level","guild":"League of Assassins","value":39]));
    addPrerequisite(
        "/guilds/league-of-assassins/assassin-path/crippling-blow.c",
        (["type":"research"]));
    addSpecification("limited by", (["equipment": ({
        "dagger",
        "short sword"
    })]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 34);
    addSpecification("cooldown", 20);
    addSpecification("command template", "marked for death ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::study## ##TargetName## "
        "and ##Infinitive::mark## the target's vital points.");
    addSpecification("damage hit points", ({
        (["probability": 70, "base damage": 16, "range": 14]),
        (["probability": 30, "base damage": 30, "range": 20])
    }));
    addSpecification("damage type", "physical");
    addSpecification("penalty to attack", -4);
    addSpecification("duration", 15);
    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item":
                "/guilds/league-of-assassins/assassin-path/"
                "improved-marked-for-death.c",
            "name": "Improved Marked for Death",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/league-of-assassins/assassin-path/"
                "perfect-marked-for-death.c",
            "name": "Perfect Marked for Death",
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
            "name": "perception",
            "formula": "additive",
            "rate": 0.20
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.22
        ]),
        ([
            "type": "level",
            "name": "League of Assassins",
            "formula": "additive",
            "rate": 0.54
        ])
    }));
}
