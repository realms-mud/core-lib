//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
// See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Improved Wasting Blight");
    addSpecification("source", "League of Assassins");
    addSpecification("description", "This research provides the user with "
        "an improved formulation of the wasting blight technique. "
        "The refined compound devastates the target's constitution "
        "more aggressively, causing rapid systemic disease alongside "
        "heavy direct damage.");

    addPrerequisite("level",
        (["type": "level",
            "guild": "League of Assassins",
            "value": 37
        ]));
    addPrerequisite("/guilds/league-of-assassins/poison-craft/"
        "wasting-blight.c",
        (["type": "research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 65);
    addSpecification("cooldown", 15);
    addSpecification("command template",
        "improved wasting blight ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## expose##InitiatorReflexive## ##TargetName## "
        "to an improved wasting blight that devours from within.");

    addSpecification("damage hit points", ({ ([
            "probability": 65,
            "base damage": 50,
            "range": 50
        ]),
        ([
            "probability": 35,
            "base damage": 85,
            "range": 75
        ])
    }));
    addSpecification("damage type", "poison");

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item":
                "/guilds/league-of-assassins/poison-craft/"
                "perfect-wasting-blight.c",
            "name": "Perfect Wasting Blight",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/league-of-assassins/poison-craft/"
                "blight-mastery.c",
            "name": "Blight Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/league-of-assassins/poison-craft/"
                "toxicology.c",
            "name": "Toxicology",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/league-of-assassins/poison-craft/"
                "assassins-poison-mastery.c",
            "name": "Assassin's Poison Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.5
        ]),
        ([
            "type": "skill",
            "name": "chemistry",
            "formula": "additive",
            "rate": 0.35
        ]),
        ([
            "type": "skill",
            "name": "herbalism",
            "formula": "additive",
            "rate": 0.3
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.3
        ]),
        ([
            "type": "level",
            "name": "League of Assassins",
            "formula": "additive",
            "rate": 0.75
        ])
    }));

    addSpecification("apply disease", 1);
    addSpecification("apply enfeebled", 1);
    addSpecification("duration", 35);
    addSpecification("consumables", (["vial of wasting blight": 1]));
}
