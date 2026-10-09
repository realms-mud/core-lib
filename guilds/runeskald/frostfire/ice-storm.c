//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Ice Storm");
    addSpecification("source", "runeskald");
    addSpecification("description", "The runeskald calls down a storm of "
        "rune-ice over a wide area, pelting all enemies with freezing shards.");

    addPrerequisite("level",
        (["type": "level", "guild": "runeskald", "value": 8]));
    addPrerequisite("/guilds/runeskald/frostfire/frost-chain.c",
        (["type": "research"]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 20);
    addSpecification("command template", "ice storm");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::call## down a ferocious ice storm, pelting the area with rune-ice.");

    addSpecification("spell point cost", 38);
    addSpecification("stamina point cost", 15);

    addSpecification("damage hit points", ({
        ([
            "probability": 75,
            "base damage": 40,
            "range": 40
        ]),
        ([
            "probability": 25,
            "base damage": 75,
            "range": 75
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
            "rate": 0.12
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.07
        ]),
        ([
            "type": "research",
            "research item": "/guilds/runeskald/frostfire/glacial-brand.c",
            "name": "Glacial Brand",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ])
    }));
    addSpecification("consumables", (["elder frost rune": 1]));
}
