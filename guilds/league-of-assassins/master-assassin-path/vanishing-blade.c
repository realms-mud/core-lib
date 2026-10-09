//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
// See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

protected void Setup()
{
    addSpecification("name", "Vanishing Blade");
    addSpecification("source", "League of Assassins");
    addSpecification("description", "This research provides the master assassin "
        "with the vanishing blade technique.");
    addPrerequisite("level",(["type":"level","guild":"League of Assassins","value":53]));
    addPrerequisite(
        "/guilds/league-of-assassins/master-assassin-path/ghost-step-strike.c",
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
    addSpecification("cooldown", 18);
    addSpecification("command template", "vanishing blade ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::attack## ##TargetName## with a blade that seems to appear and disappear between strikes.");
    addSpecification("damage hit points", ({
        (["probability": 75, "base damage": 18, "range": 14]),
        (["probability": 25, "base damage": 36, "range": 28])
    }));
    addSpecification("damage type", "physical");
    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item":
                "/guilds/league-of-assassins/master-assassin-path/"
                "improved-vanishing-blade.c",
            "name": "Improved Vanishing Blade",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/league-of-assassins/master-assassin-path/"
                "perfect-vanishing-blade.c",
            "name": "Perfect Vanishing Blade",
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
            "name": "dagger",
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
            "rate": 0.56
        ])
    }));
}