//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
// See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

protected void Setup()
{
    addSpecification("name", "Abyssal Strike");
    addSpecification("source", "League of Assassins");
    addSpecification("description", "This research provides the shadow lord "
        "with the abyssal strike technique.");
    addPrerequisite("level",(["type":"level","guild":"League of Assassins","value":65]));
    addPrerequisite(
        "/guilds/league-of-assassins/shadow-lord-path/root.c",
        (["type":"research"]));
    addSpecification("limited by", (["equipment": ({
        "dagger",
        "short sword"
    })]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 32);
    addSpecification("cooldown", 16);
    addSpecification("command template", "abyssal strike ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::strike## ##TargetName## with a blade drawn from the abyssal darkness.");
    addSpecification("damage hit points", ({
        (["probability": 70, "base damage": 20, "range": 16]),
        (["probability": 30, "base damage": 40, "range": 32])
    }));
    addSpecification("damage type", "physical");
    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item":
                "/guilds/league-of-assassins/shadow-lord-path/"
                "improved-abyssal-strike.c",
            "name": "Improved Abyssal Strike",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/league-of-assassins/shadow-lord-path/"
                "perfect-abyssal-strike.c",
            "name": "Perfect Abyssal Strike",
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
            "name": "dagger",
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