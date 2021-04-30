//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Raeg");
    addSpecification("source", "Aegis Guard");
    addSpecification("description", "This research provides the user with the "
        "knowledge of a hewing technique moving from 'Raica Dravn' to "
        "a series of quick thrusts known to the Aegis Guard as raeg. It is a form that "
        "can only be done as part of a combination attack.");
    addSpecification("usage summary", "An extension to the crooked "
        "hew - great counter against high guards.");

    addPrerequisite("/guilds/aegis-guard/forms/sword-actions/lanc.c",
        (["type":"research"]));
    addPrerequisite("/guilds/aegis-guard/forms/sword-attacks/raica-dravn.c",
        (["type":"research"]));

    addSpecification("limited by", (["equipment":({ "dagger", "short sword",
        "long sword", "hand and a half sword", "two-handed sword" })]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Aegis Guard",
            "value": 15
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("stamina point cost", 35);

    addSpecification("damage hit points", ({ ([
            "probability": 80,
            "base damage": 70,
            "range": 70
        ]),
        ([
            "probability": 20,
            "base damage": 125,
            "range": 125
        ])
    }));
    addSpecification("damage type", "thrust");

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/aegis-guard/forms/sword-attacks/lelyan-isilme.c",
            "name": "Lelyan Isilme",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type":"research",
            "research item" : "/guilds/aegis-guard/forms/sword-attacks/ruth-dravn.c",
            "name" : "Ruth Dravn",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate" : 1.15
        ]),            
        ([
            "type": "research",
            "research item" : "/guilds/aegis-guard/forms/sword-combinations/tur-godref.c",
            "name" : "Tur Godref",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate" : 1.50
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
            "type": "highest skill",
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
    addSpecification("event handler", "raegEvent");

    addSpecification("use combination message", "quickly ##Infinitive::slash## "
        "##InitiatorPossessive## ##InitiatorWeapon## from low guard to shoulder");
}
