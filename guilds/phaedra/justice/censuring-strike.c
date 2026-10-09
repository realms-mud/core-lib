//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "censuring strike");
    addSpecification("source", "Order of Phaedra");
    addSpecification("description", "The companion delivers a strike "
        "that carries the weight of the Order's censure, dealing "
        "good-aligned damage to those who oppose the realm's justice.");
    addPrerequisite("/guilds/phaedra/justice/mark-of-censure.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level", "guild": "Order of Phaedra", "value": 9]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 20);
    addSpecification("cooldown", 12);
    addSpecification("command template", "censuring strike at ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::deliver## a strike of "
        "righteous censure upon ##TargetName##.");
    addSpecification("damage type", "good");
    addSpecification("damage hit points", ({
        ([
            "probability": 100,
            "base damage": 18,
            "range": 18
        ])
    }));
    addSpecification("limited by", (["equipment": ({ "long sword",
        "hand and a half sword", "short sword", "dagger" })]));
    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/phaedra/justice/mark-of-censure.c",
            "name": "Mark of Censure",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "research",
            "research item": "/guilds/phaedra/justice/oathbound-authority.c",
            "name": "Oathbound Authority",
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
            "name": "leadership",
            "formula": "additive",
            "rate": 0.12
        ]),
        ([
            "type": "skill",
            "name": "theology",
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
            "rate": 0.50
        ])
    }));
}
