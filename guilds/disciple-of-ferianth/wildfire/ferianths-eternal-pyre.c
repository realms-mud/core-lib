//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Ferianth's Eternal Pyre");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of invoking Ferianth's eternal pyre - the ultimate "
        "manifestation of the fire god's wrath. Enemies are consumed by "
        "flames that burn with the intensity of a thousand suns.");
    addSpecification("usage summary", "Ultimate area DoT - Ferianth's wrath");

    addPrerequisite("/guilds/disciple-of-ferianth/wildfire/apocalyptic-firestorm.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 65
        ]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("spell point cost", 400);
    addSpecification("spell point cost modifiers", ([
        "/guilds/disciple-of-ferianth/wildfire/ferianths-eternal-pyre-efficiency.c": 100,
        "/guilds/disciple-of-ferianth/wildfire/wildfire-efficiency.c": 75
    ]));

    addSpecification("damage hit points", ({ ([
            "probability": 45,
            "base damage": 60,
            "range": 80
        ]),
        ([
            "probability": 35,
            "base damage": 100,
            "range": 130
        ]),
        ([
            "probability": 20,
            "base damage": 160,
            "range": 200
        ])
    }));
    addSpecification("damage type", "fire");

    addSpecification("repeat effect", 10);
    addSpecification("repeat effect modifiers", ([
        "/guilds/disciple-of-ferianth/wildfire/ferianths-eternal-pyre-intensity.c": 5,
        "/guilds/disciple-of-ferianth/wildfire/wildfire-intensity.c": 3
    ]));
    addSpecification("repeated ability message", "Ferianth's eternal pyre "
        "continues to consume all in its path!");

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
            "research item": "/guilds/disciple-of-ferianth/wildfire/ferianths-eternal-pyre-potency.c",
            "name": "Ferianth's Eternal Pyre Potency",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 2.50
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
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/wildfire/divine-wildfire-mastery.c",
            "name": "Divine Wildfire Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.75
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
            "formula": "additive",
            "rate": 0.05
        ]),
        ([
            "type": "skill",
            "name": "theology",
            "formula": "additive",
            "rate": 0.10
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
            "rate": 0.50
        ]),
        ([
            "type": "level",
            "name": "level",
            "formula": "logarithmic",
            "rate": 1.20
        ])
    }));

    addSpecification("cooldown", 240);
    addSpecification("cooldown modifiers", ([
        "/guilds/disciple-of-ferianth/wildfire/ferianths-eternal-pyre-swiftness.c": 60,
        "/guilds/disciple-of-ferianth/wildfire/wildfire-swiftness.c": 45
    ]));

    addSpecification("event handler", "ferianthsEternalPyreEvent");
    addSpecification("command template", "ferianths eternal pyre");

    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::invoke## Ferianth's eternal pyre! The very air "
        "ignites as the fire god's wrath descends upon all foes.");
}
