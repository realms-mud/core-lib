//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Wolf Aspect");
    addSpecification("source", "druid");
    addSpecification("description", "This research allows the druid to channel the hunting fury of the wolf, entering a stance of swift, coordinated aggression.");

    addPrerequisite("/guilds/druid/wild-shape/root.c",
        ([ "type": "research" ]));

    addPrerequisite("level", ([
        "type": "level",
        "guild": "druid",
        "value": 3
    ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 25);
    addSpecification("stamina point cost", 15);
    addSpecification("cooldown", 120);
    addSpecification("bonus attack", 4);
    addSpecification("bonus dodge", 4);
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
    addSpecification("command template", "wolf aspect");
    addSpecification("use ability activate message", "##InitiatorName## ##Infinitive::draw## inward and ##Infinitive::invoke## the hunting spirit of the wolf, movement becoming fluid and predatory.");
    addSpecification("use ability deactivate message", "##InitiatorName## ##Infinitive::release## the wolf aspect, returning to normal form.");
}
