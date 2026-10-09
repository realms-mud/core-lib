//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
// See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

protected void Setup()
{
    addSpecification("name", "Death's Embrace");
    addSpecification("source", "League of Assassins");
    addSpecification("description", "This research provides the shadow lord "
        "with the death's embrace technique.");
    addPrerequisite("level",(["type":"level","guild":"League of Assassins","value":69]));
    addPrerequisite(
        "/guilds/league-of-assassins/shadow-lord-path/abyssal-strike.c",
        (["type":"research"]));
    addSpecification("limited by", (["equipment": ({
        "dagger",
        "short sword"
    })]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 36);
    addSpecification("cooldown", 18);
    addSpecification("command template", "deaths embrace ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::draw## ##TargetName## into a lethal embrace from which escape is impossible.");
    addSpecification("damage hit points", ({
        (["probability": 70, "base damage": 24, "range": 18]),
        (["probability": 30, "base damage": 48, "range": 36])
    }));
    addSpecification("damage type", "physical");
        addSpecification("apply enfeebled", 1);
    addSpecification("duration", 15);
    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item":
                "/guilds/league-of-assassins/shadow-lord-path/"
                "improved-deaths-embrace.c",
            "name": "Improved Death's Embrace",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/league-of-assassins/shadow-lord-path/"
                "perfect-deaths-embrace.c",
            "name": "Perfect Death's Embrace",
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
            "rate": 0.62
        ])
    }));
}