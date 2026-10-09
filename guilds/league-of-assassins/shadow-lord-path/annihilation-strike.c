//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
// See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

protected void Setup()
{
    addSpecification("name", "Annihilation Strike");
    addSpecification("source", "League of Assassins");
    addSpecification("description", "This research provides the shadow lord "
        "with the annihilation strike technique.");
    addPrerequisite("level",(["type":"level","guild":"League of Assassins","value":89]));
    addPrerequisite(
        "/guilds/league-of-assassins/shadow-lord-path/void-rend.c",
        (["type":"research"]));
    addSpecification("limited by", (["equipment": ({
        "dagger",
        "short sword"
    })]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 58);
    addSpecification("cooldown", 30);
    addSpecification("command template", "annihilation strike ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::deliver## the annihilation strike - the definitive expression of the shadow lord's lethal art.");
    addSpecification("damage hit points", ({
        (["probability": 70, "base damage": 38, "range": 28]),
        (["probability": 30, "base damage": 76, "range": 56])
    }));
    addSpecification("damage type", "physical");
        addSpecification("apply enfeebled", 2);
    addSpecification("apply slow", 1);
    addSpecification("duration", 20);
    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item":
                "/guilds/league-of-assassins/shadow-lord-path/"
                "improved-annihilation-strike.c",
            "name": "Improved Annihilation Strike",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/league-of-assassins/shadow-lord-path/"
                "perfect-annihilation-strike.c",
            "name": "Perfect Annihilation Strike",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/league-of-assassins/shadow-lord-path/"
                "shadow-lords-precision.c",
            "name": "Shadow Lord's Precision",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/league-of-assassins/shadow-lord-path/"
                "shadow-lords-swiftness.c",
            "name": "Shadow Lord's Swiftness",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/league-of-assassins/shadow-lord-path/"
                "shadow-lords-economy.c",
            "name": "Shadow Lord's Economy",
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
            "rate": 0.3
        ]),
        ([
            "type": "attribute",
            "name": "dexterity",
            "formula": "additive",
            "rate": 0.34
        ]),
        ([
            "type": "level",
            "name": "League of Assassins",
            "formula": "additive",
            "rate": 0.72
        ])
    }));
}