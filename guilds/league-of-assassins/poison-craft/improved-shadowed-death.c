//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
// See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Improved Shadowed Death");
    addSpecification("source", "League of Assassins");
    addSpecification("description", "This research provides the user with "
        "an improved formulation of the shadowed death technique. "
        "The compound has been further refined to act faster and "
        "with greater devastation, combining poison, disease, and "
        "systemic shock in a single lethal dose.");

    addPrerequisite("level",
        (["type": "level",
            "guild": "League of Assassins",
            "value": 53
        ]));
    addPrerequisite("/guilds/league-of-assassins/poison-craft/"
        "shadowed-death.c",
        (["type": "research"]));

    addSpecification("limited by", (["equipment": ({
        "dagger",
        "short sword"
    })]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 120);
    addSpecification("cooldown", 20);
    addSpecification("command template",
        "improved shadowed death ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## deliver##InitiatorReflexive## a perfected "
        "shadowed death strike to ##TargetName##.");

    addSpecification("damage hit points", ({ ([
            "probability": 55,
            "base damage": 130,
            "range": 120
        ]),
        ([
            "probability": 45,
            "base damage": 210,
            "range": 180
        ])
    }));
    addSpecification("damage type", "poison");

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item":
                "/guilds/league-of-assassins/poison-craft/"
                "perfect-shadowed-death.c",
            "name": "Perfect Shadowed Death",
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
            "type": "research",
            "research item":
                "/guilds/league-of-assassins/poison-craft/"
                "supreme-poison-mastery.c",
            "name": "Supreme Poison Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
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
            "type": "skill",
            "name": "chemistry",
            "formula": "additive",
            "rate": 0.35
        ]),
        ([
            "type": "skill",
            "name": "herbalism",
            "formula": "additive",
            "rate": 0.25
        ]),
        ([
            "type": "skill",
            "name": "anatomy and physiology",
            "formula": "additive",
            "rate": 0.25
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.35
        ]),
        ([
            "type": "level",
            "name": "League of Assassins",
            "formula": "additive",
            "rate": 1.0
        ])
    }));

    addSpecification("apply poison", 1);
    addSpecification("apply disease", 1);
    addSpecification("apply enfeebled", 1);
    addSpecification("apply slow", 1);
    addSpecification("duration", 40);
    addSpecification("consumables", (["vial of shadowed death": 1]));
}
