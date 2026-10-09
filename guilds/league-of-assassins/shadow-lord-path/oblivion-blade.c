//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
// See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

protected void Setup()
{
    addSpecification("name", "Oblivion Blade");
    addSpecification("source", "League of Assassins");
    addSpecification("description", "This research provides the shadow lord "
        "with the oblivion blade technique.");
    addPrerequisite("level",(["type":"level","guild":"League of Assassins","value":73]));
    addPrerequisite(
        "/guilds/league-of-assassins/shadow-lord-path/deaths-embrace.c",
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
    addSpecification("cooldown", 20);
    addSpecification("command template", "oblivion blade ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::drive## an oblivion-forged blade through ##TargetName##'s defenses.");
    addSpecification("damage hit points", ({
        (["probability": 70, "base damage": 26, "range": 20]),
        (["probability": 30, "base damage": 52, "range": 40])
    }));
    addSpecification("damage type", "physical");
    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item":
                "/guilds/league-of-assassins/shadow-lord-path/"
                "improved-oblivion-blade.c",
            "name": "Improved Oblivion Blade",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/league-of-assassins/shadow-lord-path/"
                "perfect-oblivion-blade.c",
            "name": "Perfect Oblivion Blade",
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
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.32
        ]),
        ([
            "type": "level",
            "name": "League of Assassins",
            "formula": "additive",
            "rate": 0.64
        ])
    }));
}