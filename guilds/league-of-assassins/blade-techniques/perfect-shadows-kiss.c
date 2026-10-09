//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
// See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Perfect Shadow's Kiss");
    addSpecification("source", "League of Assassins");
    addSpecification("description", "This research provides the user with "
        "the perfected form of the shadow's kiss technique. The assassin "
        "has so internalized the art of the killing blade that the strike "
        "arrives before the target perceives any movement at all. The wound "
        "is catastrophic, leaving the target enfeebled and their defenses "
        "shattered.");

    addPrerequisite("level",
        (["type": "level",
            "guild": "League of Assassins",
            "value": 67
        ]));
    addPrerequisite("/guilds/league-of-assassins/blade-techniques/"
        "improved-shadows-kiss.c",
        (["type": "research"]));

    addSpecification("limited by", (["equipment": ({
        "dagger",
        "short sword"
    })]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 140);
    addSpecification("cooldown", 24);
    addSpecification("command template", "perfect shadows kiss ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## vanish##InitiatorReflexive## into shadow and "
        "reappear##InitiatorReflexive## with a devastating killing strike "
        "on ##TargetName##.");

    addSpecification("damage hit points", ({ ([
            "probability": 45,
            "base damage": 175,
            "range": 150
        ]),
        ([
            "probability": 55,
            "base damage": 280,
            "range": 275
        ])
    }));
    addSpecification("damage type", "thrust");

    addSpecification("modifiers", ({
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
            "rate": 0.3
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
    addSpecification("penalty to defense class", 8);
    addSpecification("duration", 30);
}
