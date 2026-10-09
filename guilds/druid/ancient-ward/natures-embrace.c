//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Nature's Embrace");
    addSpecification("source", "druid");
    addSpecification("description", "This research wraps the druid in a sustained embrace of natural forces, healing and protecting simultaneously.");

    addPrerequisite("/guilds/druid/ancient-ward/root.c",
        ([ "type": "research" ]));

    addPrerequisite("level", ([
        "type": "level",
        "guild": "druid",
        "value": 17
    ]));

    addPrerequisite("/guilds/druid/ancient-ward/stone-ward.c",
        ([ "type": "research" ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 40);
    addSpecification("cooldown", 90);
    addSpecification("duration", 180);
    addSpecification("bonus defense", 6);
    addSpecification("bonus soak", 3);
    addSpecification("bonus heal hit points rate", 4);
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
    addSpecification("command template", "natures embrace");
    addSpecification("use ability message", "##InitiatorName## ##Infinitive::close## ##InitiatorPossessive## eyes and ##Infinitive::draw## the healing embrace of nature around ##InitiatorReflexive##.");
}
