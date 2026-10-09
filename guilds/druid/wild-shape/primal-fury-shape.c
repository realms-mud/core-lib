//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Primal Fury");
    addSpecification("source", "druid");
    addSpecification("description", "This research allows the druid to channel the collective fury of all wild things, entering a berserker state of absolute primal aggression.");

    addPrerequisite("/guilds/druid/wild-shape/root.c",
        ([ "type": "research" ]));

    addPrerequisite("level", ([
        "type": "level",
        "guild": "druid",
        "value": 21
    ]));

    addPrerequisite("/guilds/druid/wild-shape/bear-aspect.c",
        ([ "type": "research" ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 45);
    addSpecification("stamina point cost", 30);
    addSpecification("cooldown", 180);
    addSpecification("bonus attack", 6);
    addSpecification("bonus damage", 6);
    addSpecification("bonus strength", 3);
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
    addSpecification("command template", "primal fury");
    addSpecification("use ability activate message", "##InitiatorName## ##Infinitive::throw## ##InitiatorPossessive## head back, a primal roar ##Infinitive::tear## from ##InitiatorPossessive## throat as the raw fury of the wild ##Infinitive::suffuse## every motion.");
    addSpecification("use ability deactivate message", "##InitiatorName## ##Infinitive::release## the primal fury shape, returning to normal form.");
}
