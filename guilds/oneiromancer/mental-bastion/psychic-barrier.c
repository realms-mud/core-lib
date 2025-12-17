//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Psychic Barrier");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with "
        "knowledge of erecting a temporary psychic barrier.");

    addPrerequisite("/guilds/oneiromancer/mental-bastion/thought-shield.c",
        (["type":"research"]));

    addPrerequisite("guild rank",
        (["type": "guild rank",
            "guild": "oneiromancer",
            "value": ({ "mentalist", "psion", "master" })
        ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 9
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 50);

    addSpecification("bonus defense", 10);
    addSpecification("bonus resist psionic", 15);
    addSpecification("bonus resist magical", 10);
    addSpecification("duration", 60);

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/oneiromancer/mental-bastion/fortified-mind.c",
            "name": "Fortified Mind",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/oneiromancer/mental-bastion/impenetrable-mind.c",
            "name": "Impenetrable Mind",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.35
        ]),
        ([
            "type": "skill",
            "name": "mind",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "level",
            "name": "level",
            "formula": "logarithmic",
            "rate": 1.05
        ]),
    }));

    addSpecification("cooldown", 120);
    addSpecification("event handler", "psychicBarrierEvent");
    addSpecification("command template", "psychic barrier");

    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::erect## a shimmering psychic barrier around "
        "##InitiatorPossessive## mind.");
}
