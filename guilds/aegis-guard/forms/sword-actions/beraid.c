//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Beraid");
    addSpecification("source", "Aegis Guard");
    addSpecification("description", "This research provides the user with the "
        "knowledge of a slashing technique moving from various stabs "
        "particularly great at breaking down heavily-armored defenses. It is "
        "known to the Aegis Guard as beraid. It is a form that "
        "can only be done as part of a combination attack.");
    addSpecification("usage summary", "A punishing stab capable of shattering "
        "any guards.");

    addPrerequisite("guilds/aegis-guard/forms/sword-guarding/gliri.c",
        (["type":"research"]));

    addSpecification("limited by", (["equipment":({ "dagger", "short sword",
        "long sword", "hand and a half sword", "two-handed sword" })]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Aegis Guard",
            "value": 23
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("stamina point cost", 50);

    addSpecification("damage hit points", ({ ([
            "probability": 80,
            "base damage": 100,
            "range": 100
        ]),
        ([
            "probability": 20,
            "base damage": 200,
            "range": 200
        ])
    }));
    addSpecification("damage type", "thrust");

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "guilds/aegis-guard/forms/sword-actions/delu-an-beraid.c",
            "name": "angannon",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "guilds/aegis-guard/forms/sword-guarding/braig-an-beraid.c",
            "name": "glingamath",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type":"research",
            "research item" : "guilds/aegis-guard/forms/sword-guarding/tur-beraid.c",
            "name" : "raud-angannon",
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
    addSpecification("event handler", "beraidEvent");

    addSpecification("use combination message", "##Infinitive::thrust## "
        "##InitiatorPossessive## ##InitiatorWeapon## in a shattering stab");
}
