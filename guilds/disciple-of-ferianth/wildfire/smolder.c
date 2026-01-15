//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Smolder");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of igniting a target with smoldering flames that deal "
        "initial damage and continue to burn, hindering their recovery.");
    addSpecification("usage summary", "Single target DoT fire spell");

    addPrerequisite("/guilds/disciple-of-ferianth/wildfire/wildfire-root.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 3
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("spell point cost", 15);
    addSpecification("spell point cost modifiers", ([
        "/guilds/disciple-of-ferianth/wildfire/smolder-efficiency.c": 5,
        "/guilds/disciple-of-ferianth/wildfire/wildfire-efficiency.c": 3
    ]));

    addSpecification("damage hit points", ({ ([
            "probability": 80,
            "base damage": 8,
            "range": 12
        ]),
        ([
            "probability": 20,
            "base damage": 15,
            "range": 20
        ])
    }));
    addSpecification("damage type", "fire");

    addSpecification("penalty to heal hit points", 2);
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
            "research item": "/guilds/disciple-of-ferianth/wildfire/kindling.c",
            "name": "Kindling",
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
            "rate": 1.10
        ]),
        ([
            "type": "level",
            "name": "level",
            "formula": "logarithmic",
            "rate": 1.05
        ])
    }));

    addSpecification("cooldown", 8);
    addSpecification("cooldown modifiers", ([
        "/guilds/disciple-of-ferianth/wildfire/smolder-swiftness.c": 3,
        "/guilds/disciple-of-ferianth/wildfire/wildfire-swiftness.c": 2
    ]));

    addSpecification("event handler", "smolderEvent");
    addSpecification("command template", "smolder [at ##Target##]");

    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::ignite## ##TargetName## with smoldering flames!");
}
