//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Burning Hands");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of unleashing a cone of sacred fire from their hands, "
        "scorching all enemies before them.");
    addSpecification("usage summary", "An area attack that damages all "
        "enemies in front of the caster");

    addPrerequisite("/guilds/disciple-of-ferianth/inferno/fire-bolt.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 11
        ]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 35);

    addSpecification("damage hit points", ({ ([
            "probability": 80,
            "base damage": 20,
            "range": 35
        ]),
        ([
            "probability": 20,
            "base damage": 35,
            "range": 50
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
            "type": "skill",
            "name": "elemental fire",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "skill",
            "name": "theology",
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
            "rate": 0.35
        ]),
        ([
            "type": "level",
            "name": "level",
            "formula": "additive",
            "rate": 0.50
        ])
    }));

    addSpecification("cooldown", 12);
    addSpecification("event handler", "burningHandsEvent");
    addSpecification("command template", "burning hands");

    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::thrust## ##InitiatorPossessive## hands forward, "
        "unleashing a cone of sacred fire!");
}