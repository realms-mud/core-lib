//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Sonic Volley");
    addSpecification("source", "bard");
    addSpecification("description", "This research provides the user with the "
        "knowledge of a song that converts their arrow into a hail of sonic "
        "arrows that target a single foe.");

    addPrerequisite("/guilds/bard/bow/the-archers-song.c",
        (["type":"research"]));

    addSpecification("limited by", (["equipment":({ "bow" })]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "bard",
            "value": 29
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("damage hit points", ({ ([
            "probability": 90,
            "base damage" : 100,
            "range" : 200
        ]),
        ([
            "probability":10,
            "base damage" : 200,
            "range" : 500
        ])
    }));

    addSpecification("damage spell points", ({ ([
            "probability":90,
            "base damage" : 50,
            "range" : 100
        ]),
        ([
            "probability": 10,
            "base damage": 100,
            "range" : 200
        ])
    }));

    addSpecification("damage type", "sonic");

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/bard/bow/enhanced-sonic-shaft.c",
            "name": "Enhanced Sonic Shaft",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/bard/bow/ballad-of-the-bow.c",
            "name": "Ballad of the Bow",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/bard/bow/archers-elegy.c",
            "name": "Archer's Elegy",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/bard/bow/arrowheads-lament.c",
            "name": "Arrowhead's Lament",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/bard/bow/shafts-serenade.c",
            "name": "Shaft's Serenade",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/bard/bow/bowmans-tale.c",
            "name": "Bowman's Tale",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/bard/bow/lay-of-the-archer.c",
            "name": "Lay of the Archer",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.5
        ]),
        ([
            "type": "weapon damage",
            "name" : "bow",
            "types" : ({ "bow" }),
            "formula" : "additive",
            "rate" : 1.75
        ]),
        ([
            "type": "skill",
            "name": "bow",
            "formula": "logarithmic",
            "rate": 1.25
        ]), 
        ([
            "type": "skill",
            "name": "anatomy and physiology",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "skill",
            "name": "physics",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "skill",
            "name": "mathematics",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "attribute",
            "name": "dexterity",
            "formula": "additive",
            "rate": 0.25
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.25
        ]),
    }));

    addSpecification("consumables", (["arrow": 1]));

    addSpecification("spell point cost", 250);
    addSpecification("spell point cost modifiers", ([
        "/guilds/bard/bow/rhythmic-release.c": 10,
        "/guilds/bard/bow/bowmans-form.c": 10,
        "/guilds/bard/bow/bowmans-breath.c": 10,
        "/guilds/bard/bow/minstrels-aim.c": 10
    ]));

    addSpecification("stamina point cost", 150);
    addSpecification("stamina point cost modifiers", ([
        "/guilds/bard/bow/rhythmic-release.c": 10,
        "/guilds/bard/bow/bowmans-form.c": 10,
        "/guilds/bard/bow/bowmans-breath.c": 10,
        "/guilds/bard/bow/minstrels-aim.c": 10
    ]));

    addSpecification("cooldown", 80);
    addSpecification("cooldown modifiers", ([
        "/guilds/bard/bow/archers-hand.c": 10,
        "/guilds/bard/bow/song-of-the-swift.c": 10,
        "/guilds/bard/bow/requiem-of-the-quick-draw.c": 10,
        "/guilds/bard/bow/bowmans-pace.c": 10,
    ]));

    addSpecification("event handler", "sonicVolleyEvent");
    addSpecification("command template", "sonic volley [at ##Target##]");
    addSpecification("use ability message",  "##InitiatorPossessive::Name## "
        "##Infinitive::aim## ##InitiatorPossessive## "
        "##InitiatorWeapon## at ##TargetName## and ##Infinitive::chant##. As "
        "the arrow looses, it turns into a hail of sonic arrows.");
}
