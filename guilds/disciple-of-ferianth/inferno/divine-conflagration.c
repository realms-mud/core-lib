//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Divine Conflagration");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of igniting a divine conflagration - a holy firestorm "
        "of such intensity that it tears through all enemies, dealing "
        "catastrophic damage that scales with the caster's devotion.");
    addSpecification("usage summary", "Catastrophic holy firestorm");

    addPrerequisite("/guilds/disciple-of-ferianth/inferno/solar-flare.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 59
        ]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 280);

    addSpecification("damage hit points", ({ ([
            "probability": 35,
            "base damage": 300,
            "range": 400
        ]),
        ([
            "probability": 40,
            "base damage": 420,
            "range": 540
        ]),
        ([
            "probability": 25,
            "base damage": 580,
            "range": 720
        ])
    }));

    addSpecification("damage spell points", ({ ([
            "probability": 100,
            "base damage": 70,
            "range": 100
        ])
    }));

    addSpecification("damage stamina points", ({ ([
            "probability": 100,
            "base damage": 50,
            "range": 70
        ])
    }));

    addSpecification("damage type", "fire");

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/inferno/fire-mastery.c",
            "name": "Fire Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/inferno/inferno-potency.c",
            "name": "Inferno Potency",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/inferno/divine-fire-potency.c",
            "name": "Divine Fire Potency",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/inferno/righteous-fury.c",
            "name": "Righteous Fury",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/inferno/sacred-champion.c",
            "name": "Sacred Champion",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/inferno/blinding-glory.c",
            "name": "Blinding Glory",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "skill",
            "name": "elemental fire",
            "formula": "additive",
            "rate": 0.35
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "additive",
            "rate": 0.20
        ]),
        ([
            "type": "skill",
            "name": "theology",
            "formula": "additive",
            "rate": 0.20
        ]),
        ([
            "type": "skill",
            "name": "evocation",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "skill",
            "name": "destruction",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.70
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.40
        ]),
        ([
            "type": "level",
            "name": "level",
            "formula": "additive",
            "rate": 1.10
        ])
    }));

    addSpecification("cooldown", 180);
    addSpecification("event handler", "divineConflagrationEvent");
    addSpecification("command template", "divine conflagration");

    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::spread## ##InitiatorPossessive## arms wide and "
        "##Infinitive::ignite## a divine conflagration! Holy flames "
        "sweep outward in all directions, consuming everything in an "
        "inferno of sacred wrath!");
}
