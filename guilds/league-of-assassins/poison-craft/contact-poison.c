//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
// See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Contact Poison");
    addSpecification("source", "League of Assassins");
    addSpecification("description", "This research provides the user with "
        "the knowledge of a fast-acting contact poison applied to the "
        "assassin's gloves or hand-wrap. A touch is sufficient to "
        "introduce the toxin, bypassing the need for a cutting wound "
        "and leaving the target slowed and enfeebled.");

    addPrerequisite("level",
        (["type": "level",
            "guild": "League of Assassins",
            "value": 5
        ]));
    addPrerequisite("/guilds/league-of-assassins/poison-craft/root.c",
        (["type": "research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 20);
    addSpecification("cooldown", 10);
    addSpecification("command template", "contact poison ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## brush##InitiatorReflexive## a poison-coated "
        "hand against ##TargetName##.");

    addSpecification("damage hit points", ({ ([
            "probability": 80,
            "base damage": 3,
            "range": 8
        ]),
        ([
            "probability": 20,
            "base damage": 8,
            "range": 15
        ])
    }));
    addSpecification("damage type", "poison");

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item":
                "/guilds/league-of-assassins/poison-craft/"
                "improved-contact-poison.c",
            "name": "Improved Contact Poison",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
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
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.2
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
    addSpecification("duration", 20);
    addSpecification("consumables", (["vial of contact toxin": 1]));
}
