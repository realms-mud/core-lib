//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
// See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

protected void Setup()
{
    addSpecification("name", "Void Rend");
    addSpecification("source", "League of Assassins");
    addSpecification("description", "This research provides the shadow lord "
        "with the void rend technique.");
    addPrerequisite("level",(["type":"level","guild":"League of Assassins","value":83]));
    addPrerequisite(
        "/guilds/league-of-assassins/shadow-lord-path/shadow-execution.c",
        (["type":"research"]));
    addSpecification("limited by", (["equipment": ({
        "dagger",
        "short sword"
    })]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 50);
    addSpecification("cooldown", 26);
    addSpecification("command template", "void rend ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::tear## through ##TargetName##'s defenses with a strike that seems to come from nowhere and everywhere simultaneously.");
    addSpecification("damage hit points", ({
        (["probability": 70, "base damage": 32, "range": 24]),
        (["probability": 30, "base damage": 64, "range": 48])
    }));
    addSpecification("damage type", "physical");
    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item":
                "/guilds/league-of-assassins/shadow-lord-path/"
                "improved-void-rend.c",
            "name": "Improved Void Rend",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/league-of-assassins/shadow-lord-path/"
                "perfect-void-rend.c",
            "name": "Perfect Void Rend",
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
            "rate": 0.28
        ]),
        ([
            "type": "attribute",
            "name": "dexterity",
            "formula": "additive",
            "rate": 0.32
        ]),
        ([
            "type": "level",
            "name": "League of Assassins",
            "formula": "additive",
            "rate": 0.68
        ])
    }));
}