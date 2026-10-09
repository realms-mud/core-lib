//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Eagle Aspect");
    addSpecification("source", "druid");
    addSpecification("description", "This research allows the druid to channel the aerial precision of the eagle, entering a stance of blinding speed and keen-eyed strikes.");

    addPrerequisite("/guilds/druid/wild-shape/root.c",
        ([ "type": "research" ]));

    addPrerequisite("level", ([
        "type": "level",
        "guild": "druid",
        "value": 15
    ]));

    addPrerequisite("/guilds/druid/wild-shape/cat-aspect.c",
        ([ "type": "research" ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 35);
    addSpecification("stamina point cost", 20);
    addSpecification("cooldown", 120);
    addSpecification("bonus attack", 6);
    addSpecification("bonus parry", 4);
    addSpecification("bonus dexterity", 2);
    addSpecification("modifiers", ({
    ([
        "type": "skill",
        "name": "nature",
        "formula": "additive",
        "rate": 0.1
    ]),
    ([
        "type": "skill",
        "name": "unarmed",
        "formula": "additive",
        "rate": 0.15
    ]),
    ([
        "type": "level",
        "name": "druid",
        "formula": "logarithmic",
        "rate": 1.05
    ]),
    ([
        "type": "attribute",
        "name": "strength",
        "formula": "logarithmic",
        "rate": 1.15
    ]),
    ([
        "type": "attribute",
        "name": "constitution",
        "formula": "additive",
        "rate": 0.05
    ]),
    }));
    addSpecification("command template", "eagle aspect");
    addSpecification("use ability activate message", "##InitiatorName## ##Infinitive::straighten## with sudden intensity, ##InitiatorPossessive## eyes ##Infinitive::sharpen## to the keen focus of a hunting eagle.");
    addSpecification("use ability deactivate message", "##InitiatorName## ##Infinitive::release## the eagle aspect, returning to normal form.");
}
