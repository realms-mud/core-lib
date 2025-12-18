//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Immolating Grasp");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "While in your flame conduit form, you can "
        "seize an enemy with hands of pure divine fire, inflicting severe burns "
        "and siphoning their life force to fuel your flames.");
    addSpecification("usage summary", "A powerful touch-range fire attack that "
        "siphons hit points");

    addPrerequisite("/guilds/disciple-of-ferianth/flame-conduit/blazing-soul.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 19
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 60);
    addSpecification("cooldown", 12);

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/disciple-of-ferianth/flame-conduit/conduit-root.c"
        })
    ]));

    addSpecification("siphon hit points", ({ 
        ([
            "probability": 70,
            "base damage": 50,
            "range": 75
        ]),
        ([
            "probability": 30,
            "base damage": 80,
            "range": 100
        ])
    }));

    addSpecification("siphon spell points", ({ 
        ([
            "probability": 100,
            "base damage": 15,
            "range": 25
        ])
    }));

    addSpecification("damage type", "fire");

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/flame-conduit/heart-of-cinders.c",
            "name": "Heart of Cinders",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/flame-conduit/living-flame.c",
            "name": "Living Flame",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/flame-conduit/primordial-fire.c",
            "name": "Primordial Fire",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.30
        ]),
        ([
            "type": "skill",
            "name": "elemental fire",
            "formula": "additive",
            "rate": 0.20
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
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
            "name": "strength",
            "formula": "additive",
            "rate": 0.25
        ]),
        ([
            "type": "level",
            "name": "level",
            "formula": "additive",
            "rate": 0.75
        ])
    }));

    addSpecification("command template", "immolating grasp [##Target##]");
    addSpecification("use ability message", "##InitiatorPossessive::Name## "
        "blazing hands ##Infinitive::seize## ##TargetName##, sacred fire "
        "##Infinitive::sear## deep into ##TargetPossessive## flesh!");
}
