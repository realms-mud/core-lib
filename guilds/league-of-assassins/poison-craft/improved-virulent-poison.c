//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
// See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Improved Virulent Poison");
    addSpecification("source", "League of Assassins");
    addSpecification("description", "This research provides the user with "
        "an improved formulation of the virulent poison technique. The "
        "compound has been refined to attack the target's constitution "
        "more aggressively, causing disease-like systemic damage "
        "alongside the initial wound.");

    addPrerequisite("level",
        (["type": "level",
            "guild": "League of Assassins",
            "value": 27
        ]));
    addPrerequisite("/guilds/league-of-assassins/poison-craft/"
        "virulent-poison.c",
        (["type": "research"]));

    addSpecification("limited by", (["equipment": ({
        "dagger",
        "short sword"
    })]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 45);
    addSpecification("cooldown", 10);
    addSpecification("command template",
        "improved virulent poison ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## drive##InitiatorReflexive## an "
        "exceptionally potent poisoned blade into ##TargetName##.");

    addSpecification("damage hit points", ({ ([
            "probability": 65,
            "base damage": 40,
            "range": 40
        ]),
        ([
            "probability": 35,
            "base damage": 70,
            "range": 65
        ])
    }));
    addSpecification("damage type", "poison");

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item":
                "/guilds/league-of-assassins/poison-craft/"
                "virulent-formula.c",
            "name": "Virulent Formula",
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
            "rate": 0.3
        ]),
        ([
            "type": "skill",
            "name": "herbalism",
            "formula": "additive",
            "rate": 0.2
        ]),
        ([
            "type": "skill",
            "name": "anatomy and physiology",
            "formula": "additive",
            "rate": 0.2
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

    addSpecification("apply poison", 1);
    addSpecification("apply disease", 1);
    addSpecification("duration", 30);
    addSpecification("consumables", (["vial of virulent poison": 1]));
}
