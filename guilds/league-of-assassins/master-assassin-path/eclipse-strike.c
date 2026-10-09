//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
// See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

protected void Setup()
{
    addSpecification("name", "Eclipse Strike");
    addSpecification("source", "League of Assassins");
    addSpecification("description", "This research provides the master assassin "
        "with the eclipse strike technique.");
    addPrerequisite("level",(["type":"level","guild":"League of Assassins","value":67]));
    addPrerequisite(
        "/guilds/league-of-assassins/master-assassin-path/lethal-sequence.c",
        (["type":"research"]));
    addSpecification("limited by", (["equipment": ({
        "dagger",
        "short sword"
    })]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 48);
    addSpecification("cooldown", 26);
    addSpecification("command template", "eclipse strike ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::become## a living shadow and ##Infinitive::strike## ##TargetName## with obliterating force.");
    addSpecification("damage hit points", ({
        (["probability": 75, "base damage": 26, "range": 20]),
        (["probability": 25, "base damage": 52, "range": 40])
    }));
    addSpecification("damage type", "physical");
    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item":
                "/guilds/league-of-assassins/master-assassin-path/"
                "improved-eclipse-strike.c",
            "name": "Improved Eclipse Strike",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/league-of-assassins/master-assassin-path/"
                "perfect-eclipse-strike.c",
            "name": "Perfect Eclipse Strike",
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
            "rate": 0.64
        ])
    }));
}