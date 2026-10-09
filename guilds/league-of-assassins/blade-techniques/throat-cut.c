//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
// See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Throat Cut");
    addSpecification("source", "League of Assassins");
    addSpecification("description", "This research provides the user with "
        "the knowledge of the throat cut technique. The assassin draws their "
        "blade swiftly across the target's neck, severing major vessels "
        "and disrupting the target's breathing, leaving them enfeebled "
        "and slowed as blood loss takes its toll.");

    addPrerequisite("level",
        (["type": "level",
            "guild": "League of Assassins",
            "value": 23
        ]));
    addPrerequisite("/guilds/league-of-assassins/blade-techniques/"
        "dual-strike.c",
        (["type": "research"]));

    addSpecification("limited by", (["equipment": ({
        "dagger",
        "short sword"
    })]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 35);
    addSpecification("cooldown", 12);
    addSpecification("command template", "throat cut ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## slash##InitiatorReflexive## a blade across "
        "##TargetName##'s throat.");

    addSpecification("damage hit points", ({ ([
            "probability": 70,
            "base damage": 25,
            "range": 30
        ]),
        ([
            "probability": 30,
            "base damage": 40,
            "range": 60
        ])
    }));
    addSpecification("damage type", "slash");

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item":
                "/guilds/league-of-assassins/blade-techniques/"
                "improved-throat-cut.c",
            "name": "Improved Throat Cut",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/league-of-assassins/blade-techniques/"
                "masters-throat-cut.c",
            "name": "Master's Throat Cut",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/league-of-assassins/blade-techniques/"
                "blade-precision.c",
            "name": "Blade Precision",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/league-of-assassins/blade-techniques/"
                "keen-edge.c",
            "name": "Keen Edge",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/league-of-assassins/blade-techniques/"
                "assassins-blade-mastery.c",
            "name": "Assassin's Blade Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.5
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
            "rate": 0.2
        ]),
        ([
            "type": "attribute",
            "name": "dexterity",
            "formula": "additive",
            "rate": 0.25
        ]),
        ([
            "type": "skill",
            "name": "perception",
            "formula": "additive",
            "rate": 0.1
        ]),
        ([
            "type": "level",
            "name": "League of Assassins",
            "formula": "additive",
            "rate": 0.5
        ])
    }));

    addSpecification("apply slow", 1);
    addSpecification("apply enfeebled", 1);
    addSpecification("duration", 20);
}
