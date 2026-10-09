//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
// See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Improved Shadow's Kiss");
    addSpecification("source", "League of Assassins");
    addSpecification("description", "This research provides the user with "
        "a refined mastery of the shadow's kiss technique. The assassin "
        "strikes with even greater precision, the blade finding every "
        "weakness in the target's defenses. The wound left behind bleeds "
        "freely and leaves the target enfeebled.");

    addPrerequisite("level",
        (["type": "level",
            "guild": "League of Assassins",
            "value": 63
        ]));
    addPrerequisite("/guilds/league-of-assassins/blade-techniques/"
        "shadows-kiss.c",
        (["type": "research"]));

    addSpecification("limited by", (["equipment": ({
        "dagger",
        "short sword"
    })]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 120);
    addSpecification("cooldown", 24);
    addSpecification("command template", "improved shadows kiss ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## glide##InitiatorReflexive## through the shadows "
        "and deliver##InitiatorReflexive## a precise and lethal strike "
        "to ##TargetName##.");

    addSpecification("damage hit points", ({ ([
            "probability": 50,
            "base damage": 130,
            "range": 120
        ]),
        ([
            "probability": 50,
            "base damage": 220,
            "range": 230
        ])
    }));
    addSpecification("damage type", "thrust");

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item":
                "/guilds/league-of-assassins/blade-techniques/"
                "perfect-shadows-kiss.c",
            "name": "Perfect Shadow's Kiss",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/league-of-assassins/blade-techniques/"
                "supreme-blade-mastery.c",
            "name": "Supreme Blade Mastery",
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
            "name": "move silently",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "skill",
            "name": "anatomy and physiology",
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
            "type": "attribute",
            "name": "dexterity",
            "formula": "additive",
            "rate": 0.3
        ]),
        ([
            "type": "level",
            "name": "League of Assassins",
            "formula": "additive",
            "rate": 1.0
        ])
    }));

    addSpecification("apply enfeebled", 1);
    addSpecification("duration", 25);
}
