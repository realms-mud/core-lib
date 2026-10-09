//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Ice Storm");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research teaches the battlemage to conjure a devastating storm of razor-sharp ice shards that shred through all enemies in the area.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/battle/force-blast.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 13
        ]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("damage hit points", ({
        ([
            "probability": 80,
            "base damage": 50,
            "range": 30
        ]),
        ([
            "probability": 20,
            "base damage": 85,
            "range": 50
        ])
    }));

    addSpecification("damage type", "cold");

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
            "type": "research",
            "research item": "/guilds/drambor-edlothiad/battle/arcane-might.c",
            "name": "Arcane Might",
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
            "name": "elemental water",
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
    addSpecification("cooldown", 18);
    addSpecification("command template", "ice storm");
    addSpecification("use ability message", "##InitiatorName## ##Infinitive::conjure## a devastating storm of razor ice that shreds through ##TargetName## and nearby foes.");
}
