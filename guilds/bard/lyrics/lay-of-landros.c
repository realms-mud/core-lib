//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Lay of Landros");
    addSpecification("source", "bard");
    addSpecification("composite research",
        "/guilds/bard/compositions/root.c");
    addSpecification("composite type", "lyric");
    addSpecification("composite class", "lyric");
    addSpecification("default composite description",
        "In the darkest hour, you're not alone...");

    addSpecification("description", "This skill provides the user with the "
        "knowledge of creating Landros the Skald's famous power well "
        "effects. With these, allied creatures do not require as many "
        "spell or stamina points to use abilities.");

    addPrerequisite("level", 
        (["type": "level", 
          "guild": "bard",
          "value": 5 ]));
    addPrerequisite("singing",
        ([  "type": "skill",
            "value": 10
        ]));
    addPrerequisite("/guilds/bard/lyrics/root.c",
        (["type":"research"]));

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/bard/lyrics/a-rhyme-of-the-deep.c",
            "name": "A Rhyme of the Deep",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 2.0
        ]),
        ([
            "type": "research",
            "research item": "/guilds/bard/lyrics/boon-of-landros.c",
            "name": "Boon of Landros",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.5
        ]),
        ([
            "type": "research",
            "research item": "/guilds/bard/lyrics/day-is-coming.c",
            "name": "Day is Coming",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.5
        ]),
        ([
            "type": "research",
            "research item": "/guilds/bard/lyrics/bloods-depth.c",
            "name": "Blood's Depth",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.5
        ]),
        ([
            "type": "research",
            "research item": "/guilds/bard/lyrics/into-the-dream.c",
            "name": "Into the Dream",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.5
        ]),
        ([
            "type": "research",
            "research item": "/guilds/bard/compositions/simple-ballad.c",
            "name": "Simple Ballad",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.1
        ]),
        ([
            "type": "skill",
            "name": "singing",
            "formula": "additive",
            "base value": 10,
            "rate": 0.05
        ]),
        ([
            "type": "skill",
            "name": "dancing",
            "formula": "additive",
            "rate": 0.05
        ]), 
        ([
            "type": "skill",
            "name": "spellcraft",
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

    addSpecification("spell point cost", 25);

    addSpecification("bonus reduce spell points", 5);
    addSpecification("bonus reduce stamina points", 5);

    addSpecification("duration", 20);

    addSpecification("event handler", "layLyricEvent");
    addSpecification("use composite message", "##InitiatorName## rhythmically ##Infinitive::chant##, '##CompositeSegment##'");
}
