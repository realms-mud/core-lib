//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
// See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

protected void Setup()
{
    addSpecification("name", "Final Reckoning");
    addSpecification("source", "League of Assassins");
    addSpecification("description", "This research provides the assassin with "
        "a calculated finishing strike executed with absolute commitment, "
        "combining everything learned on the path into one devastating blow.");
    addPrerequisite("level",
        (["type":"level","guild":"League of Assassins","value":45]));
    addPrerequisite(
        "/guilds/league-of-assassins/assassin-path/marked-for-death.c",
        (["type":"research"]));
    addSpecification("limited by", (["equipment": ({
        "dagger",
        "short sword"
    })]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 40);
    addSpecification("cooldown", 24);
    addSpecification("command template", "final reckoning ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::commit## utterly to a "
        "finishing blow, driving a blade into ##TargetName## "
        "with absolute lethal intent.");
    addSpecification("damage hit points", ({
        (["probability": 70, "base damage": 20, "range": 16]),
        (["probability": 30, "base damage": 36, "range": 24])
    }));
    addSpecification("damage type", "physical");
    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item":
                "/guilds/league-of-assassins/assassin-path/"
                "improved-final-reckoning.c",
            "name": "Improved Final Reckoning",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/league-of-assassins/assassin-path/"
                "perfect-final-reckoning.c",
            "name": "Perfect Final Reckoning",
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
            "rate": 0.22
        ]),
        ([
            "type": "attribute",
            "name": "dexterity",
            "formula": "additive",
            "rate": 0.28
        ]),
        ([
            "type": "level",
            "name": "League of Assassins",
            "formula": "additive",
            "rate": 0.56
        ])
    }));
}
