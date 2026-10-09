//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Total Revelation");
    addSpecification("source", "mage");
    addSpecification("description", "A divination-school attack spell.");

    addPrerequisite("/guilds/mage/divination/divinatory-mastery.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level", "guild": "mage", "value": 57]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("effect", "combat");
    addSpecification("spell point cost", 55);
    addSpecification("cooldown", 22);
    addSpecification("command template", "total revelation [at ##Target##]");
    addSpecification("event handler", "totalRevelationEvent");
    addSpecification("use ability message",
        "##InitiatorName## reveal##InitiatorReflexive## total and devastating truth upon ##TargetName##.");
    addSpecification("use ability fail message",
        "You failed to achieve total revelation on ##TargetName##.");
    addSpecification("use ability cooldown message",
        "You must wait before attempting total revelation again.");
    addSpecification("damage type", "magical");
    addSpecification("damage hit points", ({
        (["probability": 100, "base damage": 72, "range": 35])
    }));
    addSpecification("modifiers", ({
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "skill",
            "name": "divination",
            "formula": "additive",
            "rate": 0.2
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.1
        ]),
        ([
            "type": "level",
            "name": "mage",
            "formula": "additive",
            "rate": 0.5
        ]),
        ([
            "type": "research",
            "name": "Divination Theory",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.1,
            "research item": "/guilds/mage/divination/divination-theory.c"
        ]),
        ([
            "type": "research",
            "name": "Divination Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.1,
            "research item": "/guilds/mage/divination/divination-mastery.c"
        ]),
        ([
            "type": "research",
            "name": "Pure Divination",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.1,
            "research item": "/guilds/mage/divination/pure-divination.c"
        ]),
        ([
            "type": "research",
            "name": "Primal Divination",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.1,
            "research item": "/guilds/mage/divination/primal-divination.c"
        ]),
        ([
            "type": "research",
            "name": "Total Divination",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.1,
            "research item": "/guilds/mage/divination/total-divination.c"
        ]),
        ([
            "type": "research",
            "name": "Divinatory Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.1,
            "research item": "/guilds/mage/divination/divinatory-mastery.c"
        ]),
        ([
            "type": "research",
            "name": "Oracle Theory",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.1,
            "research item": "/guilds/mage/divination/oracle-theory.c"
        ]),
        ([
            "type": "research",
            "name": "Oracle Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.1,
            "research item": "/guilds/mage/divination/oracle-mastery.c"
        ]),
        ([
            "type": "research",
            "name": "Oracle Supremacy",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.1,
            "research item": "/guilds/mage/divination/oracle-supremacy.c"
        ]),
    }));
}