//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Iron Grove");
    addSpecification("source", "druid");
    addSpecification("description", "This research channels the unyielding strength of an ancient ironwood grove into an immovable defense.");

    addPrerequisite("/guilds/druid/ancient-ward/root.c",
        ([ "type": "research" ]));

    addPrerequisite("level", ([
        "type": "level",
        "guild": "druid",
        "value": 29
    ]));

    addPrerequisite("/guilds/druid/ancient-ward/natures-embrace.c",
        ([ "type": "research" ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 50);
    addSpecification("cooldown", 120);
    addSpecification("duration", 200);
    addSpecification("bonus defense", 10);
    addSpecification("bonus soak", 6);
    addSpecification("bonus constitution", 2);
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
    addSpecification("command template", "iron grove");
    addSpecification("use ability message", "##InitiatorName## ##Infinitive::plant## ##InitiatorPossessive## feet firmly and ##Infinitive::invoke## the endurance of an ironwood grove, a powerful ward ##Infinitive::form## around ##InitiatorObjective##.");
}
