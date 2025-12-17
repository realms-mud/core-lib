//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Eternal Slumber");
    addSpecification("source", "oneiromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of forcing a target into an unbreakable sleep filled with "
        "endless nightmares that drain their life force.");
    addSpecification("usage summary", "A powerful single-target attack that "
        "paralyzes and deals damage over time");

    addPrerequisite("/guilds/oneiromancer/dream-magic/mental-annihilation.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "oneiromancer",
            "value": 55
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 175);

    addSpecification("damage hit points", ({ ([
            "probability": 100,
            "base damage": 50,
            "range": 60
        ])
    }));

    addSpecification("damage type", "psionic");
    addSpecification("apply slow", 1);
    addSpecification("apply enfeebled", 1);
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
            "rate": 0.35
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.35
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.55
        ]),
    }));

    addSpecification("cooldown", 150);
    addSpecification("event handler", "eternalSlumberEvent");
    addSpecification("command template", "eternal slumber [at ##Target##]");

    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::force## ##TargetName## into an eternal slumber filled "
        "with endless nightmares.");
}
