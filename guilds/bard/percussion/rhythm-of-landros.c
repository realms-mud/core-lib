//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Rhythm of Landros");
    addSpecification("source", "bard");
    addSpecification("composite research",
        "guilds/bard/compositions/root.c");
    addSpecification("composite type", "instrumental rhythm");
    addSpecification("composite class", "percussion");
    addSpecification("default composite description",
        "offbeat 16th groove");

    addSpecification("description", "This skill provides the user with the "
        "knowledge of creating basic percussive elements for songs. This "
        "reduces the cost of all allies' mana-based abilities.");

    addPrerequisite("level", ([  
        "type":"level",
        "guild": "bard",
        "value": 35
    ]));

    addSpecification("limited by", ([
        "equipment":({ "instrument: percussion" }),
    ]));

    addPrerequisite("guilds/bard/percussion/counterspell-knell.c",
        (["type":"research"]));

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "guilds/bard/percussion/beat-of-baxeros.c",
            "name": "beat-of-baxeros",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.5
        ]),
        ([
            "type": "research",
            "research item": "guilds/bard/percussion/baxteros-meter.c",
            "name": "baxteros-meter",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "guilds/bard/percussion/duotime-drive.c",
            "name": "duotime-drive",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "guilds/bard/percussion/percussion-mastery.c",
            "name": "percussion-mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "guilds/bard/compositions/verse-chorus-bridge.c",
            "name": "verse-chorus-bridge",
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

    addSpecification("spell point cost", 200);

    addSpecification("bonus reduce spell points", 50);
    addSpecification("bonus reduce stamina points", 50);

    addSpecification("duration", 20);

    addSpecification("event handler", "rhythmOfLandrosEvent");
    addSpecification("use composite message", "##InitiatorName## "
        "rhythmically ##Infinitive::rap## ##InitiatorPossessive## "
        "##InitiatorWeapon## in a ##CompositeSegment##.");    
}
