//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Heleg");
    addSpecification("source", "Aegis Guard");
    addSpecification("description", "This research provides the user with the "
        "knowledge of a technique that allows one to project a blast of elemental "
        "frigid water energy known to the Aegis Guard as heleg. "
        "It is a form that can either be done by itself or as part of a "
        "combination attack.");
    addSpecification("usage summary", "A technique projecting a wave of "
        "elemental earth energy");

    addPrerequisite("/guilds/aegis-guard/forms/sword-elemental/luithia.c",
        (["type":"research"]));

    addSpecification("limited by", (["equipment":({ "dagger", "short sword",
        "long sword", "hand and a half sword", "two-handed sword" })]));

    addPrerequisite("level", ([  
        "type":"level",
        "guild": "Aegis Guard",
        "value": 31
    ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addSpecification("damage hit points", ({ ([
            "probability": 90,
            "base damage": 200,
            "range": 300
        ]),
        ([
            "probability": 10,
            "base damage": 300,
            "range": 600
        ])
    }));
    addSpecification("damage spell points", ({ ([
            "probability": 90,
            "base damage": 75,
            "range": 150
        ]),
        ([
            "probability": 10,
            "base damage": 150,
            "range": 250
        ])
    }));
    addSpecification("damage type", "cold");

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/aegis-guard/forms/sword-elemental/angol-anwar.c",
            "name": "Angol Anwar",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item": "/guilds/aegis-guard/forms/sword-elemental/angol-celair.c",
            "name": "Angol Celair",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item": "/guilds/aegis-guard/forms/sword-elemental/angol-edlothia.c",
            "name": "Angol Edlothia",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item": "/guilds/aegis-guard/forms/sword-elemental/angol-eiliant.c",
            "name": "Angol Eiliant",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item": "/guilds/aegis-guard/forms/sword-elemental/angol-manadh.c",
            "name": "Angol Manadh",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/aegis-guard/forms/sword-elemental/angol-dagnir.c",
            "name": "Angol Dagnir",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "skill",
            "name": "elemental water",
            "formula": "logarithmic",
            "rate": 1.10
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.05
        ]),
        ([
            "type": "skill",
            "name": "magical essence",
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
            "type":"attribute",
            "name": "charisma",
            "formula": "additive",
            "rate": 0.25
        ]), 
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.5
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.5
        ]),
    }));

    addSpecification("spell point cost", 300);
    addSpecification("spell point cost modifiers", ([
        "/guilds/aegis-guard/forms/sword-elemental/faen-celair.c": 15,
        "/guilds/aegis-guard/forms/sword-elemental/faen-edlothia.c": 15,
        "/guilds/aegis-guard/forms/sword-elemental/faen-manadh.c": 10,
        "/guilds/aegis-guard/forms/sword-elemental/faen-dagnir.c": 10
    ]));

    addSpecification("cooldown", 150);
    addSpecification("cooldown modifiers", ([
        "/guilds/aegis-guard/forms/sword-elemental/heleg-celair.c": 10,
        "/guilds/aegis-guard/forms/sword-elemental/heleg-edlothia.c": 10,
        "/guilds/aegis-guard/forms/sword-elemental/heleg-manadh.c": 10,
        "/guilds/aegis-guard/forms/sword-elemental/heleg-dagnir.c": 10,
    ]));

    addSpecification("event handler", "helegEvent");
    addSpecification("command template", "heleg [at ##Target##]");
    addSpecification("use ability message",  "##InitiatorPossessive::Name## "
        "##Infinitive::gesture## ##InitiatorPossessive## "
        "##InitiatorWeapon## at ##TargetName## sending shards of ice their way.");
    addSpecification("use combination message", "##Infinitive::summon## "
        "shards of ice");
}
