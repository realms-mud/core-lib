//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Frostfire Torrent");
    addSpecification("source", "runeskald");
    addSpecification("description", "A torrent of intertwined frost and fire "
        "blasts a single target, dealing heavy combined elemental damage.");

    addPrerequisite("level",
        (["type": "level", "guild": "runeskald", "value": 10]));
    addPrerequisite("/guilds/runeskald/frostfire/frostfire-bolt.c",
        (["type": "research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 20);
    addSpecification("command template", "frostfire torrent ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::blast## ##TargetName## with a torrent of intertwined frost and flame.");

    addSpecification("spell point cost", 40);
    addSpecification("stamina point cost", 16);

    addSpecification("damage hit points", ({
        ([
            "probability": 70,
            "base damage": 70,
            "range": 80
        ]),
        ([
            "probability": 30,
            "base damage": 120,
            "range": 120
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
            "rate": 0.15
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.08
        ]),
        ([
            "type": "research",
            "research item": "/guilds/runeskald/frostfire/frostfire-bolt.c",
            "name": "Frostfire Bolt",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.18
        ])
    }));
    addSpecification("consumables", (["elder power rune": 1]));
}
