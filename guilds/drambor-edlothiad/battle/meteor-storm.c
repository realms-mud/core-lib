//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Meteor Storm");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research teaches the battlemage to tear open rifts in the sky, calling down a barrage of blazing meteors that pummel the battlefield with apocalyptic force.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/battle/inferno.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 33
        ]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("damage hit points", ({
        ([
            "probability": 80,
            "base damage": 110,
            "range": 65
        ]),
        ([
            "probability": 20,
            "base damage": 185,
            "range": 110
        ])
    }));

    addSpecification("damage type", "fire");

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
            "type": "research",
            "research item": "/guilds/drambor-edlothiad/battle/spell-penetration-mastery.c",
            "name": "Spell Penetration Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/drambor-edlothiad/battle/arcane-might.c",
            "name": "Arcane Might",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/drambor-edlothiad/battle/devastating-focus.c",
            "name": "Devastating Focus",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/drambor-edlothiad/battle/battle-mastery.c",
            "name": "Battle Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/drambor-edlothiad/battle/overwhelming-force.c",
            "name": "Overwhelming Force",
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
            "name": "elemental fire",
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

    addSpecification("spell point cost", 130);
    addSpecification("cooldown", 45);
    addSpecification("command template", "meteor storm");
    addSpecification("use ability message", "##InitiatorName## ##Infinitive::tear## open the sky, calling down a storm of blazing meteors upon ##TargetName## and nearby foes.");
}
