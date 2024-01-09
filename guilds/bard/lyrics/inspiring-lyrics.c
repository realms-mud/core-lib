//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Inspiring Lyrics");
    addSpecification("source", "bard");
    addSpecification("composite research",
        "/guilds/bard/compositions/root.c");
    addSpecification("composite type", "lyric");
    addSpecification("composite class", "lyric");
    addSpecification("default composite description",
        "I'll tell you a tale that is terribly true...");

    addSpecification("description", "This skill provides the user with the "
        "knowledge of creating basic inspirational lyrics for songs. These "
        "provide a boost to all allies' morale and combat abilities.");

    addPrerequisite("singing",
        ([  "type": "skill",
            "value": 5
        ]));
    addPrerequisite("/guilds/bard/lyrics/root.c",
        (["type":"research"]));

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/bard/lyrics/silver-tongue.c",
            "name": "Silver Tongue",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 2.0
        ]),
        ([
            "type": "research",
            "research item": "/guilds/bard/compositions/aaba.c",
            "name": "AABA",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.1
        ]),
        ([
            "type": "skill",
            "name": "singing",
            "formula": "additive",
            "rate": 0.05
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
    }));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("spell point cost", 15);

    addSpecification("bonus attack", 2);
    addSpecification("bonus defense", 1);
    addSpecification("bonus damage", 1);

    addSpecification("duration", 20);

    addSpecification("event handler", "inspiringLyricEvent");
    addSpecification("use composite message", "##InitiatorName## ##Infinitive::sing##, '##CompositeSegment##'");
}
