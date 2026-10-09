//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Total Sensory Collapse");
    addSpecification("source", "mage");
    addSpecification("description", "A senses-school attack spell.");

    addPrerequisite("/guilds/mage/senses/perception-rend.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level", "guild": "mage", "value": 49]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("effect", "combat");
    addSpecification("spell point cost", 48);
    addSpecification("cooldown", 20);
    addSpecification("command template", "total sensory collapse [at ##Target##]");
    addSpecification("event handler", "totalSensoryCollapseEvent");
    addSpecification("use ability message",
        "##InitiatorName## cause##InitiatorReflexive## the total collapse of ##TargetName##'s senses.");
    addSpecification("use ability fail message",
        "You failed to cause a total sensory collapse in ##TargetName##.");
    addSpecification("use ability cooldown message",
        "You must wait before attempting total sensory collapse again.");
    addSpecification("damage type", "magical");
    addSpecification("damage hit points", ({
        (["probability": 100, "base damage": 62, "range": 30])
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