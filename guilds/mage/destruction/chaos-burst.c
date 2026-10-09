//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Chaos Burst");
    addSpecification("source", "mage");
    addSpecification("description", "A destruction-school attack spell.");

    addPrerequisite("/guilds/mage/destruction/ruinous-lash.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level", "guild": "mage", "value": 9]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("effect", "combat");
    addSpecification("spell point cost", 22);
    addSpecification("cooldown", 10);
    addSpecification("command template", "chaos burst [at ##Target##]");
    addSpecification("event handler", "chaosBurstEvent");
    addSpecification("use ability message",
        "##InitiatorName## detonate##InitiatorReflexive## a burst of chaotic energy around ##TargetName##.");
    addSpecification("use ability fail message",
        "You failed to detonate a chaos burst around ##TargetName##.");
    addSpecification("use ability cooldown message",
        "You must wait before detonating another chaos burst.");
    addSpecification("damage type", "magical");
    addSpecification("damage hit points", ({
        (["probability": 100, "base damage": 25, "range": 14])
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
            "name": "destruction",
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
            "name": "Destruction Theory",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.1,
            "research item": "/guilds/mage/destruction/destruction-theory.c"
        ]),
        ([
            "type": "research",
            "name": "Destruction Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.1,
            "research item": "/guilds/mage/destruction/destruction-mastery.c"
        ]),
        ([
            "type": "research",
            "name": "Pure Destruction",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.1,
            "research item": "/guilds/mage/destruction/pure-destruction.c"
        ]),
        ([
            "type": "research",
            "name": "Primal Destruction",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.1,
            "research item": "/guilds/mage/destruction/primal-destruction.c"
        ]),
        ([
            "type": "research",
            "name": "Total Devastation",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.1,
            "research item": "/guilds/mage/destruction/total-devastation.c"
        ]),
        ([
            "type": "research",
            "name": "Destructive Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.1,
            "research item": "/guilds/mage/destruction/destructive-mastery.c"
        ]),
        ([
            "type": "research",
            "name": "Entropy Theory",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.1,
            "research item": "/guilds/mage/destruction/entropy-theory.c"
        ]),
        ([
            "type": "research",
            "name": "Entropy Supremacy",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.1,
            "research item": "/guilds/mage/destruction/entropy-supremacy.c"
        ]),
        ([
            "type": "research",
            "name": "Destruction Supremacy",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.1,
            "research item": "/guilds/mage/destruction/destruction-supremacy.c"
        ]),
    }));
}