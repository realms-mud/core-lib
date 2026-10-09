//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Mind Annihilation");
    addSpecification("source", "mage");
    addSpecification("description", "A mind-school attack spell.");

    addPrerequisite("/guilds/mage/mind/psychic-overload.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level", "guild": "mage", "value": 49]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("effect", "combat");
    addSpecification("spell point cost", 48);
    addSpecification("cooldown", 20);
    addSpecification("command template", "mind annihilation [at ##Target##]");
    addSpecification("event handler", "mindAnnihilationEvent");
    addSpecification("use ability message",
        "##InitiatorName## annihilate##InitiatorReflexive## ##TargetName##'s mind with devastating psychic force.");
    addSpecification("use ability fail message",
        "You failed to annihilate ##TargetName##'s mind.");
    addSpecification("use ability cooldown message",
        "You must wait before attempting mind annihilation again.");
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