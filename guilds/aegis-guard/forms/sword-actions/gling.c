//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Gling");
    addSpecification("source", "Aegis Guard");
    addSpecification("description", "This research provides the user with the "
        "knowledge of a hewing technique moving from a hanging point to "
        "a quick upward slash known to the Aegis Guard as gling. It is a "
        "form that can only be done as part of a combination attack.");
    addSpecification("usage summary", "An upward slash from a hanging "
        "point - effective at breaking guards.");

    addPrerequisite("/guilds/aegis-guard/forms/sword-attacks/glin-an-aemas.c",
        (["type":"research"]));

    addSpecification("limited by", (["equipment":({ "dagger", "short sword",
        "long sword", "hand and a half sword", "two-handed sword" })]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Aegis Guard",
            "value": 14
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("stamina point cost", 30);

    addSpecification("damage hit points", ({ ([
            "probability": 80,
            "base damage": 60,
            "range": 60
        ]),
        ([
            "probability": 20,
            "base damage": 100,
            "range": 100
        ])
    }));
    addSpecification("damage type", "slash");

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/aegis-guard/forms/sword-actions/delu-an-gling.c",
            "name": "Delu an Gling",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type":"research",
            "research item" : "/guilds/aegis-guard/forms/sword-actions/braig-an-gling.c",
            "name" : "Braig an Gling",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate" : 1.25
        ]),            
        ([
            "type": "research",
            "research item" : "/guilds/aegis-guard/forms/sword-actions/tur-glingal.c",
            "name" : "Tur Glingal",
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
    addSpecification("event handler", "glingEvent");

    addSpecification("use combination message", "##Infinitive::slash## "
        "##InitiatorPossessive## ##InitiatorWeapon## from a hanging point");
}
