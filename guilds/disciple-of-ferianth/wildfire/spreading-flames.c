//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Spreading Flames");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of igniting all enemies in an area with spreading flames "
        "that deal damage and hinder their recovery.");
    addSpecification("usage summary", "Area DoT fire spell");

    addPrerequisite("/guilds/disciple-of-ferianth/wildfire/burning-brand.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 15
        ]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("spell point cost", 60);
    addSpecification("spell point cost modifiers", ([
        "/guilds/disciple-of-ferianth/wildfire/spreading-flames-efficiency.c": 15,
        "/guilds/disciple-of-ferianth/wildfire/wildfire-efficiency.c": 15
    ]));

    addSpecification("damage hit points", ({ ([
            "probability": 70,
            "base damage": 15,
            "range": 20
        ]),
        ([
            "probability": 25,
            "base damage": 25,
            "range": 35
        ]),
        ([
            "probability": 5,
            "base damage": 40,
            "range": 50
        ])
    }));
    addSpecification("damage type", "fire");

    addSpecification("penalty to heal hit points", 3);
    addSpecification("penalty to defense", 3);
    addSpecification("duration", 30);

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/wildfire/wildfire-mastery.c",
            "name": "Wildfire Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/wildfire/wildfire-potency.c",
            "name": "Wildfire Potency",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/wildfire/spreading-flames-potency.c",
            "name": "Spreading Flames Potency",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.50
        ]),
        ([
            "type": "skill",
            "name": "elemental fire",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.15
        ]),
        ([
            "type": "level",
            "name": "level",
            "formula": "logarithmic",
            "rate": 1.10
        ])
    }));

    addSpecification("cooldown", 45);
    addSpecification("cooldown modifiers", ([
        "/guilds/disciple-of-ferianth/wildfire/spreading-flames-swiftness.c": 10,
        "/guilds/disciple-of-ferianth/wildfire/wildfire-swiftness.c": 10
    ]));

    addSpecification("event handler", "spreadingFlamesEvent");
    addSpecification("command template", "spreading flames");

    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::unleash## spreading flames! Fire leaps from "
        "enemy to enemy, igniting all in its path.");
}
