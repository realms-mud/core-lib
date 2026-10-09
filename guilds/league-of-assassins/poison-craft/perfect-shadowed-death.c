//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
// See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Perfect Shadowed Death");
    addSpecification("source", "League of Assassins");
    addSpecification("description", "This research provides the user with "
        "the pinnacle of the shadowed death technique. The compound "
        "represents the League's most lethal creation - every element "
        "refined to absolute perfection. No living thing that receives "
        "a full dose walks away unscathed.");

    addPrerequisite("level",
        (["type": "level",
            "guild": "League of Assassins",
            "value": 59
        ]));
    addPrerequisite("/guilds/league-of-assassins/poison-craft/"
        "improved-shadowed-death.c",
        (["type": "research"]));

    addSpecification("limited by", (["equipment": ({
        "dagger",
        "short sword"
    })]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 150);
    addSpecification("cooldown", 20);
    addSpecification("command template",
        "perfect shadowed death ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## condemn##InitiatorReflexive## ##TargetName## "
        "with a perfect shadowed death, a blade-strike and poison "
        "of absolute lethality.");

    addSpecification("damage hit points", ({ ([
            "probability": 50,
            "base damage": 200,
            "range": 175
        ]),
        ([
            "probability": 50,
            "base damage": 310,
            "range": 260
        ])
    }));
    addSpecification("damage type", "poison");

    addSpecification("modifiers", ({
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
            "type": "skill",
            "name": "chemistry",
            "formula": "additive",
            "rate": 0.4
        ]),
        ([
            "type": "skill",
            "name": "herbalism",
            "formula": "additive",
            "rate": 0.3
        ]),
        ([
            "type": "skill",
            "name": "anatomy and physiology",
            "formula": "additive",
            "rate": 0.3
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.4
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
    addSpecification("duration", 45);
    addSpecification("consumables", (["vial of shadowed death": 1]));
}
