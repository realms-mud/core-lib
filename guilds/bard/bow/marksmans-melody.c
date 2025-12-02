//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Marksmans Melody");
    addSpecification("source", "bard");

    addSpecification("description", "This skill provides the user with the "
        "knowledge of a lyric that greatly improves their damage for their "
        "next attack with a bow.");

    addPrerequisite("level", 
        (["type": "level", 
          "guild": "bard",
          "value": 2 ]));

    addSpecification("limited by", (["equipment":({ "bow" })]));

    addPrerequisite("/guilds/bard/bow/root.c",
        (["type":"research"]));

    addSpecification("modifiers", ({ 
        ([
            "type": "weapon damage",
            "name" : "bow",
            "types" : ({ "bow" }),
            "formula" : "additive",
            "rate" : 1.75
        ]),
        ([
            "type": "skill",
            "name": "bow",
            "formula": "logarithmic",
            "rate": 1.25
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
            "type": "attribute",
            "name": "dexterity",
            "formula": "additive",
            "rate": 0.25
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.25
        ]),
    }));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 6);

    addSpecification("spell point cost", 25);

    addSpecification("bonus damage", 15);
    addSpecification("duration", 3);

    addSpecification("event handler", "marksmansMelodyEvent");
    addSpecification("command template", "marksman's melody");
    addSpecification("use ability message", "##InitiatorPossessive::Name## "
        "##Infinitive::sing##, `The arrow looses. The pain reduces thee to ash.'");
}
