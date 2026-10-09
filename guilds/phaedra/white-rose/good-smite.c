//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "good smite");
    addSpecification("source", "Order of Phaedra");
    addSpecification("description", "The companion channels the power "
        "of good aligned force into a mighty strike, searing "
        "corruption and evil from the target.");
    addPrerequisite("/guilds/phaedra/white-rose/white-rose-attunement.c",
        (["type": "research"]));
    addPrerequisite("guild rank",
        (["type": "guild rank", "guild": "Order of Phaedra",
        "value": "white rose"]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 35);
    addSpecification("cooldown", 22);
    addSpecification("command template", "good smite at ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::channel## the power of good "
        "into a searing smite against ##TargetName##.");
    addSpecification("damage type", "good");
    addSpecification("damage hit points", ({
        ([
            "probability": 80,
            "base damage": 30,
            "range": 28
        ]),
        ([
            "probability": 20,
            "base damage": 48,
            "range": 38
        ])
    }));
    addSpecification("limited by", (["equipment": ({ "long sword",
        "hand and a half sword", "short sword", "dagger" })]));
    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/phaedra/white-rose/white-rose-attunement.c",
            "name": "White Rose Attunement",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "research",
            "research item": "/guilds/phaedra/white-rose/blazing-conviction.c",
            "name": "Blazing Conviction",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item": "/guilds/phaedra/courage/radiant-might.c",
            "name": "Radiant Might",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "skill",
            "name": "evocation",
            "formula": "additive",
            "rate": 0.18
        ]),
        ([
            "type": "skill",
            "name": "theology",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "skill",
            "name": "long sword",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "attribute",
            "name": "charisma",
            "formula": "additive",
            "rate": 0.28
        ]),
        ([
            "type": "attribute",
            "name": "strength",
            "formula": "additive",
            "rate": 0.28
        ]),
        ([
            "type": "level",
            "name": "Order of Phaedra",
            "formula": "additive",
            "rate": 0.55
        ])
    }));
}
