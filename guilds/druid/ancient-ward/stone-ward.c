//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Stone Ward");
    addSpecification("source", "druid");
    addSpecification("description", "This research draws the endurance of stone into a protective barrier around the druid.");

    addPrerequisite("/guilds/druid/ancient-ward/root.c",
        ([ "type": "research" ]));

    addPrerequisite("level", ([
        "type": "level",
        "guild": "druid",
        "value": 9
    ]));

    addPrerequisite("/guilds/druid/ancient-ward/barkskin-ward.c",
        ([ "type": "research" ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 30);
    addSpecification("cooldown", 60);
    addSpecification("duration", 150);
    addSpecification("bonus defense", 6);
    addSpecification("bonus soak", 4);
    addSpecification("modifiers", ({
    ([
        "type": "skill",
        "name": "nature",
        "formula": "additive",
        "rate": 0.1
    ]),
    ([
        "type": "skill",
        "name": "spellcraft",
        "formula": "logarithmic",
        "rate": 1.25
    ]),
    ([
        "type": "level",
        "name": "druid",
        "formula": "logarithmic",
        "rate": 1.05
    ]),
    ([
        "type": "attribute",
        "name": "wisdom",
        "formula": "logarithmic",
        "rate": 1.15
    ]),
    }));
    addSpecification("command template", "stone ward");
    addSpecification("use ability message", "##InitiatorName## ##Infinitive::invoke## the strength of stone and a grey shimmer ##Infinitive::envelop## ##InitiatorObjective##.");
}
