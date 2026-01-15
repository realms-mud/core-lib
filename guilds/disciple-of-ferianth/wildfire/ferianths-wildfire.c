//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Ferianth's Wildfire");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of calling down Ferianth's divine wildfire, the ultimate "
        "expression of the god's consuming flames that devastates all foes.");
    addSpecification("usage summary", "Ultimate area DoT with devastating debuffs");

    addPrerequisite("/guilds/disciple-of-ferianth/wildfire/raging-wildfire.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 35
        ]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("spell point cost", 200);
    addSpecification("spell point cost modifiers", ([
        "/guilds/disciple-of-ferianth/wildfire/ferianths-wildfire-efficiency.c": 50,
        "/guilds/disciple-of-ferianth/wildfire/wildfire-efficiency.c": 50
    ]));

    addSpecification("damage hit points", ({ ([
            "probability": 50,
            "base damage": 80,
            "range": 100
        ]),
        ([
            "probability": 35,
            "base damage": 130,
            "range": 160
        ]),
        ([
            "probability": 15,
            "base damage": 200,
            "range": 250
        ])
    }));
    addSpecification("damage type", "fire");

    addSpecification("penalty to defense", 12);
    addSpecification("penalty to attack", 8);
    addSpecification("penalty to strength", 3);
    addSpecification("penalty to constitution", 2);
    addSpecification("penalty to heal hit points", 8);
    addSpecification("apply enfeebled", 1);
    addSpecification("duration", 60);

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
            "research item": "/guilds/disciple-of-ferianth/wildfire/ferianths-wildfire-potency.c",
            "name": "Ferianth's Wildfire Potency",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 2.00
        ]),
        ([
            "type": "skill",
            "name": "elemental fire",
            "formula": "additive",
            "rate": 0.25
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.30
        ]),
        ([
            "type": "level",
            "name": "level",
            "formula": "logarithmic",
            "rate": 1.20
        ])
    }));

    addSpecification("cooldown", 180);
    addSpecification("cooldown modifiers", ([
        "/guilds/disciple-of-ferianth/wildfire/ferianths-wildfire-swiftness.c": 45,
        "/guilds/disciple-of-ferianth/wildfire/wildfire-swiftness.c": 40
    ]));

    addSpecification("event handler", "ferianthsWildfireEvent");
    addSpecification("command template", "ferianths wildfire");

    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::call## down Ferianth's wildfire! Divine flames "
        "erupt from the heavens, consuming all foes with the "
        "god's sacred fury.");
}
