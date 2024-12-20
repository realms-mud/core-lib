//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Blast Beat");
    addSpecification("source", "bard");
    addSpecification("composite research",
        "/guilds/bard/compositions/root.c");
    addSpecification("composite type", "instrumental rhythm");
    addSpecification("composite class", "percussion");
    addSpecification("default composite description",
        "syncopated ostinato");

    addSpecification("description", "This skill provides the user with the "
        "knowledge of creating basic percussive elements for songs. "
        "For the next four rounds, the drummer unleashes an onslaught "
        "of sonic and pyrotechnic attacks.");

    addPrerequisite("level", 
        (["type": "level", 
          "guild": "bard",
          "value": 25 ]));

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
        ([
            "type":"attribute",
            "name": "dexterity",
            "formula": "additive",
            "rate": 0.05
        ]), 
        ([
            "type":"attribute",
            "name": "strength",
            "formula": "additive",
            "rate": 0.05
        ]), 
    }));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("spell point cost", 150);

    addSpecification("bonus sonic attack", 25);
    addSpecification("bonus chaos attack", 25);
    addSpecification("bonus fire attack", 25);
    addSpecification("bonus air attack", 25);
    addSpecification("duration", 8);

    addSpecification("event handler", "blastBeatEvent");
    addSpecification("use composite message", "##InitiatorName## "
    "rhythmically ##Infinitive::thrum## ##InitiatorPossessive## "
    "##InitiatorWeapon## in a ##CompositeSegment##.");
}
