//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Raging Wildfire");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of unleashing a raging wildfire upon all enemies, "
        "dealing devastating damage and enfeebling them.");
    addSpecification("usage summary", "Powerful area DoT with enfeeble");

    addPrerequisite("/guilds/disciple-of-ferianth/wildfire/conflagration.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 27
        ]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("spell point cost", 130);
    addSpecification("spell point cost modifiers", ([
        "/guilds/disciple-of-ferianth/wildfire/raging-wildfire-efficiency.c": 30,
        "/guilds/disciple-of-ferianth/wildfire/wildfire-efficiency.c": 30
    ]));

    addSpecification("damage hit points", ({ ([
            "probability": 55,
            "base damage": 50,
            "range": 65
        ]),
        ([
            "probability": 35,
            "base damage": 80,
            "range": 100
        ]),
        ([
            "probability": 10,
            "base damage": 120,
            "range": 150
        ])
    }));
    addSpecification("damage type", "fire");

    addSpecification("penalty to defense", 8);
    addSpecification("penalty to attack", 5);
    addSpecification("penalty to heal hit points", 5);
    addSpecification("apply enfeebled", 1);
    addSpecification("duration", 45);

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
            "research item": "/guilds/disciple-of-ferianth/wildfire/raging-wildfire-potency.c",
            "name": "Raging Wildfire Potency",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.75
        ]),
        ([
            "type": "skill",
            "name": "elemental fire",
            "formula": "additive",
            "rate": 0.20
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.25
        ]),
        ([
            "type": "level",
            "name": "level",
            "formula": "logarithmic",
            "rate": 1.15
        ])
    }));

    addSpecification("cooldown", 120);
    addSpecification("cooldown modifiers", ([
        "/guilds/disciple-of-ferianth/wildfire/raging-wildfire-swiftness.c": 25,
        "/guilds/disciple-of-ferianth/wildfire/wildfire-swiftness.c": 25
    ]));

    addSpecification("event handler", "ragingWildfireEvent");
    addSpecification("command template", "raging wildfire");

    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::unleash## a raging wildfire! Sacred flames "
        "sweep through the area, consuming all enemies.");
}
