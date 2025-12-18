//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Inferno Nova");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "While in your flame conduit form, you can "
        "release an explosive burst of divine fire in all directions, engulfing "
        "all enemies around you in Ferianth's sacred flames.");
    addSpecification("usage summary", "A powerful area-of-effect fire explosion");

    addPrerequisite("/guilds/disciple-of-ferianth/flame-conduit/living-flame.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 35
        ]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addSpecification("spell point cost", 100);
    addSpecification("cooldown", 30);

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/disciple-of-ferianth/flame-conduit/conduit-root.c"
        })
    ]));

    addSpecification("damage hit points", ({ 
        ([
            "probability": 60,
            "base damage": 75,
            "range": 100
        ]),
        ([
            "probability": 40,
            "base damage": 125,
            "range": 150
        ])
    }));

    addSpecification("damage type", "fire");

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/flame-conduit/molten-core.c",
            "name": "Molten Core",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/flame-conduit/phoenix-essence.c",
            "name": "Phoenix Essence",
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
            "rate": 1.35
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
            "rate": 0.75
        ]),
        ([
            "type": "level",
            "name": "level",
            "formula": "additive",
            "rate": 1.00
        ])
    }));

    addSpecification("command template", "inferno nova");
    addSpecification("use ability message", "##InitiatorPossessive::Name## "
        "form ##Infinitive::erupt## in a devastating nova of divine fire, "
        "sacred flames ##Infinitive::engulf## everything nearby!");
}
