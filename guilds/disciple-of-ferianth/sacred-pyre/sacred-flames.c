//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Sacred Flames");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of invoking Ferianth's sacred flames to hinder enemies. "
        "All foes in the area are weakened by the holy fire's presence.");

    addPrerequisite("/guilds/disciple-of-ferianth/sacred-pyre/invocation-of-the-pyre.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 11
        ]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 100);

    addSpecification("penalty to attack", 5);
    addSpecification("penalty to defense", 5);
    addSpecification("duration", 60);

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/sacred-pyre/intensified-sacred-flames.c",
            "name": "Intensified Sacred Flames",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/sacred-pyre/overwhelming-sacred-flames.c",
            "name": "Overwhelming Sacred Flames",
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
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.05
        ])
    }));

    addSpecification("cooldown", 180);
    addSpecification("cooldown modifiers", ([
        "/guilds/disciple-of-ferianth/sacred-pyre/hastened-sacred-flames.c": 45,
    ]));
    addSpecification("event handler", "sacredFlamesEvent");
    addSpecification("command template", "sacred flames");

    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::call## upon Ferianth's sacred flames. An aura of "
        "divine fire radiates outward, weakening all enemies in the area.");
}
