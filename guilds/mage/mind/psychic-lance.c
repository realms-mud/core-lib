//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Psychic Lance");
    addSpecification("source", "mage");
    addSpecification("description", "A mind-school attack spell.");

    addPrerequisite("/guilds/mage/mind/root.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level", "guild": "mage", "value": 1]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("effect", "combat");
    addSpecification("spell point cost", 15);
    addSpecification("cooldown", 8);
    addSpecification("command template", "psychic lance [at ##Target##]");
    addSpecification("event handler", "psychicLanceEvent");
    addSpecification("use ability message",
        "##InitiatorName## drive##InitiatorReflexive## a psychic lance of pure energy into ##TargetName##'s mind.");
    addSpecification("use ability fail message",
        "You failed to drive a psychic lance into ##TargetName##'s mind.");
    addSpecification("use ability cooldown message",
        "You must wait before launching another psychic lance.");
    addSpecification("damage type", "magical");
    addSpecification("damage hit points", ({
        (["probability": 100, "base damage": 15, "range": 10])
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
            "name": "mind",
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
            "name": "Mind Theory",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.1,
            "research item": "/guilds/mage/mind/mind-theory.c"
        ]),
        ([
            "type": "research",
            "name": "Mind Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.1,
            "research item": "/guilds/mage/mind/mind-mastery.c"
        ]),
        ([
            "type": "research",
            "name": "Pure Mind",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.1,
            "research item": "/guilds/mage/mind/pure-mind.c"
        ]),
        ([
            "type": "research",
            "name": "Primal Mind",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.1,
            "research item": "/guilds/mage/mind/primal-mind.c"
        ]),
        ([
            "type": "research",
            "name": "Total Mind",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.1,
            "research item": "/guilds/mage/mind/total-mind.c"
        ]),
        ([
            "type": "research",
            "name": "Mind Supremacy",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.1,
            "research item": "/guilds/mage/mind/mind-supremacy.c"
        ]),
        ([
            "type": "research",
            "name": "Psionic Theory",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.1,
            "research item": "/guilds/mage/mind/psionic-theory.c"
        ]),
        ([
            "type": "research",
            "name": "Psionic Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.1,
            "research item": "/guilds/mage/mind/psionic-mastery.c"
        ]),
        ([
            "type": "research",
            "name": "Psionic Supremacy",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.1,
            "research item": "/guilds/mage/mind/psionic-supremacy.c"
        ]),
    }));
}