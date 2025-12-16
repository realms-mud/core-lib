//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Inescapable Maze");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of trapping the target in the nightmare of an endless "
        "labyrinth - every turn leading back, every exit false, the walls "
        "closing in. The disorientation impairs the target's combat abilities. "
        "It can be used alone or as part of a combination attack.");
    addSpecification("usage summary", "Nightmare imagery of a maze that "
        "penalizes attack and dodge");

    addPrerequisite("/guilds/oneiromancer/dream-imagery/exposed-judged.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 35
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("damage hit points", ({ ([
            "probability": 80,
            "base damage": 70,
            "range": 140
        ]),
        ([
            "probability": 20,
            "base damage": 140,
            "range": 280
        ])
    }));

    addSpecification("damage type", "psionic");

    // Persisted combat penalties
    addSpecification("penalty to attack", 8);
    addSpecification("penalty to dodge", 5);
    addSpecification("penalty to parry", 5);
    addSpecification("duration", 25);

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
    }));

    addSpecification("spell point cost", 60);
    addSpecification("cooldown", 35);

    addSpecification("event handler", "inescapableMazeEvent");
    addSpecification("command template", "inescapable maze [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::trap## ##TargetName## in the nightmare of an "
        "inescapable maze, disorienting ##TargetObjective## completely.");
    addSpecification("use combination message", "##Infinitive::trap## "
        "in an inescapable maze");
}
