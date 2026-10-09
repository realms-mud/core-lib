//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
// See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Shadowed Death");
    addSpecification("source", "League of Assassins");
    addSpecification("description", "This research provides the user with "
        "the knowledge of the shadowed death technique. The assassin "
        "delivers a strike laced with the League's most lethal compound, "
        "a blend of multiple toxins that attacks every system "
        "simultaneously. The target is poisoned, diseased, and enfeebled "
        "by this single devastating blow.");

    addPrerequisite("level",
        (["type": "level",
            "guild": "League of Assassins",
            "value": 47
        ]));
    addPrerequisite("/guilds/league-of-assassins/poison-craft/"
        "improved-virulent-poison.c",
        (["type": "research"]));
    addPrerequisite("/guilds/league-of-assassins/poison-craft/"
        "assassins-poison-mastery.c",
        (["type": "research"]));

    addSpecification("limited by", (["equipment": ({
        "dagger",
        "short sword"
    })]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 100);
    addSpecification("cooldown", 20);
    addSpecification("command template", "shadowed death ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## drive##InitiatorReflexive## a blade coated "
        "in shadowed death into ##TargetName##, condemning them to "
        "a swift and toxic end.");

    addSpecification("damage hit points", ({ ([
            "probability": 60,
            "base damage": 90,
            "range": 90
        ]),
        ([
            "probability": 40,
            "base damage": 150,
            "range": 130
        ])
    }));
    addSpecification("damage type", "poison");

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item":
                "/guilds/league-of-assassins/poison-craft/"
                "improved-shadowed-death.c",
            "name": "Improved Shadowed Death",
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
            "rate": 1.0
        ])
    }));

    addSpecification("apply poison", 1);
    addSpecification("apply disease", 1);
    addSpecification("apply enfeebled", 1);
    addSpecification("duration", 35);
    addSpecification("consumables", (["vial of shadowed death": 1]));
}
