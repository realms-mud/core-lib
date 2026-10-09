//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
// See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

protected void Setup()
{
    addSpecification("name", "Assassin's Wrath");
    addSpecification("source", "League of Assassins");
    addSpecification("description", "This research provides the master assassin "
        "with the assassin's wrath technique.");
    addPrerequisite("level",(["type":"level","guild":"League of Assassins","value":57]));
    addPrerequisite(
        "/guilds/league-of-assassins/master-assassin-path/vanishing-blade.c",
        (["type":"research"]));
    addSpecification("limited by", (["equipment": ({
        "dagger",
        "short sword"
    })]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 38);
    addSpecification("cooldown", 20);
    addSpecification("command template", "assassins wrath ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::channel## the full fury of the League into a devastating strike against ##TargetName##.");
    addSpecification("damage hit points", ({
        (["probability": 75, "base damage": 20, "range": 16]),
        (["probability": 25, "base damage": 40, "range": 32])
    }));
    addSpecification("damage type", "physical");
        addSpecification("apply enfeebled", 1);
    addSpecification("duration", 15);
    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item":
                "/guilds/league-of-assassins/master-assassin-path/"
                "improved-assassins-wrath.c",
            "name": "Improved Assassin's Wrath",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/league-of-assassins/master-assassin-path/"
                "perfect-assassins-wrath.c",
            "name": "Perfect Assassin's Wrath",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/league-of-assassins/master-assassin-path/"
                "masters-precision.c",
            "name": "Master's Precision",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/league-of-assassins/master-assassin-path/"
                "masters-swiftness.c",
            "name": "Master's Swiftness",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/league-of-assassins/master-assassin-path/"
                "masters-economy.c",
            "name": "Master's Economy",
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
            "rate": 0.24
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
            "rate": 0.58
        ])
    }));
}