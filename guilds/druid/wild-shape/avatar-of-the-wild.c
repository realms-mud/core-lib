//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Avatar of the Wild");
    addSpecification("source", "druid");
    addSpecification("description", "This research allows the druid to channel the entirety of the primal wilderness, entering a transcendent combat state that blends the best of all wild natures.");

    addPrerequisite("/guilds/druid/wild-shape/root.c",
        ([ "type": "research" ]));

    addPrerequisite("level", ([
        "type": "level",
        "guild": "druid",
        "value": 37
    ]));

    addPrerequisite("/guilds/druid/wild-shape/primal-fury-shape.c",
        ([ "type": "research" ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 60);
    addSpecification("stamina point cost", 40);
    addSpecification("cooldown", 240);
    addSpecification("bonus attack", 8);
    addSpecification("bonus damage", 6);
    addSpecification("bonus dodge", 6);
    addSpecification("bonus defense", 6);
    addSpecification("bonus strength", 3);
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
    addSpecification("command template", "avatar of the wild");
    addSpecification("use ability activate message", "##InitiatorName## ##Infinitive::close## ##InitiatorPossessive## eyes briefly and the primal essence of the entire wild world ##Infinitive::flow## through ##InitiatorObjective## - every creature, every forest, every storm ##Infinitive::lend## its nature to the druid's form.");
    addSpecification("use ability deactivate message", "##InitiatorName## ##Infinitive::release## the avatar of the wild, returning to normal form.");
}
