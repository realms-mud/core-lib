//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
// See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Improved Envenom");
    addSpecification("source", "League of Assassins");
    addSpecification("description", "This research provides the user with "
        "an improved formulation of the envenom technique. The assassin "
        "has refined their poison compounds, producing a more potent "
        "toxin that spreads faster through the target's blood.");

    addPrerequisite("level",
        (["type": "level",
            "guild": "League of Assassins",
            "value": 9
        ]));
    addPrerequisite("/guilds/league-of-assassins/poison-craft/envenom.c",
        (["type": "research"]));

    addSpecification("limited by", (["equipment": ({
        "dagger",
        "short sword"
    })]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 20);
    addSpecification("cooldown", 8);
    addSpecification("command template", "improved envenom ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## drive##InitiatorReflexive## a heavily envenomed "
        "blade into ##TargetName##.");

    addSpecification("damage hit points", ({ ([
            "probability": 75,
            "base damage": 12,
            "range": 18
        ]),
        ([
            "probability": 25,
            "base damage": 22,
            "range": 30
        ])
    }));
    addSpecification("damage type", "poison");

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item":
                "/guilds/league-of-assassins/poison-craft/"
                "virulent-poison.c",
            "name": "Virulent Poison",
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
            "rate": 0.25
        ]),
        ([
            "type": "skill",
            "name": "herbalism",
            "formula": "additive",
            "rate": 0.15
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
            "rate": 0.5
        ])
    }));

    addSpecification("apply poison", 1);
    addSpecification("duration", 25);
    addSpecification("consumables", (["vial of serpent's venom": 1]));
}
