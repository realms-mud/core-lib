//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
// See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Heartseeker");
    addSpecification("source", "League of Assassins");
    addSpecification("description", "This research provides the user with "
        "the knowledge of the heartseeker technique. The assassin drives "
        "their blade toward the target's heart in a powerful lunge. Even "
        "when not immediately fatal, the cardiac shock and blood loss "
        "enfeeble the target and compromise their defenses.");

    addPrerequisite("level",
        (["type": "level",
            "guild": "League of Assassins",
            "value": 31
        ]));
    addPrerequisite("/guilds/league-of-assassins/blade-techniques/"
        "throat-cut.c",
        (["type": "research"]));

    addSpecification("limited by", (["equipment": ({
        "dagger",
        "short sword"
    })]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 45);
    addSpecification("cooldown", 14);
    addSpecification("command template", "heartseeker ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## drive##InitiatorReflexive## a blade toward "
        "##TargetName##'s heart in a powerful lunge.");

    addSpecification("damage hit points", ({ ([
            "probability": 70,
            "base damage": 35,
            "range": 40
        ]),
        ([
            "probability": 30,
            "base damage": 60,
            "range": 80
        ])
    }));
    addSpecification("damage type", "thrust");

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item":
                "/guilds/league-of-assassins/blade-techniques/"
                "improved-heartseeker.c",
            "name": "Improved Heartseeker",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/league-of-assassins/blade-techniques/"
                "perfect-heartseeker.c",
            "name": "Perfect Heartseeker",
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
            "rate": 0.25
        ]),
        ([
            "type": "attribute",
            "name": "strength",
            "formula": "additive",
            "rate": 0.2
        ]),
        ([
            "type": "attribute",
            "name": "dexterity",
            "formula": "additive",
            "rate": 0.2
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
            "rate": 0.75
        ])
    }));

    addSpecification("apply enfeebled", 1);
    addSpecification("penalty to defense class", 5);
    addSpecification("duration", 20);
}
