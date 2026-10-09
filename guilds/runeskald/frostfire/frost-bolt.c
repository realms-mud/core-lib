//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Frost Bolt");
    addSpecification("source", "runeskald");
    addSpecification("description", "A concentrated bolt of glacial rune-force "
        "that deals more cold damage than a basic ice shard.");

    addPrerequisite("level",
        (["type": "level", "guild": "runeskald", "value": 2]));
    addPrerequisite("/guilds/runeskald/frostfire/glacial-brand.c",
        (["type": "research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 12);
    addSpecification("command template", "frost bolt ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::hurl## a frost bolt of glacial rune-force at ##TargetName##.");

    addSpecification("spell point cost", 18);
    addSpecification("stamina point cost", 6);

    addSpecification("damage hit points", ({
        ([
            "probability": 80,
            "base damage": 22,
            "range": 25
        ]),
        ([
            "probability": 20,
            "base damage": 42,
            "range": 38
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
            "type": "skill",
            "name": "spellcraft",
            "formula": "additive",
            "rate": 0.08
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.05
        ]),
        ([
            "type": "research",
            "research item": "/guilds/runeskald/frostfire/glacial-brand.c",
            "name": "Glacial Brand",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.10
        ])
    }));
    addSpecification("consumables", (["basic frost rune": 1]));
}
