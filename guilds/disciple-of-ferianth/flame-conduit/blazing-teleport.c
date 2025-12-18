//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Blazing Teleport");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "While in your flame conduit form, you can "
        "dissolve into pure flame and streak across the battlefield, leaving "
        "a trail of fire that damages enemies in your path.");
    addSpecification("usage summary", "A short-range movement ability that "
        "damages enemies in your path");

    addPrerequisite("/guilds/disciple-of-ferianth/flame-conduit/infernal-veins.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 27
        ]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 60);
    addSpecification("cooldown", 20);

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/disciple-of-ferianth/flame-conduit/conduit-root.c"
        })
    ]));

    addSpecification("siphon hit points", ({ 
        ([
            "probability": 100,
            "base damage": 30,
            "range": 50
        ])
    }));

    addSpecification("damage type", "fire");

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/flame-conduit/pyroclastic-form.c",
            "name": "Pyroclastic Form",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/flame-conduit/living-flame.c",
            "name": "Living Flame",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/flame-conduit/primordial-fire.c",
            "name": "Primordial Fire",
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
            "rate": 0.50
        ]),
        ([
            "type": "attribute",
            "name": "dexterity",
            "formula": "additive",
            "rate": 0.25
        ]),
        ([
            "type": "level",
            "name": "level",
            "formula": "additive",
            "rate": 0.50
        ])
    }));

    addSpecification("command template", "blazing teleport");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::dissolve## into pure flame and ##Infinitive::streak## "
        "across the area, leaving a blazing trail of sacred fire!");
}
