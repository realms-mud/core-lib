//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Dirge of the Deft");
    addSpecification("source", "bard");

    addSpecification("description", "This skill provides the user with the "
        "knowledge of a lyric that greatly improves their ability to block "
        "and avoid attacks.");

    addPrerequisite("level", 
        (["type": "level", 
          "guild": "bard",
          "value": 5 ]));

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
    addSpecification("cooldown", 20);

    addSpecification("spell point cost", 50);

    addSpecification("bonus soak", 10);
    addSpecification("bonus dodge", 10);
    addSpecification("bonus parry", 10);
    addSpecification("duration", 12);

    addSpecification("event handler", "dirgeOfTheDeftEvent");
    addSpecification("command template", "dirge of the deft");
    addSpecification("use ability message", "##InitiatorPossessive::Name## "
        "##Infinitive::sing##, `Your fate is to fail. Your fall, my boon.'");
}
