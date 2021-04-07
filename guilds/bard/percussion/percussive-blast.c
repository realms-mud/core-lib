//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Percussive Blast");
    addSpecification("source", "bard");
    addSpecification("composite research",
        "guilds/bard/compositions/root.c");
    addSpecification("composite type", "instrumental rhythm");
    addSpecification("composite class", "percussion");
    addSpecification("default composite description",
        "standard low 4/4 beat");

    addSpecification("description", "This skill provides the user with the "
        "knowledge of creating basic percussive elements for songs. "
        "For the next four rounds, the drummer unleashes a sonic attack.");

    addPrerequisite("level", 
        (["type": "level", 
          "guild": "bard",
          "value": 2 ]));

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
            "name": "verse-pre-chorus",
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

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("spell point cost", 15);

    addSpecification("bonus sonic attack", 10);
    addSpecification("duration", 8);

    addSpecification("event handler", "percussiveBlastEvent");
    addSpecification("use composite message", "##InitiatorName## "
    "rhythmically ##Infinitive::pound## ##InitiatorPossessive## "
    "##InitiatorWeapon## in a ##CompositeSegment##.");
}
