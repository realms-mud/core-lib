//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Total Dominion");
    addSpecification("source", "mage");
    addSpecification("description", "A manipulation-school attack spell.");

    addPrerequisite("/guilds/mage/manipulation/manipulative-mastery.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level", "guild": "mage", "value": 57]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("effect", "combat");
    addSpecification("spell point cost", 55);
    addSpecification("cooldown", 22);
    addSpecification("command template", "total dominion [at ##Target##]");
    addSpecification("event handler", "totalDominionEvent");
    addSpecification("use ability message",
        "##InitiatorName## assert##InitiatorReflexive## total dominion over ##TargetName##'s energy, tearing it asunder.");
    addSpecification("use ability fail message",
        "You failed to assert total dominion over ##TargetName##.");
    addSpecification("use ability cooldown message",
        "You must wait before asserting total dominion again.");
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
            "name": "manipulation",
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
            "type": "level",
            "name": "mage",
            "formula": "additive",
            "rate": 0.5
        ]),
        ([
            "type": "research",
            "name": "Manipulation Theory",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.1,
            "research item": "/guilds/mage/manipulation/manipulation-theory.c"
        ]),
        ([
            "type": "research",
            "name": "Manipulation Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.1,
            "research item": "/guilds/mage/manipulation/manipulation-mastery.c"
        ]),
        ([
            "type": "research",
            "name": "Pure Manipulation",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.1,
            "research item": "/guilds/mage/manipulation/pure-manipulation.c"
        ]),
        ([
            "type": "research",
            "name": "Primal Manipulation",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.1,
            "research item": "/guilds/mage/manipulation/primal-manipulation.c"
        ]),
        ([
            "type": "research",
            "name": "Total Manipulation",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.1,
            "research item": "/guilds/mage/manipulation/total-manipulation.c"
        ]),
        ([
            "type": "research",
            "name": "Manipulative Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.1,
            "research item": "/guilds/mage/manipulation/manipulative-mastery.c"
        ]),
        ([
            "type": "research",
            "name": "Siphon Theory",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.1,
            "research item": "/guilds/mage/manipulation/siphon-theory.c"
        ]),
        ([
            "type": "research",
            "name": "Siphon Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.1,
            "research item": "/guilds/mage/manipulation/siphon-mastery.c"
        ]),
        ([
            "type": "research",
            "name": "Siphon Supremacy",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.1,
            "research item": "/guilds/mage/manipulation/siphon-supremacy.c"
        ]),
    }));
}