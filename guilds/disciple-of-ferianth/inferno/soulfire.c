//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Soulfire");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of igniting a target's very soul with sacred fire. This "
        "devastating attack drains their life essence while simultaneously "
        "burning away their will to fight.");
    addSpecification("usage summary", "Soul-burning flames that drain essence");

    addPrerequisite("/guilds/disciple-of-ferianth/inferno/blazing-wrath.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 47
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 190);

    addSpecification("siphon hit points", ({ ([
            "probability": 100,
            "base damage": 150,
            "range": 200
        ])
    }));

    addSpecification("siphon spell points", ({ ([
            "probability": 100,
            "base damage": 60,
            "range": 80
        ])
    }));

    addSpecification("damage type", "fire");

    addSpecification("penalty to wisdom", 4);
    addSpecification("penalty to intelligence", 4);
    addSpecification("penalty to charisma", 3);
    addSpecification("apply enfeebled", 1);
    addSpecification("duration", 90);

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
            "rate": 1.20
        ]),
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/inferno/inner-light.c",
            "name": "Inner Light",
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
            "rate": 0.12
        ]),
        ([
            "type": "skill",
            "name": "destruction",
            "formula": "additive",
            "rate": 0.12
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
            "rate": 0.60
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
            "rate": 0.95
        ])
    }));

    addSpecification("cooldown", 60);
    addSpecification("event handler", "soulfireEvent");
    addSpecification("command template", "soulfire [at ##Target##]");

    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::ignite## ##TargetName##'s very soul with sacred fire! "
        "The ethereal flames burn from within, draining "
        "##TargetPossessive## essence!");
}
