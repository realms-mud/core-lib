//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Thorny Shield");
    addSpecification("source", "druid");
    addSpecification("description", "This research weaves a barrier of thorns and vines around the druid, deterring attackers.");

    addPrerequisite("/guilds/druid/ancient-ward/root.c",
        ([ "type": "research" ]));

    addPrerequisite("level", ([
        "type": "level",
        "guild": "druid",
        "value": 5
    ]));

    addPrerequisite("/guilds/druid/ancient-ward/barkskin-ward.c",
        ([ "type": "research" ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 25);
    addSpecification("cooldown", 60);
    addSpecification("duration", 120);
    addSpecification("bonus defense", 5);
    addSpecification("bonus soak", 3);
    addSpecification("bonus parry", 3);
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
    addSpecification("command template", "thorny shield");
    addSpecification("use ability message", "##InitiatorName## ##Infinitive::call## a shimmering barrier of thorned vines into being around ##InitiatorReflexive##.");
}
