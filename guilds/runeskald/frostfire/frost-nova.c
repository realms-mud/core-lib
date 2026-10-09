//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Frost Nova");
    addSpecification("source", "runeskald");
    addSpecification("description", "The runeskald erupts in a burst of glacial "
        "energy, damaging all nearby enemies with cold.");

    addPrerequisite("level",
        (["type": "level", "guild": "runeskald", "value": 3]));
    addPrerequisite("/guilds/runeskald/frostfire/frost-bolt.c",
        (["type": "research"]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 12);
    addSpecification("command template", "frost nova");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::erupt## in a glacial burst, showering all nearby foes with rune-ice.");

    addSpecification("spell point cost", 24);
    addSpecification("stamina point cost", 10);

    addSpecification("damage hit points", ({
        ([
            "probability": 80,
            "base damage": 18,
            "range": 18
        ]),
        ([
            "probability": 20,
            "base damage": 36,
            "range": 30
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
