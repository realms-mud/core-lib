//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
// See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Perfect Sleep Draught");
    addSpecification("source", "League of Assassins");
    addSpecification("description", "This research provides the user with "
        "the perfected form of the sleep draught technique. The highly "
        "concentrated compound incapacitates the target's nervous system "
        "almost instantly, leaving them deeply enfeebled and unable to "
        "mount an effective defense.");

    addPrerequisite("level",
        (["type": "level",
            "guild": "League of Assassins",
            "value": 19
        ]));
    addPrerequisite("/guilds/league-of-assassins/poison-craft/"
        "improved-sleep-draught.c",
        (["type": "research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 45);
    addSpecification("cooldown", 30);
    addSpecification("command template", "perfect sleep draught ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## administer##InitiatorReflexive## a perfectly "
        "formulated sedative that drops ##TargetName## in their tracks.");

    addSpecification("damage hit points", ({ ([
            "probability": 80,
            "base damage": 10,
            "range": 15
        ]),
        ([
            "probability": 20,
            "base damage": 20,
            "range": 25
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
            "rate": 0.3
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
            "rate": 0.3
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
    addSpecification("penalty to defense class", 5);
    addSpecification("duration", 40);
    addSpecification("consumables", (["vial of soporific draught": 1]));
}
