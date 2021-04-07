//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Demoralizing Lyrics");
    addSpecification("source", "bard");
    addSpecification("composite research",
        "guilds/bard/compositions/root.c");
    addSpecification("composite type", "lyric");
    addSpecification("composite class", "lyric");
    addSpecification("default composite description",
        "'Twas a day full of malfeance...");

    addSpecification("description", "This skill provides the user with the "
        "knowledge of creating basic demoralizing lyrics for songs. These "
        "provide a penalty to all foes' morale and combat abilities.");

    addPrerequisite("singing",
        ([  "type": "skill",
            "value": 5
        ]));
    addPrerequisite("guilds/bard/lyrics/root.c",
        (["type":"research"]));

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "guilds/bard/lyrics/silver-tongue.c",
            "name": "silver-tongue",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 2.0
        ]),
        ([
            "type": "research",
            "research item": "guilds/bard/compositions/abac.c",
            "name": "abac",
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
            "type": "attribute",
            "name": "charisma",
            "formula": "additive",
            "rate": 0.05
        ]), 
    }));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("spell point cost", 15);

    addSpecification("penalty to attack", 2);
    addSpecification("penalty to defense", 1);
    addSpecification("penalty to damage", 1);

    addSpecification("duration", 20);

    addSpecification("event handler", "demoralizingLyricEvent");
    addSpecification("use composite message", "##InitiatorName## poetically ##Infinitive::lilt##, '##CompositeSegment##'");
}
