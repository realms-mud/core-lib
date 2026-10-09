//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Blizzard Strike");
    addSpecification("source", "runeskald");
    addSpecification("description", "The runeskald launches a barrage of "
        "razor-sharp ice shards that rakes all nearby enemies with "
        "freezing damage.");

    addPrerequisite("level",
        (["type": "level", "guild": "runeskald", "value": 9]));
    addPrerequisite("/guilds/runeskald/frostfire/frost-chain.c",
        (["type": "research"]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 20);
    addSpecification("command template", "invoke blizzard strike");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::launch## a barrage of razor ice shards that rakes everything nearby.");

    addSpecification("spell point cost", 35);
    addSpecification("stamina point cost", 14);

    addSpecification("damage hit points", ({
        ([
            "probability": 70,
            "base damage": 52,
            "range": 58
        ]),
        ([
            "probability": 30,
            "base damage": 98,
            "range": 92
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
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.09
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "additive",
            "rate": 0.09
        ])
    }));
    addSpecification("consumables", (["elder frost rune": 1]));
}
