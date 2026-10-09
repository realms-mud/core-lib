//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "dawn's reckoning");
    addSpecification("source", "Order of Phaedra");
    addSpecification("description", "The companion calls upon the full "
        "radiant power they have cultivated through decades of service, "
        "unleashing a devastating assault of light upon a single foe.");
    addPrerequisite("/guilds/phaedra/courage/blaze-of-valor.c",
        (["type": "research"]));
    addPrerequisite("/guilds/phaedra/courage/masters-resolve.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level", "guild": "Order of Phaedra", "value": 39]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 50);
    addSpecification("cooldown", 30);
    addSpecification("command template", "dawns reckoning at ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::channel## the radiant power "
        "of dawn itself upon ##TargetName## in a blinding reckoning.");
    addSpecification("damage type", "radiant");
    addSpecification("damage hit points", ({
        ([
            "probability": 75,
            "base damage": 35,
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
            "research item": "/guilds/phaedra/courage/masters-resolve.c",
            "name": "Master's Resolve",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/phaedra/courage/champions-bearing.c",
            "name": "Champion's Bearing",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "research",
            "research item": "/guilds/phaedra/courage/radiant-might.c",
            "name": "Radiant Might",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "skill",
            "name": "evocation",
            "formula": "additive",
            "rate": 0.20
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "skill",
            "name": "theology",
            "formula": "additive",
            "rate": 0.12
        ]),
        ([
            "type": "attribute",
            "name": "charisma",
            "formula": "additive",
            "rate": 0.40
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.25
        ]),
        ([
            "type": "level",
            "name": "Order of Phaedra",
            "formula": "additive",
            "rate": 0.50
        ])
    }));
}
