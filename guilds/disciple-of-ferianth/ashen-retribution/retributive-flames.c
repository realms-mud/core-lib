//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Retributive Flames");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of unleashing Ferianth's righteous fury upon enemies. "
        "Sacred flames erupt outward, dealing fire damage to all nearby foes.");

    addPrerequisite("/guilds/disciple-of-ferianth/ashen-retribution/ashen-ward.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 11
        ]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("spell point cost", 75);
    addSpecification("spell point cost modifiers", ([
        "/guilds/disciple-of-ferianth/ashen-retribution/efficient-flames.c": 15,
    ]));

    addSpecification("damage hit points", ({ ([
            "probability": 80,
            "base damage": 25,
            "range": 50
        ]),
        ([
            "probability": 20,
            "base damage": 50,
            "range": 100
        ])
    }));
    addSpecification("damage type", "fire");

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/ashen-retribution/intensified-flames.c",
            "name": "Intensified Flames",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/ashen-retribution/searing-retribution.c",
            "name": "Searing Retribution",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
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
            "formula": "additive",
            "rate": 0.05
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.05
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
        "/guilds/disciple-of-ferianth/ashen-retribution/hastened-flames.c": 15,
    ]));
    addSpecification("event handler", "retributiveFlamesEvent");
    addSpecification("command template", "retributive flames");

    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::release## a burst of retributive flames, searing "
        "all nearby foes with Ferianth's judgment.");
}
