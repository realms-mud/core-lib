//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
// See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Improved Contact Poison");
    addSpecification("source", "League of Assassins");
    addSpecification("description", "This research provides the user with "
        "a more potent formulation of the contact poison technique. "
        "The improved compound penetrates skin faster and with greater "
        "intensity, slowing the target more severely and robbing them "
        "of their strength.");

    addPrerequisite("level",
        (["type": "level",
            "guild": "League of Assassins",
            "value": 13
        ]));
    addPrerequisite("/guilds/league-of-assassins/poison-craft/"
        "contact-poison.c",
        (["type": "research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 30);
    addSpecification("cooldown", 10);
    addSpecification("command template",
        "improved contact poison ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## press##InitiatorReflexive## a potent contact "
        "poison against ##TargetName##.");

    addSpecification("damage hit points", ({ ([
            "probability": 75,
            "base damage": 8,
            "range": 15
        ]),
        ([
            "probability": 25,
            "base damage": 15,
            "range": 25
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
            "rate": 0.3
        ]),
        ([
            "type": "skill",
            "name": "herbalism",
            "formula": "additive",
            "rate": 0.2
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
    addSpecification("duration", 25);
    addSpecification("consumables", (["vial of contact toxin": 1]));
}
