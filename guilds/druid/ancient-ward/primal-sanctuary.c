//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Primal Sanctuary");
    addSpecification("source", "druid");
    addSpecification("description", "This research creates a field of natural sanctuary around the druid, nature itself resisting intrusion.");

    addPrerequisite("/guilds/druid/ancient-ward/root.c",
        ([ "type": "research" ]));

    addPrerequisite("level", ([
        "type": "level",
        "guild": "druid",
        "value": 37
    ]));

    addPrerequisite("/guilds/druid/ancient-ward/ancestral-ward.c",
        ([ "type": "research" ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 60);
    addSpecification("cooldown", 120);
    addSpecification("duration", 200);
    addSpecification("bonus defense", 12);
    addSpecification("bonus soak", 7);
    addSpecification("bonus dodge", 6);
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
    addSpecification("command template", "primal sanctuary");
    addSpecification("use ability message", "##InitiatorName## ##Infinitive::invoke## the sanctuary of the primal wild, nature ##Infinitive::weave## a powerful barrier around ##InitiatorObjective##.");
}
