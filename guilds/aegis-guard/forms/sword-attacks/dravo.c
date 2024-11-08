//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Dravo");
    addSpecification("source", "Aegis Guard");
    addSpecification("description", "This research provides the user with the "
        "knowledge of a hewing technique known to the Aegis Guard as dravo. "
        "It is a form that can either be done by itself or as part of a "
        "combination attack.");
    addSpecification("usage summary", "A hewing technique moving from "
        "various guards to a counter attack.");

    addPrerequisite("/guilds/aegis-guard/forms/sword-attacks/dravnu.c",
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
    addSpecification("stamina point cost", 35);

    addSpecification("damage hit points", ({ ([
            "probability": 80,
            "base damage": 15,
            "range": 15
        ]),
        ([
            "probability": 20,
            "base damage": 20,
            "range": 20
        ])
    }));
    addSpecification("damage type", "slash");

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/aegis-guard/forms/sword-attacks/thar-dravn.c",
            "name": "Thar Dravn",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item": "/guilds/aegis-guard/forms/sword-attacks/nuath-dravn.c",
            "name": "Nuath Dravn",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item": "/guilds/aegis-guard/forms/sword-attacks/enaidravn.c",
            "name": "Enaidravn",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type":"research",
            "research item" : "/guilds/aegis-guard/forms/sword-attacks/edaid-lhewig.c",
            "name" : "Edaid Lhewig",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate" : 1.25
        ]),            
        ([
            "type": "research",
            "research item" : "/guilds/aegis-guard/forms/sword-attacks/raica-dravn.c",
            "name" : "Raica Dravn",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate" : 1.25
        ]),
        ([
            "type": "research",
            "research item" : "/guilds/aegis-guard/forms/sword-attacks/gwistamacil.c",
            "name" : "Gwistamacil",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate" : 1.15
        ]),
        ([
            "type": "research",
            "research item" : "/guilds/aegis-guard/forms/sword-attacks/ruth-dravn.c",
            "name" : "Ruth Dravn",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate" : 1.25
        ]),
        ([
            "type": "research",
            "research item" : "/guilds/aegis-guard/forms/sword-attacks/lanna-dravn.c",
            "name" : "Lanna Dravn",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate" : 1.15
        ]),
        ([
            "type": "research",
            "research item" : "/guilds/aegis-guard/forms/sword-attacks/centhlein-dravn.c",
            "name" : "Centhlein Dravn",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate" : 1.15
        ]),
        ([
            "type": "research",
            "research item" : "/guilds/aegis-guard/forms/sword-attacks/asta-dravn.c",
            "name" : "Asta Dravn",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate" : 1.15
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
            "rate": 0.10
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
    addSpecification("event handler", "dravoEvent");
    addSpecification("command template", "dravo [at ##Target##]");
    addSpecification("use ability message",  "##InitiatorPossessive::Name## "
        "##Infinitive::arc## ##InitiatorPossessive## "
        "##InitiatorWeapon## at ##TargetName## in a masterful hewing motion.");
    addSpecification("use combination message", "##Infinitive::hew## "
        "masterfully");
}
