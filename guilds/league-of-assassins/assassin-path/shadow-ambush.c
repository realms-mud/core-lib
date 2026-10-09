//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
// See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

protected void Setup()
{
    addSpecification("name", "Shadow Ambush");
    addSpecification("source", "League of Assassins");
    addSpecification("description", "This research provides the assassin with "
        "a devastating ambush strike launched from cover, dealing "
        "heightened damage when the target is unaware or distracted.");
    addPrerequisite("level",
        (["type":"level","guild":"League of Assassins","value":27]));
    addPrerequisite(
        "/guilds/league-of-assassins/assassin-path/precision-strike.c",
        (["type":"research"]));
    addSpecification("limited by", (["equipment": ({
        "dagger",
        "short sword"
    })]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 24);
    addSpecification("cooldown", 14);
    addSpecification("command template", "shadow ambush ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::burst## from shadow and "
        "##Infinitive::drive## a blade into ##TargetName##.");
    addSpecification("damage hit points", ({
        (["probability": 75, "base damage": 12, "range": 10]),
        (["probability": 25, "base damage": 22, "range": 16])
    }));
    addSpecification("damage type", "physical");
    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item":
                "/guilds/league-of-assassins/assassin-path/"
                "improved-shadow-ambush.c",
            "name": "Improved Shadow Ambush",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/league-of-assassins/assassin-path/"
                "perfect-shadow-ambush.c",
            "name": "Perfect Shadow Ambush",
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
            "name": "hide",
            "formula": "additive",
            "rate": 0.18
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
