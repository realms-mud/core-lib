//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Loved Ones Twisted");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of inflicting the nightmare of loved ones transformed into "
        "monsters - familiar faces twisted with malice, beloved voices "
        "speaking hatred. The emotional devastation enfeebles the target. "
        "It can be used alone or as part of a combination attack.");
    addSpecification("usage summary", "Nightmare imagery of betrayal that "
        "enfeebles the target");

    addPrerequisite("/guilds/oneiromancer/dream-imagery/inescapable-maze.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 43
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("damage hit points", ({ ([
            "probability": 80,
            "base damage": 85,
            "range": 170
        ]),
        ([
            "probability": 20,
            "base damage": 170,
            "range": 340
        ])
    }));

    addSpecification("damage type", "psionic");

    // Persisted enfeebled effect
    addSpecification("apply enfeebled", 1);
    addSpecification("penalty to wisdom", 2);
    addSpecification("duration", 30);

    addSpecification("modifiers", ({ 
        ([
            "type": "skill",
            "name": "mind",
            "formula": "logarithmic",
            "rate": 1.10
        ]),
        ([
            "type": "skill",
            "name": "evocation",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type":"attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.5
        ]), 
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.5
        ]),
        ([
            "type": "attribute",
            "name": "charisma",
            "formula": "additive",
            "rate": 0.25
        ]),
    }));

    addSpecification("spell point cost", 75);
    addSpecification("cooldown", 40);

    addSpecification("event handler", "lovedOnesTwistedEvent");
    addSpecification("command template", "loved ones twisted [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::twist## ##TargetName##'s loved ones into nightmare "
        "monsters, the emotional devastation leaving ##TargetObjective## "
        "enfeebled.");
    addSpecification("use combination message", "##Infinitive::twist## "
        "loved ones into monsters");
}
