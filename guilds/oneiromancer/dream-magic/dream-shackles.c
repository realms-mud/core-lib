//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Dream Shackles");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of binding a target's limbs with chains of solidified "
        "dream energy, slowing their movements.");
    addSpecification("usage summary", "An attack that slows the target");

    addPrerequisite("/guilds/oneiromancer/dream-magic/sleep-of-ages.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 23
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 40);

    addSpecification("damage hit points", ({ ([
            "probability": 100,
            "base damage": 20,
            "range": 25
        ])
    }));

    addSpecification("damage type", "psionic");
    addSpecification("apply slow", 1);
    addSpecification("duration", 45);

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
            "rate": 0.15
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.15
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.30
        ]),
    }));

    addSpecification("cooldown", 45);
    addSpecification("event handler", "dreamShacklesEvent");
    addSpecification("command template", "dream shackles [at ##Target##]");

    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::conjure## chains of crystallized dream energy that "
        "wrap around ##TargetName##.");
}
