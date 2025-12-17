//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Mind Fog");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of enveloping a target's mind in a disorienting fog of "
        "dream energy, hampering their ability to fight effectively.");
    addSpecification("usage summary", "A debilitating attack that reduces "
        "the target's combat effectiveness");

    addPrerequisite("/guilds/oneiromancer/dream-magic/dreamscape-shift.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 11
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 25);

    addSpecification("damage hit points", ({ ([
            "probability": 100,
            "base damage": 10,
            "range": 15
        ])
    }));

    addSpecification("damage type", "psionic");
    addSpecification("apply enfeebled", 1);
    addSpecification("duration", 60);

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/oneiromancer/dream-magic/dream-mastery.c",
            "name": "Dream Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/oneiromancer/dream-magic/oneiric-potency.c",
            "name": "Oneiric Potency",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/oneiromancer/dream-magic/nightmare-potency.c",
            "name": "Nightmare Potency",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "skill",
            "name": "mind",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.10
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.25
        ]),
    }));

    addSpecification("cooldown", 30);
    addSpecification("event handler", "mindFogEvent");
    addSpecification("command template", "mind fog [at ##Target##]");

    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::engulf## ##TargetName##'s mind in a disorienting fog "
        "of dream essence.");
}
