//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Gliri");
    addSpecification("source", "Aegis Guard");
    addSpecification("description", "This research provides the user with the "
        "knowledge of a slashing technique moving from various hews "
        "particularly great at breaking down heavily-armored defenses. It is "
        "known to the Aegis Guard as gliri. It is a form that "
        "can only be done as part of a combination attack.");
    addSpecification("usage summary", "An artful dance of blades that "
        "shatters defenses.");

    addPrerequisite("guilds/aegis-guard/forms/sword-guarding/raeg.c",
        (["type":"research"]));

    addSpecification("limited by", (["equipment":({ "dagger", "short sword",
        "long sword", "hand and a half sword", "two-handed sword" })]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Aegis Guard",
            "value": 19
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("stamina point cost", 45);

    addSpecification("damage hit points", ({ ([
            "probability": 80,
            "base damage": 90,
            "range": 90
        ]),
        ([
            "probability": 20,
            "base damage": 175,
            "range": 175
        ])
    }));
    addSpecification("damage type", "slash");

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "guilds/aegis-guard/forms/sword-actions/delu-an-gliri.c",
            "name": "angannon",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "guilds/aegis-guard/forms/sword-guarding/braig-an-gliri.c",
            "name": "glingamath",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type":"research",
            "research item" : "guilds/aegis-guard/forms/sword-guarding/tur-gliraen.c",
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
    addSpecification("event handler", "gliriEvent");

    addSpecification("use combination message", "##Infinitive::swing## "
        "##InitiatorPossessive## ##InitiatorWeapon## quickly such that it sings");
}
