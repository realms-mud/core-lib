//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
// See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Lacerate");
    addSpecification("source", "League of Assassins");
    addSpecification("description", "This research provides the user with "
        "the knowledge of the lacerate technique. The assassin rakes their "
        "blade across exposed flesh in a tearing motion, opening a wound "
        "that bleeds freely and saps the target's strength.");

    addPrerequisite("level",
        (["type": "level",
            "guild": "League of Assassins",
            "value": 3
        ]));
    addPrerequisite("/guilds/league-of-assassins/blade-techniques/root.c",
        (["type": "research"]));

    addSpecification("limited by", (["equipment": ({
        "dagger",
        "short sword"
    })]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 15);
    addSpecification("cooldown", 6);
    addSpecification("command template", "lacerate ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## rake##InitiatorReflexive## a blade across "
        "##TargetName##, lacerating exposed flesh.");

    addSpecification("damage hit points", ({ ([
            "probability": 80,
            "base damage": 8,
            "range": 12
        ]),
        ([
            "probability": 20,
            "base damage": 15,
            "range": 25
        ])
    }));
    addSpecification("damage type", "slash");

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item":
                "/guilds/league-of-assassins/blade-techniques/"
                "deep-laceration.c",
            "name": "Deep Laceration",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/league-of-assassins/blade-techniques/"
                "serrated-technique.c",
            "name": "Serrated Technique",
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
            "rate": 0.15
        ]),
        ([
            "type": "attribute",
            "name": "dexterity",
            "formula": "additive",
            "rate": 0.25
        ]),
        ([
            "type": "level",
            "name": "League of Assassins",
            "formula": "additive",
            "rate": 0.5
        ])
    }));

    addSpecification("apply enfeebled", 1);
    addSpecification("duration", 15);
}
