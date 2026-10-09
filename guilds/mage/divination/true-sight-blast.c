//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "True Sight Blast");
    addSpecification("source", "mage");
    addSpecification("description", "A divination-school attack spell.");

    addPrerequisite("/guilds/mage/divination/prescient-strike.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level", "guild": "mage", "value": 27]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("effect", "combat");
    addSpecification("spell point cost", 36);
    addSpecification("cooldown", 16);
    addSpecification("command template", "true sight blast [at ##Target##]");
    addSpecification("event handler", "trueSightBlastEvent");
    addSpecification("use ability message",
        "##InitiatorName## unleash##InitiatorReflexive## a blast of true-sight energy upon ##TargetName##.");
    addSpecification("use ability fail message",
        "You failed to unleash a true sight blast on ##TargetName##.");
    addSpecification("use ability cooldown message",
        "You must wait before unleashing another true sight blast.");
    addSpecification("damage type", "magical");
    addSpecification("damage hit points", ({
        (["probability": 100, "base damage": 44, "range": 22])
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