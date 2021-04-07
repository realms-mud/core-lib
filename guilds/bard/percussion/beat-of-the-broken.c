//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Beat of the Broken");
    addSpecification("source", "bard");
    addSpecification("composite research",
        "guilds/bard/compositions/root.c");
    addSpecification("composite type", "instrumental rhythm");
    addSpecification("composite class", "percussion");
    addSpecification("default composite description",
        "16th note groove");

    addSpecification("description", "This skill provides the user with the "
        "knowledge of creating basic percussive elements for songs. These "
        "heal all of your allies for several seconds.");

    addPrerequisite("level", 
        (["type": "level", 
          "guild": "bard",
          "value": 5 ]));

    addSpecification("limited by", ([
        "equipment":({ "instrument: percussion" }),
    ]));

    addPrerequisite("guilds/bard/percussion/root.c",
        (["type":"research"]));

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "guilds/bard/percussion/keeping-time.c",
            "name": "keeping-time",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.5
        ]),
        ([
            "type": "research",
            "research item": "guilds/bard/percussion/advanced-timing.c",
            "name": "advanced-timing",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "guilds/bard/percussion/modulated-timing.c",
            "name": "modulated-timing",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "guilds/bard/percussion/fibonacci-timing.c",
            "name": "fibonacci-timing",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "guilds/bard/percussion/golden-measures.c",
            "name": "golden-measures",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "guilds/bard/compositions/verse-pre-chorus.c",
            "name": "aaba",
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

    addSpecification("spell point cost", 75);

    addSpecification("bonus heal hit points", 50);
    addSpecification("bonus heal hit points rate", 50);
    addSpecification("duration", 6);

    addSpecification("event handler", "beatOfTheBrokenEvent");
    addSpecification("use composite message", "##InitiatorName## "
        "##Infinitive::rap## ##InitiatorPossessive## "
        "##InitiatorWeapon## in a ##CompositeSegment##.");
}
