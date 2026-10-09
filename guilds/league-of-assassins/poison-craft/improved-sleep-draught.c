//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
// See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Improved Sleep Draught");
    addSpecification("source", "League of Assassins");
    addSpecification("description", "This research provides the user with "
        "an enhanced version of the sleep draught technique. The refined "
        "sedative compound acts more aggressively, dulling the target's "
        "senses more deeply and leaving them far more vulnerable.");

    addPrerequisite("level",
        (["type": "level",
            "guild": "League of Assassins",
            "value": 15
        ]));
    addPrerequisite("/guilds/league-of-assassins/poison-craft/"
        "sleep-draught.c",
        (["type": "research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 35);
    addSpecification("cooldown", 30);
    addSpecification("command template", "improved sleep draught ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## administer##InitiatorReflexive## a powerful "
        "sedative compound to ##TargetName##.");

    addSpecification("damage hit points", ({ ([
            "probability": 100,
            "base damage": 5,
            "range": 10
        ])
    }));
    addSpecification("damage type", "poison");

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item":
                "/guilds/league-of-assassins/poison-craft/"
                "soporific-mastery.c",
            "name": "Soporific Mastery",
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
            "rate": 0.25
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

    addSpecification("apply slow", 1);
    addSpecification("apply enfeebled", 1);
    addSpecification("duration", 35);
    addSpecification("consumables", (["vial of soporific draught": 1]));
}
