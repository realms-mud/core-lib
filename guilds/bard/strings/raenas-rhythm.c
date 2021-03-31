//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        instantaneousActiveResearchItem::reset(arg);
        addSpecification("name", "Raena's Rhythm");
        addSpecification("source", "bard");
        addSpecification("composite research",
            "guilds/bard/compositions/root.c");
        addSpecification("composite type", "instrumental rhythm");
        addSpecification("composite class", "strings");
        addSpecification("default composite description",
            "riff going from Cm7b4 to Ab");

        addSpecification("description", "This research provides the user "
            "knowledge of creating searing riffs that cause sonic "
            "damage to all nearby enemies.");

        addSpecification("scope", "area");
        addSpecification("research type", "points");
        addSpecification("research cost", 1);
                
        addPrerequisite("level", 
            (["type": "level", 
              "guild": "bard",
              "value": 35 ]));

        addSpecification("limited by", ([
            "equipment":({ "instrument: plucked", "instrument: bowed" }),
        ]));

        addPrerequisite("guilds/bard/strings/requiem-of-release.c",
            (["type":"research"]));

        addSpecification("spell point cost", 350);
        addSpecification("damage hit points", ({ ([
                "probability": 90,
                "base damage": 100,
                "range": 200
            ]),
            ([
                "probability": 10,
                "base damage": 200,
                "range": 500
            ])
        }));
        addSpecification("damage spell points", ({ ([
                "probability":90,
                "base damage": 50,
                "range": 100
            ]),
            ([
                "probability": 10,
                "base damage": 100,
                "range": 200
            ])
        }));

        addSpecification("modifiers", ({ 
            ([
                "type": "research",
                "research item": "guilds/bard/strings/hammer-ons-and-pull-offs.c",
                "name": "keeping-time",
                "formula": "multiplicative",
                "base value": 1,
                "rate": 1.5
            ]),
            ([
                "type": "research",
                "research item": "guilds/bard/strings/string-bending.c",
                "name": "advanced-timing",
                "formula": "multiplicative",
                "base value": 1,
                "rate": 1.25
            ]),
            ([
                "type": "research",
                "research item": "guilds/bard/strings/slide-techniques.c",
                "name": "golden-measures",
                "formula": "multiplicative",
                "base value": 1,
                "rate": 1.25
            ]),
            ([
                "type": "research",
                "research item": "guilds/bard/strings/string-skipping.c",
                "name": "modulated-timing",
                "formula": "multiplicative",
                "base value": 1,
                "rate": 1.25
            ]),
            ([
                "type": "research",
                "research item": "guilds/bard/strings/finger-picking.c",
                "name": "fibonacci-timing",
                "formula": "multiplicative",
                "base value": 1,
                "rate": 1.25
            ]),
            ([
                "type": "research",
                "research item": "guilds/bard/compositions/ababcb.c",
                "name": "verse-pre-chorus",
                "formula": "multiplicative",
                "base value": 1,
                "rate": 1.1
            ]),
            ([
                "type": "weapon damage",
                "name" : "strings",
                "types" : ({ "instrument: plucked", "instrument: bowed" }),
                "formula" : "additive",
                "rate" : 1.0
            ]),
            ([
                "type": "highest skill",
                "name" : "instrument skills",
                "skills": ({ "instrument: plucked", "instrument: bowed" }),
                "formula" : "additive",
                "rate" : 0.5
            ]),
            ([
                "type": "skill",
                "name": "spellcraft",
                "formula": "additive",
                "rate": 0.10
            ]), 
            ([
                "type": "skill",
                "name": "senses",
                "formula": "additive",
                "rate": 0.05
            ]), 
            ([
                "type": "skill",
                "name": "magical essence",
                "formula": "logarithmic",
                "rate": 1.25
            ]), 
            ([
                "type": "skill",
                "name": "dancing",
                "formula": "additive",
                "rate": 0.05
            ]), 
            ([
                "type":"attribute",
                "name": "charisma",
                "formula": "additive",
                "rate": 0.05
            ]), 
            ([
                "type":"attribute",
                "name": "dexterity",
                "formula": "additive",
                "rate": 0.05
            ]),
        }));

        addSpecification("damage type", "sonic");
        addSpecification("event handler", "requiemOfReleaseEvent");
        addSpecification("use composite message", "##InitiatorName## "
            "vigorously ##Infinitive::strum## ##InitiatorPossessive## "
            "##InitiatorWeapon## in a ##CompositeSegment##.");
    }
}
