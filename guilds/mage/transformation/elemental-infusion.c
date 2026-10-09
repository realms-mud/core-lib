//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Elemental Infusion");
    addSpecification("source", "mage");
    addSpecification("description", "A transformation-school attack spell.");

    addPrerequisite("/guilds/mage/transformation/transmute-matter.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level", "guild": "mage", "value": 13]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("effect", "combat");
    addSpecification("spell point cost", 26);
    addSpecification("cooldown", 12);
    addSpecification("command template", "elemental infusion [at ##Target##]");
    addSpecification("event handler", "elementalInfusionEvent");
    addSpecification("use ability message",
        "##InitiatorName## infuse##InitiatorReflexive## ##TargetName## with destructive elemental energy.");
    addSpecification("use ability fail message",
        "You failed to infuse ##TargetName## with elemental energy.");
    addSpecification("use ability cooldown message",
        "You must wait before infusing elemental energy again.");
    addSpecification("damage type", "magical");
    addSpecification("damage hit points", ({
        (["probability": 100, "base damage": 30, "range": 16])
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
            "name": "transformation",
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
            "name": "Transformation Theory",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.1,
            "research item": "/guilds/mage/transformation/transformation-theory.c"
        ]),
        ([
            "type": "research",
            "name": "Transformation Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.1,
            "research item": "/guilds/mage/transformation/transformation-mastery.c"
        ]),
        ([
            "type": "research",
            "name": "Pure Transformation",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.1,
            "research item": "/guilds/mage/transformation/pure-transformation.c"
        ]),
        ([
            "type": "research",
            "name": "Primal Transformation",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.1,
            "research item": "/guilds/mage/transformation/primal-transformation.c"
        ]),
        ([
            "type": "research",
            "name": "Total Transformation",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.1,
            "research item": "/guilds/mage/transformation/total-transformation.c"
        ]),
        ([
            "type": "research",
            "name": "Transformative Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.1,
            "research item": "/guilds/mage/transformation/transformative-mastery.c"
        ]),
        ([
            "type": "research",
            "name": "Transmutation Theory",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.1,
            "research item": "/guilds/mage/transformation/transmutation-theory.c"
        ]),
        ([
            "type": "research",
            "name": "Transmutation Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.1,
            "research item": "/guilds/mage/transformation/transmutation-mastery.c"
        ]),
        ([
            "type": "research",
            "name": "Transmutation Supremacy",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.1,
            "research item": "/guilds/mage/transformation/transmutation-supremacy.c"
        ]),
    }));
}