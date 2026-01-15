//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Searing Devastation");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of unleashing searing devastation upon a single target, "
        "engulfing them in relentless flames that burn with divine fury.");
    addSpecification("usage summary", "Powerful single target DoT");

    addPrerequisite("/guilds/disciple-of-ferianth/wildfire/ferianths-wildfire.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 45
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("spell point cost", 175);
    addSpecification("spell point cost modifiers", ([
        "/guilds/disciple-of-ferianth/wildfire/searing-devastation-efficiency.c": 40,
        "/guilds/disciple-of-ferianth/wildfire/wildfire-efficiency.c": 35
    ]));

    addSpecification("damage hit points", ({ ([
            "probability": 50,
            "base damage": 35,
            "range": 45
        ]),
        ([
            "probability": 35,
            "base damage": 55,
            "range": 70
        ]),
        ([
            "probability": 15,
            "base damage": 85,
            "range": 100
        ])
    }));
    addSpecification("damage type", "fire");

    addSpecification("repeat effect", 7);
    addSpecification("repeat effect modifiers", ([
        "/guilds/disciple-of-ferianth/wildfire/searing-devastation-intensity.c": 3,
        "/guilds/disciple-of-ferianth/wildfire/wildfire-intensity.c": 2
    ]));
    addSpecification("repeated ability message", "Searing flames continue "
        "to devastate ##TargetName##!");

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
            "research item": "/guilds/disciple-of-ferianth/wildfire/searing-devastation-potency.c",
            "name": "Searing Devastation Potency",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.75
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
            "rate": 0.15
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
            "rate": 0.35
        ]),
        ([
            "type": "level",
            "name": "level",
            "formula": "logarithmic",
            "rate": 1.10
        ])
    }));

    addSpecification("cooldown", 90);
    addSpecification("cooldown modifiers", ([
        "/guilds/disciple-of-ferianth/wildfire/searing-devastation-swiftness.c": 20,
        "/guilds/disciple-of-ferianth/wildfire/wildfire-swiftness.c": 20
    ]));

    addSpecification("event handler", "searingDevastationEvent");
    addSpecification("command template", "searing devastation [at ##Target##]");

    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::unleash## searing devastation upon ##TargetName##! "
        "Divine flames engulf ##TargetObjective## completely.");
}
