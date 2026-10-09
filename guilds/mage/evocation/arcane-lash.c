//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Arcane Lash");
    addSpecification("source", "mage");
    addSpecification("description", "An evocation-school attack spell.");

    addPrerequisite("/guilds/mage/evocation/magical-bolt.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level", "guild": "mage", "value": 5]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("effect", "combat");
    addSpecification("spell point cost", 18);
    addSpecification("cooldown", 9);
    addSpecification("command template", "arcane lash [at ##Target##]");
    addSpecification("event handler", "arcaneLashEvent");
    addSpecification("use ability message",
        "##InitiatorName## lash##InitiatorReflexive## ##TargetName## with a whip of arcane force.");
    addSpecification("use ability fail message",
        "You failed to lash ##TargetName## with arcane force.");
    addSpecification("use ability cooldown message",
        "You must wait before lashing again.");
    addSpecification("damage type", "magical");
    addSpecification("damage hit points", ({
        (["probability": 100, "base damage": 18, "range": 12])
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
            "name": "evocation",
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
            "name": "Evocation Theory",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.1,
            "research item": "/guilds/mage/evocation/evocation-theory.c"
        ]),
        ([
            "type": "research",
            "name": "Evocation Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.1,
            "research item": "/guilds/mage/evocation/evocation-mastery.c"
        ]),
        ([
            "type": "research",
            "name": "Pure Evocation",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.1,
            "research item": "/guilds/mage/evocation/pure-evocation.c"
        ]),
        ([
            "type": "research",
            "name": "Primal Evocation",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.1,
            "research item": "/guilds/mage/evocation/primal-evocation.c"
        ]),
        ([
            "type": "research",
            "name": "Total Evocation",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.1,
            "research item": "/guilds/mage/evocation/total-evocation.c"
        ]),
        ([
            "type": "research",
            "name": "Evocative Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.1,
            "research item": "/guilds/mage/evocation/evocative-mastery.c"
        ]),
        ([
            "type": "research",
            "name": "Force Theory",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.1,
            "research item": "/guilds/mage/evocation/force-theory.c"
        ]),
        ([
            "type": "research",
            "name": "Force Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.1,
            "research item": "/guilds/mage/evocation/force-mastery.c"
        ]),
        ([
            "type": "research",
            "name": "Force Supremacy",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.1,
            "research item": "/guilds/mage/evocation/force-supremacy.c"
        ]),
        ([
            "type": "research",
            "name": "Evocation Supremacy",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.1,
            "research item": "/guilds/mage/evocation/evocation-supremacy.c"
        ]),
    }));
}