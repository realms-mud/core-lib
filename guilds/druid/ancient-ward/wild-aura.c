//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Wild Aura");
    addSpecification("source", "druid");
    addSpecification("description", "This research surrounds the druid with an aura of primal energy that repels hostile intent.");

    addPrerequisite("/guilds/druid/ancient-ward/root.c",
        ([ "type": "research" ]));

    addPrerequisite("level", ([
        "type": "level",
        "guild": "druid",
        "value": 13
    ]));

    addPrerequisite("/guilds/druid/ancient-ward/thorny-shield.c",
        ([ "type": "research" ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 35);
    addSpecification("cooldown", 90);
    addSpecification("duration", 150);
    addSpecification("bonus defense", 7);
    addSpecification("bonus dodge", 4);
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
    addSpecification("command template", "wild aura");
    addSpecification("use ability message", "##InitiatorName## ##Infinitive::radiate## with the raw energy of the untamed wild, a palpable aura of primal power.");
}
