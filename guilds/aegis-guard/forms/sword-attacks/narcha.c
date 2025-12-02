//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Narcha");
    addSpecification("source", "Aegis Guard");
    addSpecification("description", "This research provides the user with the "
        "knowledge of a hewing technique known to the Aegis Guard as narcha. "
        "It is a form that can either be done by itself or as part of a "
        "combination attack.");
    addSpecification("usage summary", "A master hewing technique suitable "
        "against all defenses.");

    addPrerequisite("/guilds/aegis-guard/forms/sword-attacks/asta-dravn.c",
        (["type":"research"]));

    addSpecification("limited by", (["equipment":({ "dagger", "short sword",
        "long sword", "hand and a half sword", "two-handed sword" })]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Aegis Guard",
            "value": 31
        ]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("stamina point cost", 175);

    addSpecification("damage hit points", ({ ([
            "probability": 80,
            "base damage": 200,
            "range": 250
        ]),
        ([
            "probability": 20,
            "base damage": 300,
            "range": 500
        ])
    }));
    addSpecification("damage type", "slash");

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/aegis-guard/forms/sword-attacks/lelyan-isilme.c",
            "name": "Lelyan Isilme",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item": "/guilds/aegis-guard/forms/sword-evading/dagnir-rhinc.c",
            "name": "Dagnir Rhinc",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item": "/guilds/aegis-guard/forms/sword-evading/pirin-maed-tir.c",
            "name": "Pirin Maed Tir",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item": "/guilds/aegis-guard/forms/sword-guarding/mithrannon.c",
            "name": "Mithrannon",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/aegis-guard/forms/sword-evading/nista-ai-mab.c",
            "name": "Nista ai Mab",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "weapon damage",
            "name" : "sword",
            "types" : ({ "dagger", "short sword", "long sword",
                "hand and a half sword", "two-handed sword" }),
            "formula" : "additive",
            "rate" : 0.5
        ]),
        ([
            "type":"highest skill",
            "name": "sword skills",
            "skills": ({ "dagger", "short sword", "long sword", 
                "hand and a half sword", "two-handed sword" }),
            "formula": "additive",
            "rate": 0.75
        ]),
        ([
            "type": "skill",
            "name": "dancing",
            "formula": "additive",
            "rate": 1.0
        ]),
        ([
            "type": "skill",
            "name": "acrobatics",
            "formula": "additive",
            "rate": 1.0
        ]),
        ([
            "type": "skill",
            "name": "anatomy and physiology",
            "formula": "additive",
            "rate": 1.0
        ]),
        ([
            "type": "skill",
            "name": "perception",
            "formula": "additive",
            "rate": 0.5
        ]),
        ([
            "type":"attribute",
            "name": "strength",
            "formula": "additive",
            "rate": 0.25
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
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.25
        ]),
    }));

    addSpecification("cooldown", 20);
    addSpecification("event handler", "narchaEvent");
    addSpecification("command template", "narcha");
    addSpecification("use ability message",  "##InitiatorPossessive::Name## "
        "##Infinitive::lash## out with ##InitiatorPossessive## "
        "##InitiatorWeapon## from a high guard around ##InitiatorPossessive## "
        "body attacking everyone within reach.");
    addSpecification("use combination message", "##Infinitive::lash## "
        "out in a graceful arc");
}
