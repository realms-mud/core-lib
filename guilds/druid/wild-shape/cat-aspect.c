//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Cat Aspect");
    addSpecification("source", "druid");
    addSpecification("description", "This research allows the druid to channel the lethal precision of the panther, entering a stance of swift strikes and perfect evasion.");

    addPrerequisite("/guilds/druid/wild-shape/root.c",
        ([ "type": "research" ]));

    addPrerequisite("level", ([
        "type": "level",
        "guild": "druid",
        "value": 11
    ]));

    addPrerequisite("/guilds/druid/wild-shape/wolf-aspect.c",
        ([ "type": "research" ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 35);
    addSpecification("stamina point cost", 20);
    addSpecification("cooldown", 120);
    addSpecification("bonus attack", 5);
    addSpecification("bonus dodge", 6);
    addSpecification("bonus dexterity", 3);
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
    addSpecification("command template", "cat aspect");
    addSpecification("use ability activate message", "##InitiatorName## ##Infinitive::flow## into a low, fluid stance, ##InitiatorPossessive## movements taking on the liquid grace of a hunting panther.");
    addSpecification("use ability deactivate message", "##InitiatorName## ##Infinitive::release## the cat aspect, returning to normal form.");
}
