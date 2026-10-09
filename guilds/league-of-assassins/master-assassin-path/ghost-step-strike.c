//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
// See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

protected void Setup()
{
    addSpecification("name", "Ghost Step Strike");
    addSpecification("source", "League of Assassins");
    addSpecification("description", "This research provides the master assassin "
        "with the ghost step strike technique.");
    addPrerequisite("level",(["type":"level","guild":"League of Assassins","value":49]));
    addPrerequisite(
        "/guilds/league-of-assassins/master-assassin-path/flaying-strike.c",
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
    addSpecification("command template", "ghost step strike ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::vanish## into shadow and ##Infinitive::reappear## behind ##TargetName## with a blade already moving.");
    addSpecification("damage hit points", ({
        (["probability": 75, "base damage": 16, "range": 14]),
        (["probability": 25, "base damage": 32, "range": 28])
    }));
    addSpecification("damage type", "physical");
    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item":
                "/guilds/league-of-assassins/master-assassin-path/"
                "improved-ghost-step-strike.c",
            "name": "Improved Ghost Step Strike",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/league-of-assassins/master-assassin-path/"
                "perfect-ghost-step-strike.c",
            "name": "Perfect Ghost Step Strike",
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
            "name": "hide",
            "formula": "additive",
            "rate": 0.22
        ]),
        ([
            "type": "attribute",
            "name": "dexterity",
            "formula": "additive",
            "rate": 0.26
        ]),
        ([
            "type": "level",
            "name": "League of Assassins",
            "formula": "additive",
            "rate": 0.54
        ])
    }));
}