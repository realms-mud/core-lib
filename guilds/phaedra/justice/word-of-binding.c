//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "word of binding");
    addSpecification("source", "Order of Phaedra");
    addSpecification("description", "The companion speaks a word of "
        "binding drawn from the Order's authority, striking an "
        "enemy with good-aligned force that staggeres their actions.");
    addPrerequisite("/guilds/phaedra/justice/censuring-strike.c",
        (["type": "research"]));
    addPrerequisite("/guilds/phaedra/justice/decree-of-weakness.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level", "guild": "Order of Phaedra", "value": 13]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 25);
    addSpecification("cooldown", 16);
    addSpecification("command template", "word of binding at ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::speak## a word of binding "
        "against ##TargetName##, striking them with judicial force.");
    addSpecification("damage type", "good");
    addSpecification("damage hit points", ({
        ([
            "probability": 90,
            "base damage": 20,
            "range": 20
        ]),
        ([
            "probability": 10,
            "base damage": 35,
            "range": 25
        ])
    }));
    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/phaedra/justice/justices-edge.c",
            "name": "Justice's Edge",
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
            "name": "evocation",
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
            "type": "skill",
            "name": "leadership",
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
            "name": "charisma",
            "formula": "additive",
            "rate": 0.35
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.20
        ]),
        ([
            "type": "level",
            "name": "Order of Phaedra",
            "formula": "additive",
            "rate": 0.50
        ])
    }));
}
