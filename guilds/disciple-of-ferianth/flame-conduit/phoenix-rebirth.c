//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Phoenix Rebirth");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "While in your flame conduit form and "
        "gravely wounded, you can call upon the phoenix essence within you "
        "to be reborn from your own flames, restoring your vitality.");
    addSpecification("usage summary", "A powerful self-heal that can only be "
        "used when near death");

    addPrerequisite("/guilds/disciple-of-ferianth/flame-conduit/phoenix-essence.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 43
        ]));

    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("research type", "points");
    addSpecification("research cost", 2);
    addSpecification("spell point cost", 150);
    addSpecification("cooldown", 300);

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/disciple-of-ferianth/flame-conduit/conduit-root.c"
        }),
        "near death": 25
    ]));

    addSpecification("increase hit points", ({ 
        ([
            "probability": 100,
            "base damage": 100,
            "range": 150
        ])
    }));

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/flame-conduit/sun-touched.c",
            "name": "Sun-Touched",
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
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/flame-conduit/fire-eternal.c",
            "name": "Fire Eternal",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.35
        ]),
        ([
            "type": "skill",
            "name": "elemental fire",
            "formula": "additive",
            "rate": 0.20
        ]),
        ([
            "type": "skill",
            "name": "theology",
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
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.50
        ]),
        ([
            "type": "attribute",
            "name": "constitution",
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

    addSpecification("command template", "phoenix rebirth");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::erupt## in a brilliant explosion of sacred flame and "
        "##Infinitive::rise## reborn like the divine phoenix from the ashes!");
}
