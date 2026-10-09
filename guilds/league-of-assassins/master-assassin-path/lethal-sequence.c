//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
// See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

protected void Setup()
{
    addSpecification("name", "Lethal Sequence");
    addSpecification("source", "League of Assassins");
    addSpecification("description", "This research provides the master assassin "
        "with the lethal sequence technique.");
    addPrerequisite("level",(["type":"level","guild":"League of Assassins","value":61]));
    addPrerequisite(
        "/guilds/league-of-assassins/master-assassin-path/assassins-wrath.c",
        (["type":"research"]));
    addSpecification("limited by", (["equipment": ({
        "dagger",
        "short sword"
    })]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 42);
    addSpecification("cooldown", 22);
    addSpecification("command template", "lethal sequence ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::execute## a precisely choreographed sequence of lethal strikes against ##TargetName##.");
    addSpecification("damage hit points", ({
        (["probability": 75, "base damage": 22, "range": 18]),
        (["probability": 25, "base damage": 44, "range": 36])
    }));
    addSpecification("damage type", "physical");
    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item":
                "/guilds/league-of-assassins/master-assassin-path/"
                "improved-lethal-sequence.c",
            "name": "Improved Lethal Sequence",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/league-of-assassins/master-assassin-path/"
                "perfect-lethal-sequence.c",
            "name": "Perfect Lethal Sequence",
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
            "rate": 0.26
        ]),
        ([
            "type": "attribute",
            "name": "dexterity",
            "formula": "additive",
            "rate": 0.3
        ]),
        ([
            "type": "level",
            "name": "League of Assassins",
            "formula": "additive",
            "rate": 0.6
        ])
    }));
}