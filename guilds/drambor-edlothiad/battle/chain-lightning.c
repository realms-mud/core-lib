//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Chain Lightning");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research teaches the battlemage to call forth a bolt of lightning that arcs between multiple foes, each leap amplifying its destructive fury.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/battle/magic-missile.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 9
        ]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("damage hit points", ({
        ([
            "probability": 80,
            "base damage": 35,
            "range": 25
        ]),
        ([
            "probability": 20,
            "base damage": 60,
            "range": 40
        ])
    }));

    addSpecification("damage type", "electricity");

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/drambor-edlothiad/battle/combat-casting.c",
            "name": "Combat Casting",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/drambor-edlothiad/battle/spell-focus.c",
            "name": "Spell Focus",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/drambor-edlothiad/battle/quickened-casting.c",
            "name": "Quickened Casting",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/drambor-edlothiad/battle/mana-efficiency.c",
            "name": "Mana Efficiency",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/drambor-edlothiad/battle/spell-penetration.c",
            "name": "Spell Penetration",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.25
        ]),
        ([
            "type": "skill",
            "name": "magical essence",
            "formula": "logarithmic",
            "rate": 1.25
        ]),
        ([
            "type": "skill",
            "name": "elemental air",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "skill",
            "name": "evocation",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "level",
            "name": "Drambor Edlothiad",
            "formula": "logarithmic",
            "rate": 1.05
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.05
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.025
        ])
    }));

    addSpecification("spell point cost", 55);
    addSpecification("cooldown", 20);
    addSpecification("command template", "chain lightning");
    addSpecification("use ability message", "##InitiatorName## ##Infinitive::call## forth a bolt of lightning that arcs between ##TargetName## and nearby foes.");
}
