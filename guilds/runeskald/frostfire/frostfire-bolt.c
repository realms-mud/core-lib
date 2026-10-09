//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Frostfire Bolt");
    addSpecification("source", "runeskald");
    addSpecification("description", "The runeskald combines frost and fire "
        "into a single devastating bolt that deals both cold and fire damage.");

    addPrerequisite("level",
        (["type": "level", "guild": "runeskald", "value": 7]));
    addPrerequisite("/guilds/runeskald/frostfire/elemental-attunement.c",
        (["type": "research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 20);
    addSpecification("command template", "frostfire bolt ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::hurl## a swirling bolt of frost and flame at ##TargetName##.");

    addSpecification("spell point cost", 30);
    addSpecification("stamina point cost", 12);

    addSpecification("damage hit points", ({
        ([
            "probability": 75,
            "base damage": 45,
            "range": 50
        ]),
        ([
            "probability": 25,
            "base damage": 85,
            "range": 80
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
            "research item": "/guilds/runeskald/frostfire/elemental-attunement.c",
            "name": "Elemental Attunement",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ])
    }));
    addSpecification("consumables", (["elder power rune": 1]));
}
