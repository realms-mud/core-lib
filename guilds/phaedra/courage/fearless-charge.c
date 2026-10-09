//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "fearless charge");
    addSpecification("source", "Order of Phaedra");
    addSpecification("description", "The companion charges the enemy "
        "without hesitation, striking with the full weight of their "
        "conviction and infusing the blow with righteous light.");
    addPrerequisite("/guilds/phaedra/courage/rallying-strike.c",
        (["type": "research"]));
    addPrerequisite("/guilds/phaedra/courage/stalwart-training.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level", "guild": "Order of Phaedra", "value": 5]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 18);
    addSpecification("cooldown", 12);
    addSpecification("command template", "fearless charge at ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::charge## ##TargetName## with "
        "fearless resolve, striking with radiant fury.");
    addSpecification("damage type", "radiant");
    addSpecification("damage hit points", ({
        ([
            "probability": 90,
            "base damage": 18,
            "range": 18
        ]),
        ([
            "probability": 10,
            "base damage": 30,
            "range": 20
        ])
    }));
    addSpecification("limited by", (["equipment": ({ "long sword",
        "hand and a half sword", "short sword", "dagger" })]));
    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/phaedra/courage/stalwart-training.c",
            "name": "Stalwart Training",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "research",
            "research item": "/guilds/phaedra/courage/resolve-of-the-founders.c",
            "name": "Resolve of the Founders",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "skill",
            "name": "long sword",
            "formula": "additive",
            "rate": 0.18
        ]),
        ([
            "type": "skill",
            "name": "tactics",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "additive",
            "rate": 0.08
        ]),
        ([
            "type": "attribute",
            "name": "strength",
            "formula": "additive",
            "rate": 0.35
        ]),
        ([
            "type": "attribute",
            "name": "charisma",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "level",
            "name": "Order of Phaedra",
            "formula": "additive",
            "rate": 0.50
        ])
    }));
}
