//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Runic Devastation");
    addSpecification("source", "runeskald");
    addSpecification("description", "The runeskald channels all the power "
        "of their body runes into a single devastating sweep, striking "
        "all enemies in range.");

    addPrerequisite("level",
        (["type": "level", "guild": "runeskald", "value": 15]));
    addPrerequisite("/guilds/runeskald/rune-warrior/runic-whirlwind.c",
        (["type": "research"]));
    addPrerequisite("/guilds/runeskald/rune-warrior/rune-surge.c",
        (["type": "research"]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 20);
    addSpecification("command template", "runic devastation");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::unleash## all the power of their runes in a sweeping devastation of everything nearby.");

    addSpecification("spell point cost", 35);
    addSpecification("stamina point cost", 30);

    addSpecification("damage hit points", ({
        ([
            "probability": 65,
            "base damage": 90,
            "range": 100
        ]),
        ([
            "probability": 35,
            "base damage": 165,
            "range": 150
        ])
    }));

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/runeskald/rune-warrior/warriors-might.c",
            "name": "warriors-might",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/runeskald/rune-warrior/warriors-endurance.c",
            "name": "warriors-endurance",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/runeskald/rune-warrior/warriors-tempo.c",
            "name": "warriors-tempo",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/runeskald/rune-warrior/warriors-might-ii.c",
            "name": "warriors-might-ii",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/runeskald/rune-warrior/warriors-endurance-ii.c",
            "name": "warriors-endurance-ii",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/runeskald/rune-warrior/warriors-tempo-ii.c",
            "name": "warriors-tempo-ii",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/runeskald/rune-warrior/warriors-might-iii.c",
            "name": "warriors-might-iii",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "attribute",
            "name": "strength",
            "formula": "additive",
            "rate": 0.12
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "additive",
            "rate": 0.09
        ])
    }));
    addSpecification("consumables", (["ancient blade rune": 1]));
}
