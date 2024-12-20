//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Dueler's Dance");
    addSpecification("source", "bard");
    addSpecification("composite research",
        "/guilds/bard/compositions/root.c");
    addSpecification("composite type", "chorus lyric");
    addSpecification("composite class", "lyric");
    addSpecification("default composite description",
        "'Tis a dodgy fellow, full of grace.");

    addSpecification("description", "This skill provides the user with the "
        "knowledge of the great balladeer Reinlen's combat-driven songs. This "
        "lyric provides a boost to all allies' sword-swinging abilities.");

    addPrerequisite("level", 
        (["type": "level", 
          "guild": "bard",
          "value": 11 ]));
    addPrerequisite("singing",
        ([  "type": "skill",
            "value": 5
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
            "skills": ({ "dodge", "parry" }),
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

    addSpecification("spell point cost", 35);

    addSpecification("bonus dodge", 10);
    addSpecification("bonus parry", 10);

    addSpecification("duration", 20);

    addSpecification("event handler", "inspiringLyricEvent");
    addSpecification("use composite message", "##InitiatorName## ##Infinitive::harmonize##, '##CompositeSegment##'");
}
