//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Solar Flare");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of conjuring a miniature sun that explodes with "
        "blinding radiance and searing heat, devastating all enemies "
        "while temporarily blinding survivors.");
    addSpecification("usage summary", "Explosive solar burst that blinds survivors");

    addPrerequisite("/guilds/disciple-of-ferianth/inferno/ferianths-fury.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 55
        ]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 250);

    addSpecification("damage hit points", ({ ([
            "probability": 40,
            "base damage": 240,
            "range": 310
        ]),
        ([
            "probability": 40,
            "base damage": 340,
            "range": 430
        ]),
        ([
            "probability": 20,
            "base damage": 480,
            "range": 600
        ])
    }));

    addSpecification("damage type", "fire");

    addSpecification("penalty to attack", 12);
    addSpecification("penalty to defense", 10);
    addSpecification("penalty to dexterity", 5);
    addSpecification("duration", 45);

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
            "research item": "/guilds/disciple-of-ferianth/inferno/blinding-glory.c",
            "name": "Blinding Glory",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "skill",
            "name": "elemental fire",
            "formula": "additive",
            "rate": 0.30
        ]),
        ([
            "type": "skill",
            "name": "elemental light",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "additive",
            "rate": 0.18
        ]),
        ([
            "type": "skill",
            "name": "theology",
            "formula": "additive",
            "rate": 0.18
        ]),
        ([
            "type": "skill",
            "name": "evocation",
            "formula": "additive",
            "rate": 0.12
        ]),
        ([
            "type": "skill",
            "name": "destruction",
            "formula": "additive",
            "rate": 0.12
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.65
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.35
        ]),
        ([
            "type": "level",
            "name": "level",
            "formula": "additive",
            "rate": 1.05
        ])
    }));

    addSpecification("cooldown", 150);
    addSpecification("event handler", "solarFlareEvent");
    addSpecification("command template", "solar flare");

    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::conjure## a miniature sun above ##InitiatorPossessive## "
        "head! The solar sphere explodes in a blinding flash of searing "
        "radiance, scorching all enemies!");
}
