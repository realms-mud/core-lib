//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Magic Missile");
    addSpecification("source", "Drambor Edlothiad");
    addSpecification("description", "This research teaches the classic magic missile spell, launching multiple unerring bolts of force that track and strike their target regardless of evasion.");

    addPrerequisite(
        "/guilds/drambor-edlothiad/battle/arcane-bolt.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Drambor Edlothiad",
            "value": 3
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("damage hit points", ({
        ([
            "probability": 80,
            "base damage": 25,
            "range": 15
        ]),
        ([
            "probability": 20,
            "base damage": 40,
            "range": 25
        ])
    }));

    addSpecification("damage type", "magical");

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

    addSpecification("spell point cost", 30);
    addSpecification("cooldown", 8);
    addSpecification("command template", "magic missile");
    addSpecification("use ability message", "##InitiatorName## ##Infinitive::launch## a volley of shimmering magic missiles at ##TargetName##.");
}
