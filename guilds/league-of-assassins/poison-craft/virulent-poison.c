//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
// See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Virulent Poison");
    addSpecification("source", "League of Assassins");
    addSpecification("description", "This research provides the user with "
        "the knowledge of a particularly virulent poison applied to the "
        "blade before striking. The formulation attacks multiple body "
        "systems simultaneously, causing greater immediate damage "
        "alongside a severe poisoning effect.");

    addPrerequisite("level",
        (["type": "level",
            "guild": "League of Assassins",
            "value": 21
        ]));
    addPrerequisite("/guilds/league-of-assassins/poison-craft/"
        "improved-envenom.c",
        (["type": "research"]));
    addPrerequisite("/guilds/league-of-assassins/poison-craft/"
        "toxicology.c",
        (["type": "research"]));

    addSpecification("limited by", (["equipment": ({
        "dagger",
        "short sword"
    })]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 35);
    addSpecification("cooldown", 10);
    addSpecification("command template", "virulent poison ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## plunge##InitiatorReflexive## a virulently "
        "poisoned blade into ##TargetName##.");

    addSpecification("damage hit points", ({ ([
            "probability": 70,
            "base damage": 25,
            "range": 30
        ]),
        ([
            "probability": 30,
            "base damage": 45,
            "range": 50
        ])
    }));
    addSpecification("damage type", "poison");

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item":
                "/guilds/league-of-assassins/poison-craft/"
                "improved-virulent-poison.c",
            "name": "Improved Virulent Poison",
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
            "rate": 0.15
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.25
        ]),
        ([
            "type": "level",
            "name": "League of Assassins",
            "formula": "additive",
            "rate": 0.75
        ])
    }));

    addSpecification("apply poison", 1);
    addSpecification("duration", 30);
    addSpecification("consumables", (["vial of virulent poison": 1]));
}
