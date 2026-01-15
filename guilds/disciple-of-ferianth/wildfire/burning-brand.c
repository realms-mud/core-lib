//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Burning Brand");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of searing a target with a burning brand that deals "
        "damage over time as the sacred flames consume them.");
    addSpecification("usage summary", "DoT fire spell - damage repeats over time");

    addPrerequisite("/guilds/disciple-of-ferianth/wildfire/smolder.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 9
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("spell point cost", 35);
    addSpecification("spell point cost modifiers", ([
        "/guilds/disciple-of-ferianth/wildfire/burning-brand-efficiency.c": 10,
        "/guilds/disciple-of-ferianth/wildfire/wildfire-efficiency.c": 8
    ]));

    addSpecification("damage hit points", ({ ([
            "probability": 70,
            "base damage": 12,
            "range": 18
        ]),
        ([
            "probability": 25,
            "base damage": 20,
            "range": 28
        ]),
        ([
            "probability": 5,
            "base damage": 30,
            "range": 40
        ])
    }));
    addSpecification("damage type", "fire");

    addSpecification("repeat effect", 4);
    addSpecification("repeat effect modifiers", ([
        "/guilds/disciple-of-ferianth/wildfire/burning-brand-intensity.c": 2,
        "/guilds/disciple-of-ferianth/wildfire/wildfire-intensity.c": 1
    ]));
    addSpecification("repeated ability message", "The burning brand continues "
        "to sear ##TargetName##!");

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
            "research item": "/guilds/disciple-of-ferianth/wildfire/burning-brand-potency.c",
            "name": "Burning Brand Potency",
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
            "rate": 0.25
        ]),
        ([
            "type": "level",
            "name": "level",
            "formula": "logarithmic",
            "rate": 1.05
        ])
    }));

    addSpecification("cooldown", 20);
    addSpecification("cooldown modifiers", ([
        "/guilds/disciple-of-ferianth/wildfire/burning-brand-swiftness.c": 5,
        "/guilds/disciple-of-ferianth/wildfire/wildfire-swiftness.c": 5
    ]));

    addSpecification("event handler", "burningBrandEvent");
    addSpecification("command template", "burning brand [at ##Target##]");

    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::sear## ##TargetName## with a burning brand! "
        "Sacred fire brands ##TargetPossessive## flesh.");
}
