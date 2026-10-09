//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
// See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Wasting Blight");
    addSpecification("source", "League of Assassins");
    addSpecification("description", "This research provides the user with "
        "the knowledge of the wasting blight technique. Derived from "
        "the spores of the dreaded deathcap mushroom, this compound "
        "inflicts both immediate damage and a creeping disease that "
        "saps the target's constitution and enfeebles them over time.");

    addPrerequisite("level",
        (["type": "level",
            "guild": "League of Assassins",
            "value": 31
        ]));
    addPrerequisite("/guilds/league-of-assassins/poison-craft/"
        "improved-contact-poison.c",
        (["type": "research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 50);
    addSpecification("cooldown", 15);
    addSpecification("command template", "wasting blight ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## expose##InitiatorReflexive## ##TargetName## "
        "to a withering blight compound.");

    addSpecification("damage hit points", ({ ([
            "probability": 70,
            "base damage": 30,
            "range": 35
        ]),
        ([
            "probability": 30,
            "base damage": 55,
            "range": 55
        ])
    }));
    addSpecification("damage type", "poison");

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item":
                "/guilds/league-of-assassins/poison-craft/"
                "improved-wasting-blight.c",
            "name": "Improved Wasting Blight",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item":
                "/guilds/league-of-assassins/poison-craft/"
                "blight-mastery.c",
            "name": "Blight Mastery",
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
            "rate": 0.75
        ])
    }));

    addSpecification("apply disease", 1);
    addSpecification("apply enfeebled", 1);
    addSpecification("duration", 30);
    addSpecification("consumables", (["vial of wasting blight": 1]));
}
