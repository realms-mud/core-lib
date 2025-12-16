//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Nightmare Apocalypse");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the ultimate nightmare - the end of all things. Every "
        "fear made manifest, every horror realized, existence itself screaming "
        "its final death cry. The capstone nightmare devastates all aspects of "
        "the target. It can be used alone or as part of a combination attack.");
    addSpecification("usage summary", "The ultimate nightmare that devastates "
        "with multiple damage types and severe debuffs");

    addPrerequisite("/guilds/oneiromancer/dream-imagery/death-of-self.c",
        (["type":"research"]));
    addPrerequisite("/guilds/oneiromancer/dream-imagery/unraveling-reality.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 67
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("damage hit points", ({ ([
            "probability": 70,
            "base damage": 150,
            "range": 300
        ]),
        ([
            "probability": 30,
            "base damage": 300,
            "range": 600
        ])
    }));

    addSpecification("damage type", "psionic");

    // Devastating persisted effects
    addSpecification("apply enfeebled", 1);
    addSpecification("apply slow", 1);
    addSpecification("penalty to intelligence", 3);
    addSpecification("penalty to wisdom", 3);
    addSpecification("penalty to attack", 10);
    addSpecification("penalty to defense", 10);
    addSpecification("duration", 45);

    addSpecification("modifiers", ({ 
        ([
            "type": "skill",
            "name": "mind",
            "formula": "logarithmic",
            "rate": 1.20
        ]),
        ([
            "type": "skill",
            "name": "evocation",
            "formula": "additive",
            "rate": 0.20
        ]),
        ([
            "type":"attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 1.0
        ]), 
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 1.0
        ]),
    }));

    addSpecification("spell point cost", 200);
    addSpecification("cooldown", 300);

    addSpecification("event handler", "nightmareApocalypseEvent");
    addSpecification("command template", "nightmare apocalypse [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::unleash## the nightmare apocalypse upon ##TargetName##, "
        "every fear made manifest, the end of all things burning through "
        "##TargetPossessive## mind.");
    addSpecification("use combination message", "##Infinitive::unleash## "
        "the nightmare apocalypse");
}
