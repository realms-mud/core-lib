//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Maceman's Melody");
    addSpecification("source", "bard");
    addSpecification("composite research",
        "/guilds/bard/compositions/root.c");
    addSpecification("composite type", "chorus lyric");
    addSpecification("composite class", "lyric");
    addSpecification("default composite description",
        "I'll bash you and smash you and mash you...");

    addSpecification("description", "This skill provides the user with the "
        "knowledge of the great balladeer Reinlen's combat-driven songs. This "
        "lyric provides a boost to all allies' mace-swinging abilities.");

    addPrerequisite("level", 
        (["type": "level", 
          "guild": "bard",
          "value": 19 ]));
    addPrerequisite("singing",
        ([  "type": "skill",
            "value": 15
        ]));
    addPrerequisite("/guilds/bard/lyrics/root.c",
        (["type":"research"]));

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/bard/compositions/abacbaa.c",
            "name": "ABACBAA",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.1
        ]),
        ([
            "type": "highest skill",
            "name" : "sword skills",
            "skills": ({ "mace", "flail", }),
            "formula" : "additive",
            "rate" : 0.5
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
            "type": "skill",
            "name": "acrobatics",
            "formula": "additive",
            "rate": 0.05
        ]),
        ([
            "type": "skill",
            "name": "anatomy and physiology",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "skill",
            "name": "physics",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "skill",
            "name": "mathematics",
            "formula": "additive",
            "rate": 0.10
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

    addSpecification("spell point cost", 35);

    addSpecification("bonus mace", 10);
    addSpecification("bonus flail", 10);

    addSpecification("duration", 20);

    addSpecification("event handler", "inspiringLyricEvent");
    addSpecification("use composite message", "##InitiatorName## ##Infinitive::sing##, '##CompositeSegment##'");
}
