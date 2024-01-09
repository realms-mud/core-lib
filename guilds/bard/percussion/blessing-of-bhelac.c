//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Blessing of Bhelac");
    addSpecification("source", "bard");
    addSpecification("composite research",
        "/guilds/bard/compositions/root.c");
    addSpecification("composite type", "instrumental rhythm");
    addSpecification("composite class", "percussion");
    addSpecification("default composite description",
        "offbeat 8th");

    addSpecification("description", "This skill provides the user with the "
        "knowledge of creating basic percussive elements for songs. This "
        "provides a sonic enchantment to all allies' weapons.");

    addPrerequisite("level", ([  
        "type":"level",
        "guild": "bard",
        "value": 19
    ]));

    addSpecification("limited by", ([
        "equipment":({ "instrument: percussion" }),
    ]));

    addPrerequisite("/guilds/bard/percussion/counterspell-knell.c",
        (["type":"research"]));

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/bard/percussion/beat-of-baxeros.c",
            "name": "Beat of Baxeros",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.5
        ]),
        ([
            "type": "research",
            "research item": "/guilds/bard/percussion/baxteros-meter.c",
            "name": "Baxteros' Meter",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/bard/percussion/duotime-drive.c",
            "name": "Duotime Drive",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/bard/percussion/percussion-mastery.c",
            "name": "Percussion Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/bard/compositions/verse-chorus-bridge.c",
            "name": "Verse/Chorus/Bridge",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.1
        ]),
        ([
            "type": "skill",
            "name": "instrument: percussion",
            "formula": "additive",
            "rate": 0.10
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

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("spell point cost", 50);

    addSpecification("bonus sonic enchantment", 15);

    addSpecification("duration", 10);

    addSpecification("event handler", "blessingOfBhelacEvent");
    addSpecification("use composite message", "##InitiatorName## "
        "##Infinitive::thrum## ##InitiatorPossessive## "
        "##InitiatorWeapon## in a ##CompositeSegment##.");    
}
