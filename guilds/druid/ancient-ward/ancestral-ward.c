//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Ancestral Ward");
    addSpecification("source", "druid");
    addSpecification("description", "This research invokes the protection of the ancient druids, wrapping the caster in their power.");

    addPrerequisite("/guilds/druid/ancient-ward/root.c",
        ([ "type": "research" ]));

    addPrerequisite("level", ([
        "type": "level",
        "guild": "druid",
        "value": 23
    ]));

    addPrerequisite("/guilds/druid/ancient-ward/wild-aura.c",
        ([ "type": "research" ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 45);
    addSpecification("cooldown", 90);
    addSpecification("duration", 180);
    addSpecification("bonus defense", 8);
    addSpecification("bonus soak", 5);
    addSpecification("bonus parry", 4);
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
    addSpecification("command template", "ancestral ward");
    addSpecification("use ability message", "##InitiatorName## ##Infinitive::call## upon the spirit-druids of old and a nimbus of ancient power ##Infinitive::surround## ##InitiatorObjective##.");
}
