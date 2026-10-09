//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "blaze of valor");
    addSpecification("source", "Order of Phaedra");
    addSpecification("description", "The companion blazes with the "
        "concentrated courage of Phaedra herself, unleashing a powerful "
        "strike wrapped in brilliant radiant fire.");
    addPrerequisite("/guilds/phaedra/courage/searing-radiance.c",
        (["type": "research"]));
    addPrerequisite("/guilds/phaedra/courage/courageous-leader.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level", "guild": "Order of Phaedra", "value": 29]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 40);
    addSpecification("cooldown", 26);
    addSpecification("command template", "blaze of valor at ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::blaze## with valorous radiant "
        "light and ##Infinitive::strike## ##TargetName## with terrible force.");
    addSpecification("damage type", "radiant");
    addSpecification("damage hit points", ({
        ([
            "probability": 80,
            "base damage": 30,
            "range": 28
        ]),
        ([
            "probability": 20,
            "base damage": 50,
            "range": 35
        ])
    }));
    addSpecification("limited by", (["equipment": ({ "long sword",
        "hand and a half sword", "short sword", "dagger" })]));
    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/phaedra/courage/radiant-might.c",
            "name": "Radiant Might",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/phaedra/courage/iron-discipline.c",
            "name": "Iron Discipline",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "research",
            "research item": "/guilds/phaedra/courage/courageous-leader.c",
            "name": "Courageous Leader",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "skill",
            "name": "long sword",
            "formula": "additive",
            "rate": 0.20
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
            "rate": 0.12
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
            "rate": 0.30
        ]),
        ([
            "type": "level",
            "name": "Order of Phaedra",
            "formula": "additive",
            "rate": 0.50
        ])
    }));
}
