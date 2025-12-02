//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Athra");
    addSpecification("source", "Aegis Guard");
    addSpecification("description", "This research provides the user with the "
        "knowledge of a slashing technique moving from 'An Aras' to "
        "'An Craban' known to the Aegis Guard as athra. It is a form that "
        "can only be done as part of a combination attack.");
    addSpecification("usage summary", "A cross-body offensive counter "
        "effective against hews.");

    addPrerequisite("/guilds/aegis-guard/forms/sword-actions/action-root.c",
        (["type":"research"]));
    addPrerequisite("/guilds/aegis-guard/forms/sword-guarding/an-aras.c",
        (["type":"research"]));
    addPrerequisite("/guilds/aegis-guard/forms/sword-actions/an-craban.c",
        (["type":"research"]));

    addSpecification("limited by", (["equipment":({ "dagger", "short sword",
        "long sword", "hand and a half sword", "two-handed sword" })]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Aegis Guard",
            "value": 7
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("stamina point cost", 10);

    addSpecification("damage hit points", ({ ([
            "probability": 80,
            "base damage": 10,
            "range": 10
        ]),
        ([
            "probability": 20,
            "base damage": 18,
            "range": 18
        ])
    }));
    addSpecification("damage type", "slash");

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/aegis-guard/forms/sword-guarding/angannon.c",
            "name": "Angannon",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.10
        ]),
        ([
            "type": "research",
            "research item": "/guilds/aegis-guard/forms/sword-guarding/glingamath.c",
            "name": "Glingamath",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.10
        ]),
        ([
            "type":"research",
            "research item" : "/guilds/aegis-guard/forms/sword-guarding/raud-angannon.c",
            "name" : "Raud Angannon",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate" : 1.15
        ]),            
        ([
            "type": "research",
            "research item" : "/guilds/aegis-guard/forms/sword-guarding/mithrannon.c",
            "name" : "Mithrannon",
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
    addSpecification("event handler", "athraEvent");

    addSpecification("use combination message", "##Infinitive::swing## "
        "##InitiatorPossessive## ##InitiatorWeapon## from high guard to low");
}
