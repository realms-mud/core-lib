//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "light of the oath");
    addSpecification("source", "Order of Phaedra");
    addSpecification("description", "The companion invokes the light "
        "of their sworn oath, striking an enemy with a burst of "
        "radiant energy born of absolute conviction.");
    addPrerequisite("/guilds/phaedra/white-rose/roses-wrath.c",
        (["type": "research"]));
    addPrerequisite("guild rank",
        (["type": "guild rank", "guild": "Order of Phaedra",
        "value": "white rose"]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 42);
    addSpecification("cooldown", 25);
    addSpecification("command template", "light of the oath at ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::call## forth the light of "
        "their oath, burning ##TargetName## with radiant conviction.");
    addSpecification("damage type", "radiant");
    addSpecification("damage hit points", ({
        ([
            "probability": 80,
            "base damage": 35,
            "range": 30
        ]),
        ([
            "probability": 20,
            "base damage": 55,
            "range": 40
        ])
    }));
    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/phaedra/white-rose/white-rose-banner.c",
            "name": "White Rose Banner",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/phaedra/white-rose/radiant-bearing.c",
            "name": "Radiant Bearing",
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
            "rate": 0.14
        ]),
        ([
            "type": "skill",
            "name": "long sword",
            "formula": "additive",
            "rate": 0.16
        ]),
        ([
            "type": "attribute",
            "name": "strength",
            "formula": "additive",
            "rate": 0.30
        ]),
        ([
            "type": "attribute",
            "name": "charisma",
            "formula": "additive",
            "rate": 0.25
        ]),
        ([
            "type": "level",
            "name": "Order of Phaedra",
            "formula": "additive",
            "rate": 0.55
        ])
    }));
}
