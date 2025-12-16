//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Mind Spike");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of a technique that projects a piercing lance of psychic "
        "energy directly into the target's consciousness. It is a form that "
        "can either be done by itself or as part of a combination attack.");
    addSpecification("usage summary", "A piercing psionic attack that "
        "targets the mind directly");

    addPrerequisite("/guilds/oneiromancer/psionic-focus/focus-root.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 1
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("damage hit points", ({ ([
            "probability": 90,
            "base damage": 25,
            "range": 50
        ]),
        ([
            "probability": 10,
            "base damage": 50,
            "range": 100
        ])
    }));

    addSpecification("damage type", "psionic");

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/oneiromancer/psionic-focus/focused-intent.c",
            "name": "Focused Intent",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.10
        ]),
        ([
            "type": "research",
            "research item": "/guilds/oneiromancer/psionic-focus/penetrating-thought.c",
            "name": "Penetrating Thought",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "skill",
            "name": "mind",
            "formula": "logarithmic",
            "rate": 1.10
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.05
        ]),
        ([
            "type": "skill",
            "name": "senses",
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

    addSpecification("spell point cost", 15);
    addSpecification("cooldown", 6);

    addSpecification("event handler", "mindSpikeEvent");
    addSpecification("command template", "mind spike [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::fix## ##InitiatorPossessive## gaze on ##TargetName##, "
        "driving a spike of pure thought into ##TargetPossessive## mind.");
    addSpecification("use combination message", "##Infinitive::drive## "
        "a spike of pure thought");
}
