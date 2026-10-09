//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Rune Strike");
    addSpecification("source", "runeskald");
    addSpecification("description", "The runeskald channels the power of a "
        "painted rune into a single devastating blow. Deals heavy physical "
        "damage to one target, amplified if the rune of strength is active.");

    addPrerequisite("level",
        (["type": "level", "guild": "runeskald", "value": 5]));
    addPrerequisite("/guilds/runeskald/rune-warrior/paint-rune-of-strength.c",
        (["type": "research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 12);
    addSpecification("command template", "rune strike ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::channel## the rune's power into a crushing blow against ##TargetName##.");

    addSpecification("spell point cost", 20);
    addSpecification("stamina point cost", 15);

    addSpecification("damage hit points", ({
        ([
            "probability": 75,
            "base damage": 25,
            "range": 30
        ]),
        ([
            "probability": 25,
            "base damage": 55,
            "range": 40
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
            "type": "skill",
            "name": "long sword",
            "formula": "additive",
            "rate": 0.06
        ]),
        ([
            "type": "attribute",
            "name": "strength",
            "formula": "additive",
            "rate": 0.07
        ]),
        ([
            "type": "research",
            "research item": "/guilds/runeskald/rune-warrior/paint-rune-of-strength.c",
            "name": "Paint Rune of Strength",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.30
        ])
    }));
    addSpecification("consumables", (["basic blade rune": 1]));
}
