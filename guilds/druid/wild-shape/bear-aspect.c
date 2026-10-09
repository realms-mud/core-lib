//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Bear Aspect");
    addSpecification("source", "druid");
    addSpecification("description", "This research allows the druid to channel the immovable strength of the bear, entering a stance of overwhelming physical power.");

    addPrerequisite("/guilds/druid/wild-shape/root.c",
        ([ "type": "research" ]));

    addPrerequisite("level", ([
        "type": "level",
        "guild": "druid",
        "value": 7
    ]));

    addPrerequisite("/guilds/druid/wild-shape/wolf-aspect.c",
        ([ "type": "research" ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 30);
    addSpecification("stamina point cost", 20);
    addSpecification("cooldown", 120);
    addSpecification("bonus attack", 4);
    addSpecification("bonus damage", 4);
    addSpecification("bonus strength", 2);
    addSpecification("bonus soak", 2);
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
    addSpecification("command template", "bear aspect");
    addSpecification("use ability activate message", "##InitiatorName## ##Infinitive::draw## upon the primal strength of the bear, ##InitiatorPossessive## posture ##Infinitive::become## heavy and imposing.");
    addSpecification("use ability deactivate message", "##InitiatorName## ##Infinitive::release## the bear aspect, returning to normal form.");
}
