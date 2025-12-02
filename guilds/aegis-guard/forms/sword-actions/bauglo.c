//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Bauglo");
    addSpecification("source", "Aegis Guard");
    addSpecification("description", "This research provides the user with the "
        "knowledge of a slashing technique based loosely from Beraid that "
        "can hit multiple targets. It is particularly great at breaking "
        "down heavily-armored defenses. It is known to the Aegis Guard as "
        "bauglo. It is a form that can only be done as part of a combination "
        "attack.");
    addSpecification("usage summary", "A punishing series of slashes "
        "that can bypass multiple foes' armor.");

    addPrerequisite("/guilds/aegis-guard/forms/sword-guarding/beraid.c",
        (["type":"research"]));

    addSpecification("limited by", (["equipment":({ "dagger", "short sword",
        "long sword", "hand and a half sword", "two-handed sword" })]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Aegis Guard",
            "value": 30
        ]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("stamina point cost", 75);

    addSpecification("damage hit points", ({ ([
            "probability": 80,
            "base damage": 150,
            "range": 150
        ]),
        ([
            "probability": 20,
            "base damage": 250,
            "range": 250
        ])
    }));
    addSpecification("damage type", "thrust");

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/aegis-guard/forms/sword-actions/delu-an-beraid.c",
            "name": "Delu an Beraid",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/aegis-guard/forms/sword-actions/braig-an-beraid.c",
            "name": "Braig an Beraid",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type":"research",
            "research item" : "/guilds/aegis-guard/forms/sword-actions/tur-beraid.c",
            "name" : "Tur Beraid",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate" : 1.25
        ]),       
        ([
            "type": "weapon damage",
            "name" : "sword",
            "types" : ({ "dagger", "short sword", "long sword",
                "hand and a half sword", "two-handed sword" }),
            "formula" : "additive",
            "rate" : 1.0
        ]),
        ([
            "type":"highest skill",
            "name" : "sword skills",
            "skills": ({ "dagger", "short sword", "long sword", 
                "hand and a half sword", "two-handed sword" }),
            "formula" : "additive",
            "rate" : 0.5
        ]),
        ([
            "type": "skill",
            "name": "dancing",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "skill",
            "name": "acrobatics",
            "formula": "additive",
            "rate": 0.10
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
            "type":"attribute",
            "name": "strength",
            "formula": "additive",
            "rate": 0.5
        ]), 
        ([
            "type": "attribute",
            "name": "dexterity",
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

    addSpecification("cooldown", 8);
    addSpecification("event handler", "naergoEvent");

    addSpecification("use combination message", "##Infinitive::slash## "
        "##InitiatorPossessive## ##InitiatorWeapon## in an oppressive arc");
}
