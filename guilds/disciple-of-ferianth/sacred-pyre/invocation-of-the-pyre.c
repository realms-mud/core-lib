//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousRitualResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Invocation of the Pyre");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of performing a sacred ritual that invokes Ferianth's "
        "divine judgment upon a target. The ritual requires sacred incense "
        "but channels devastating holy fire.");

    addPrerequisite("/guilds/disciple-of-ferianth/sacred-pyre/root.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 7
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("consumables", ([
        "sacred incense": 1
    ]));

    addSpecification("damage hit points", ({ ([
            "probability": 70,
            "base damage": 75,
            "range": 100
        ]),
        ([
            "probability": 25,
            "base damage": 125,
            "range": 150
        ]),
        ([
            "probability": 5,
            "base damage": 200,
            "range": 200
        ])
    }));
    addSpecification("damage type", "fire");

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/sacred-pyre/amplified-invocation.c",
            "name": "Amplified Invocation",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/sacred-pyre/divine-invocation.c",
            "name": "Divine Invocation",
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
            "name": "theology",
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
            "type": "attribute",
            "name": "wisdom",
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

    addSpecification("cooldown", 120);
    addSpecification("cooldown modifiers", ([
        "/guilds/disciple-of-ferianth/sacred-pyre/hastened-invocation.c": 30,
    ]));
    addSpecification("event handler", "invocationOfThePyreEvent");
    addSpecification("command template", "invocation of the pyre [at ##Target##]");

    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::perform## the sacred rite of invocation. Holy fire "
        "erupts from the burning incense and ##Infinitive::engulf## "
        "##TargetName## in Ferianth's judgment.");
    addSpecification("use ability fail message", "##InitiatorName## "
        "##Infinitive::attempt## to perform the invocation, but "
        "##Infinitive::lack## the required sacred incense.");
}
