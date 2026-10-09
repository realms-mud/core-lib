//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Dulled Senses");
    addSpecification("source", "mage");
    addSpecification("description", "A senses-school attack spell.");

    addPrerequisite("/guilds/mage/senses/root.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level", "guild": "mage", "value": 3]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("effect", "combat");
    addSpecification("spell point cost", 16);
    addSpecification("cooldown", 8);
    addSpecification("command template", "dulled senses [at ##Target##]");
    addSpecification("event handler", "dulledSensesEvent");
    addSpecification("use ability message",
        "##InitiatorName## dull##InitiatorReflexive## the senses of ##TargetName## to cause disorienting harm.");
    addSpecification("use ability fail message",
        "You failed to dull the senses of ##TargetName##.");
    addSpecification("use ability cooldown message",
        "You must wait before dulling senses again.");
    addSpecification("damage type", "magical");
    addSpecification("damage hit points", ({
        (["probability": 100, "base damage": 16, "range": 11])
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
            "name": "perception",
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
            "name": "Senses Theory",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.1,
            "research item": "/guilds/mage/senses/senses-theory.c"
        ]),
        ([
            "type": "research",
            "name": "Senses Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.1,
            "research item": "/guilds/mage/senses/senses-mastery.c"
        ]),
        ([
            "type": "research",
            "name": "Pure Senses",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.1,
            "research item": "/guilds/mage/senses/pure-senses.c"
        ]),
        ([
            "type": "research",
            "name": "Primal Senses",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.1,
            "research item": "/guilds/mage/senses/primal-senses.c"
        ]),
        ([
            "type": "research",
            "name": "Total Senses",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.1,
            "research item": "/guilds/mage/senses/total-senses.c"
        ]),
        ([
            "type": "research",
            "name": "Sensory Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.1,
            "research item": "/guilds/mage/senses/sensory-mastery.c"
        ]),
        ([
            "type": "research",
            "name": "Perception Theory",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.1,
            "research item": "/guilds/mage/senses/perception-theory.c"
        ]),
        ([
            "type": "research",
            "name": "Perception Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.1,
            "research item": "/guilds/mage/senses/perception-mastery.c"
        ]),
        ([
            "type": "research",
            "name": "Perception Supremacy",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.1,
            "research item": "/guilds/mage/senses/perception-supremacy.c"
        ]),
    }));
}