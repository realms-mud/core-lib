//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Frost Chain");
    addSpecification("source", "runeskald");
    addSpecification("description", "Glacial rune-ice arcs between multiple "
        "nearby enemies in rapid sequence, chilling each one.");

    addPrerequisite("level",
        (["type": "level", "guild": "runeskald", "value": 6]));
    addPrerequisite("/guilds/runeskald/frostfire/frost-lance.c",
        (["type": "research"]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 20);
    addSpecification("command template", "frost chain");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::unleash## a chain of glacial rune-ice that arcs between nearby foes.");

    addSpecification("spell point cost", 32);
    addSpecification("stamina point cost", 12);

    addSpecification("damage hit points", ({
        ([
            "probability": 75,
            "base damage": 28,
            "range": 28
        ]),
        ([
            "probability": 25,
            "base damage": 55,
            "range": 50
        ])
    }));

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/runeskald/frostfire/elemental-potency.c",
            "name": "elemental-potency",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/runeskald/frostfire/elemental-reserve.c",
            "name": "elemental-reserve",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/runeskald/frostfire/elemental-tempo.c",
            "name": "elemental-tempo",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/runeskald/frostfire/elemental-potency-ii.c",
            "name": "elemental-potency-ii",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/runeskald/frostfire/elemental-reserve-ii.c",
            "name": "elemental-reserve-ii",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/runeskald/frostfire/elemental-tempo-ii.c",
            "name": "elemental-tempo-ii",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.06
        ]),
        ([
            "type": "research",
            "research item": "/guilds/runeskald/frostfire/glacial-brand.c",
            "name": "Glacial Brand",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.12
        ])
    }));
    addSpecification("consumables", (["elder frost rune": 1]));
}
