//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Mystic Rhythms");
    addSpecification("source", "bard");
    addSpecification("composite research",
        "/guilds/bard/compositions/root.c");
    addSpecification("composite type", "instrumental rhythm");
    addSpecification("composite class", "percussion");
    addSpecification("default composite description",
        "syncopated 16th note groove");

    addSpecification("description", "This skill provides the user with the "
        "knowledge of creating basic percussive elements for songs. These "
        "heal all of your allies for several seconds.");

    addPrerequisite("level", 
        (["type": "level", 
          "guild": "bard",
          "value": 9 ]));

    addSpecification("limited by", ([
        "equipment":({ "instrument: percussion" }),
    ]));

    addPrerequisite("/guilds/bard/percussion/root.c",
        (["type":"research"]));

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/bard/percussion/keeping-time.c",
            "name": "Keeping Time",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.5
        ]),
        ([
            "type": "research",
            "research item": "/guilds/bard/percussion/advanced-timing.c",
            "name": "Advanced Timing",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/bard/percussion/modulated-timing.c",
            "name": "Modulated Timing",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/bard/percussion/fibonacci-timing.c",
            "name": "Fibonacci Timing",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/bard/percussion/golden-measures.c",
            "name": "Golden Measures",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/bard/compositions/verse-pre-chorus.c",
            "name": "Verse/Pre-Chorus/Chorus",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.1
        ]),
        ([
            "type": "skill",
            "name": "instrument: percussion",
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

    addSpecification("spell point cost", 125);

    addSpecification("bonus heal spell points", 50);
    addSpecification("bonus heal spell points rate", 50);
    addSpecification("bonus heal stamina", 50);
    addSpecification("bonus heal stamina rate", 50);
    addSpecification("duration", 6);

    addSpecification("event handler", "beatOfTheBrokenEvent");
    addSpecification("use composite message", "##InitiatorName## ##Infinitive::drum## in a ##CompositeSegment##");
}
