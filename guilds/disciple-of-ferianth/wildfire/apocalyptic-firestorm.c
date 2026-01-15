//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Apocalyptic Firestorm");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of calling down an apocalyptic firestorm that engulfs "
        "all enemies in relentless waves of divine flame.");
    addSpecification("usage summary", "Devastating area DoT");

    addPrerequisite("/guilds/disciple-of-ferianth/wildfire/searing-devastation.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 55
        ]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("spell point cost", 275);
    addSpecification("spell point cost modifiers", ([
        "/guilds/disciple-of-ferianth/wildfire/apocalyptic-firestorm-efficiency.c": 65,
        "/guilds/disciple-of-ferianth/wildfire/wildfire-efficiency.c": 50
    ]));

    addSpecification("damage hit points", ({ ([
            "probability": 50,
            "base damage": 45,
            "range": 55
        ]),
        ([
            "probability": 35,
            "base damage": 70,
            "range": 90
        ]),
        ([
            "probability": 15,
            "base damage": 110,
            "range": 140
        ])
    }));
    addSpecification("damage type", "fire");

    addSpecification("repeat effect", 8);
    addSpecification("repeat effect modifiers", ([
        "/guilds/disciple-of-ferianth/wildfire/apocalyptic-firestorm-intensity.c": 4,
        "/guilds/disciple-of-ferianth/wildfire/wildfire-intensity.c": 2
    ]));
    addSpecification("repeated ability message", "The apocalyptic firestorm "
        "continues to rage!");

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
            "research item": "/guilds/disciple-of-ferianth/wildfire/apocalyptic-firestorm-potency.c",
            "name": "Apocalyptic Firestorm Potency",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 2.00
        ]),
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/wildfire/supreme-wildfire.c",
            "name": "Supreme Wildfire",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.50
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
            "formula": "additive",
            "rate": 0.05
        ]),
        ([
            "type": "skill",
            "name": "theology",
            "formula": "additive",
            "rate": 0.05
        ]),
        ([
            "type": "skill",
            "name": "magical essence",
            "formula": "additive",
            "rate": 0.05
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.40
        ]),
        ([
            "type": "level",
            "name": "level",
            "formula": "logarithmic",
            "rate": 1.15
        ])
    }));

    addSpecification("cooldown", 150);
    addSpecification("cooldown modifiers", ([
        "/guilds/disciple-of-ferianth/wildfire/apocalyptic-firestorm-swiftness.c": 35,
        "/guilds/disciple-of-ferianth/wildfire/wildfire-swiftness.c": 30
    ]));

    addSpecification("event handler", "apocalypticFirestormEvent");
    addSpecification("command template", "apocalyptic firestorm");

    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::call## down an apocalyptic firestorm! "
        "Waves of divine fire cascade from the heavens.");
}
