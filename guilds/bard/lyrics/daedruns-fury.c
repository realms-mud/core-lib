//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Daedrun's Fury");
    addSpecification("source", "bard");
    addSpecification("composite research",
        "/guilds/bard/compositions/root.c");
    addSpecification("composite type", "lyric");
    addSpecification("composite class", "lyric");
    addSpecification("default composite description",
        "Mistakes and broken vows are all I know...");

    addSpecification("description", "This skill provides the user with the "
        "knowledge of Daedrun's Fury, a lyrical style of potent magic "
        "that emboldens ones defenses.");

    addPrerequisite("singing",
        ([  "type": "skill",
            "value": 7
        ]));

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "bard",
          "value": 7 ]));

    addPrerequisite("/guilds/bard/lyrics/inspiring-lyric.c",
        (["type":"research"]));

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/bard/lyrics/daedruns-might.c",
            "name": "Daedrun's Might",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 2.0
        ]),
        ([
            "type": "research",
            "research item": "/guilds/bard/lyrics/daedruns-sorrow.c",
            "name": "Daedrun's Sorrow",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.5
        ]),
        ([
            "type": "research",
            "research item": "/guilds/bard/lyrics/daedruns-regret.c",
            "name": "Daedrun's Regret",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.5
        ]),
        ([
            "type": "research",
            "research item": "/guilds/bard/lyrics/daedruns-despair.c",
            "name": "Daedrun's Despair",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.5
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

    addSpecification("spell point cost", 40);

    addSpecification("bonus defense", 1);
    addSpecification("bonus resist acid", 2);
    addSpecification("bonus resist air", 2);
    addSpecification("bonus resist chaos", 2);
    addSpecification("bonus resist cold", 2);
    addSpecification("bonus resist disease", 2);
    addSpecification("bonus resist earth", 2);
    addSpecification("bonus resist electricity", 2);
    addSpecification("bonus resist energy", 2);
    addSpecification("bonus resist evil", 2);
    addSpecification("bonus resist fire", 2);
    addSpecification("bonus resist good", 2);
    addSpecification("bonus resist magical", 2);
    addSpecification("bonus resist neutral", 2);
    addSpecification("bonus resist paralysis", 2);
    addSpecification("bonus resist physical", 2);
    addSpecification("bonus resist poison", 2);
    addSpecification("bonus resist psionic", 2);
    addSpecification("bonus resist sonic", 2);
    addSpecification("bonus resist undead", 2);
    addSpecification("bonus resist water", 2);

    addSpecification("duration", 20);

    addSpecification("event handler", "daedrunsFuryLyricEvent");
    addSpecification("use composite message", "##InitiatorName## ##Infinitive::croon##, '##CompositeSegment##'");
}
