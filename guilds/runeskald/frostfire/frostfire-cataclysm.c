//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Frostfire Cataclysm");
    addSpecification("source", "runeskald");
    addSpecification("description", "The runeskald unleashes a catastrophic "
        "combined explosion of frost and fire across the entire area, "
        "dealing devastating damage to all enemies.");

    addPrerequisite("level",
        (["type": "level", "guild": "runeskald", "value": 16]));
    addPrerequisite("/guilds/runeskald/frostfire/frostfire-wave.c",
        (["type": "research"]));
    addPrerequisite("/guilds/runeskald/frostfire/frostfire-burst.c",
        (["type": "research"]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 40);
    addSpecification("command template", "frostfire cataclysm");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::unleash## a cataclysmic explosion of frost and fire that engulfs the entire area.");

    addSpecification("spell point cost", 65);
    addSpecification("stamina point cost", 28);

    addSpecification("damage hit points", ({
        ([
            "probability": 65,
            "base damage": 120,
            "range": 130
        ]),
        ([
            "probability": 35,
            "base damage": 200,
            "range": 200
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
            "type": "research",
            "research item": "/guilds/runeskald/frostfire/elemental-potency-iii.c",
            "name": "elemental-potency-iii",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "additive",
            "rate": 0.22
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "research",
            "research item": "/guilds/runeskald/frostfire/frostfire-burst.c",
            "name": "Frostfire Burst",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ])
    }));
    addSpecification("consumables", (["ancient power rune": 1]));
}
