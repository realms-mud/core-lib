//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Blazing Wrath");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of channeling Ferianth's righteous anger into searing "
        "flames that not only burn the target but cripple their combat "
        "effectiveness through sheer agony.");
    addSpecification("usage summary", "Wrathful flames that cripple combat ability");

    addPrerequisite("/guilds/disciple-of-ferianth/inferno/consuming-flames.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 39
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 150);

    addSpecification("siphon hit points", ({ ([
            "probability": 100,
            "base damage": 110,
            "range": 150
        ])
    }));

    addSpecification("damage stamina points", ({ ([
            "probability": 100,
            "base damage": 50,
            "range": 70
        ])
    }));

    addSpecification("damage type", "fire");

    addSpecification("penalty to attack", 8);
    addSpecification("penalty to defense", 8);
    addSpecification("penalty to dexterity", 3);
    addSpecification("apply slow", 1);
    addSpecification("duration", 75);

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
            "research item": "/guilds/disciple-of-ferianth/inferno/smite-the-wicked.c",
            "name": "Smite the Wicked",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "skill",
            "name": "elemental fire",
            "formula": "additive",
            "rate": 0.25
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "skill",
            "name": "theology",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "skill",
            "name": "evocation",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "skill",
            "name": "destruction",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "skill",
            "name": "magical essence",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.55
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.25
        ]),
        ([
            "type": "level",
            "name": "level",
            "formula": "additive",
            "rate": 0.85
        ])
    }));

    addSpecification("cooldown", 40);
    addSpecification("event handler", "blazingWrathEvent");
    addSpecification("command template", "blazing wrath [at ##Target##]");

    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::channel## Ferianth's blazing wrath into ##TargetName##! "
        "The searing flames leave ##TargetObjective## writhing in agony!");
}
