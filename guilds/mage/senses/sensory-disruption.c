//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Sensory Disruption");
    addSpecification("source", "mage");
    addSpecification("description", "A senses-school attack spell.");

    addPrerequisite("/guilds/mage/senses/dulled-senses.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level", "guild": "mage", "value": 9]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("effect", "combat");
    addSpecification("spell point cost", 22);
    addSpecification("cooldown", 10);
    addSpecification("command template", "sensory disruption [at ##Target##]");
    addSpecification("event handler", "sensoryDisruptionEvent");
    addSpecification("use ability message",
        "##InitiatorName## disrupt##InitiatorReflexive## the senses of ##TargetName## with harsh magical force.");
    addSpecification("use ability fail message",
        "You failed to disrupt ##TargetName##'s senses.");
    addSpecification("use ability cooldown message",
        "You must wait before disrupting senses again.");
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