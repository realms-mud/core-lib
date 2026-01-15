//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Conflagration");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of engulfing a target in a raging conflagration that "
        "deals massive damage and severely weakens them.");
    addSpecification("usage summary", "Powerful single target DoT with major debuffs");

    addPrerequisite("/guilds/disciple-of-ferianth/wildfire/spreading-flames.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 21
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("spell point cost", 85);
    addSpecification("spell point cost modifiers", ([
        "/guilds/disciple-of-ferianth/wildfire/conflagration-efficiency.c": 20,
        "/guilds/disciple-of-ferianth/wildfire/wildfire-efficiency.c": 20
    ]));

    addSpecification("damage hit points", ({ ([
            "probability": 60,
            "base damage": 45,
            "range": 55
        ]),
        ([
            "probability": 30,
            "base damage": 70,
            "range": 85
        ]),
        ([
            "probability": 10,
            "base damage": 100,
            "range": 120
        ])
    }));
    addSpecification("damage type", "fire");

    addSpecification("penalty to defense", 8);
    addSpecification("penalty to attack", 5);
    addSpecification("penalty to heal hit points", 5);
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
            "research item": "/guilds/disciple-of-ferianth/wildfire/conflagration-potency.c",
            "name": "Conflagration Potency",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.75
        ]),
        ([
            "type": "skill",
            "name": "elemental fire",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.20
        ]),
        ([
            "type": "level",
            "name": "level",
            "formula": "logarithmic",
            "rate": 1.10
        ])
    }));

    addSpecification("cooldown", 60);
    addSpecification("cooldown modifiers", ([
        "/guilds/disciple-of-ferianth/wildfire/conflagration-swiftness.c": 15,
        "/guilds/disciple-of-ferianth/wildfire/wildfire-swiftness.c": 15
    ]));

    addSpecification("event handler", "conflagrationEvent");
    addSpecification("command template", "conflagration [at ##Target##]");

    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::engulf## ##TargetName## in a raging conflagration! "
        "Sacred fire consumes ##TargetObjective## utterly.");
}
