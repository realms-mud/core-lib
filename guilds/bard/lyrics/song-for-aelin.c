//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Song for Aelin");
    addSpecification("source", "bard");
    addSpecification("composite research",
        "guilds/bard/compositions/root.c");
    addSpecification("composite type", "lyric");
    addSpecification("composite class", "lyric");
    addSpecification("default composite description",
        "She knows her life will fail when the dark chord flies...");

    addSpecification("description", "This skill provides the user with the "
        "knowledge of creating Landros the Skald's famous power well "
        "effects. With these, allied creatures can tap into hitherto "
        "unknown reserves.");

    addPrerequisite("level", 
        (["type": "level", 
          "guild": "bard",
          "value": 13 ]));
    addPrerequisite("singing",
        ([  "type": "skill",
            "value": 10
        ]));
    addPrerequisite("guilds/bard/lyrics/lay-of-landros.c",
        (["type":"research"]));

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "guilds/bard/lyrics/a-rhyme-of-the-deep.c",
            "name": "rhyme of the deep",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 2.0
        ]),
        ([
            "type": "research",
            "research item": "guilds/bard/lyrics/boon-of-landros.c",
            "name": "boon-of-landros",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.5
        ]),
        ([
            "type": "research",
            "research item": "guilds/bard/lyrics/day-is-coming.c",
            "name": "day-is-coming",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.5
        ]),
        ([
            "type": "research",
            "research item": "guilds/bard/lyrics/bloods-depth.c",
            "name": "bloods-depth",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.5
        ]),
        ([
            "type": "research",
            "research item": "guilds/bard/lyrics/into-the-dream.c",
            "name": "into-the-dream",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.5
        ]),
        ([
            "type": "research",
            "research item": "guilds/bard/compositions/simple-ballad.c",
            "name": "simple-ballad",
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

    addSpecification("bonus spell points", 25);
    addSpecification("bonus stamina points", 25);

    addSpecification("duration", 60);

    addSpecification("event handler", "aelinLyricEvent");
    addSpecification("use composite message", "##InitiatorName## emotively ##Infinitive::serenade##, '##CompositeSegment##'");
}
