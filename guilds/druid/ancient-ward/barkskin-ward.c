//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Barkskin Ward");
    addSpecification("source", "druid");
    addSpecification("description", "This research allows the druid to harden their skin with natural magic, granting temporary protection.");

    addPrerequisite("/guilds/druid/ancient-ward/root.c",
        ([ "type": "research" ]));

    addPrerequisite("level", ([
        "type": "level",
        "guild": "druid",
        "value": 1
    ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 20);
    addSpecification("cooldown", 60);
    addSpecification("duration", 120);
    addSpecification("bonus defense", 4);
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
    addSpecification("command template", "barkskin ward");
    addSpecification("use ability message", "##InitiatorName## ##Infinitive::draw## natural energy inward, skin hardening like ancient bark.");
}
