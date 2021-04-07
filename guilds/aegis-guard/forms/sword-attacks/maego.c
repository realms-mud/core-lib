//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Maego");
    addSpecification("source", "Aegis Guard");
    addSpecification("description", "This research provides the user with the "
        "knowledge of a stabbing technique known to the Aegis Guard as maego. "
        "It is a form that can either be done by itself or as part of a "
        "combination attack.");
    addSpecification("usage summary", "An advanced thrust used to break "
        "an opponent's low guards.");

    addPrerequisite("guilds/aegis-guard/forms/sword-attacks/maetha.c",
        (["type":"research"]));
    addPrerequisite("guilds/aegis-guard/forms/sword-evading/pirin-tir.c",
        (["type":"research"]));
    addPrerequisite("guilds/aegis-guard/forms/sword-evading/gwaedrhen.c",
        (["type":"research"]));

    addSpecification("limited by", (["equipment":({ "dagger", "short sword",
        "long sword", "hand and a half sword", "two-handed sword" })]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Aegis Guard",
            "value": 29
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("stamina point cost", 150);

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
    addSpecification("damage type", "thrust");

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "guilds/aegis-guard/forms/sword-attacks/lelyan-isilme.c",
            "name": "Lelyan Isilme",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item": "guilds/aegis-guard/forms/sword-evading/dagnir-rhinc.c",
            "name": "dagnir-rhinc",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item": "guilds/aegis-guard/forms/sword-evading/pirin-maed-tir.c",
            "name": "pirin-maed-tir",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item": "guilds/aegis-guard/forms/sword-guarding/mithrannon.c",
            "name": "Mithrannon",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "guilds/aegis-guard/forms/sword-evading/nista-ai-mab.c",
            "name": "nista-ai-mab",
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
    addSpecification("event handler", "maegoEvent");
    addSpecification("command template", "maego [at ##Target##]");
    addSpecification("use ability message",  "##InitiatorPossessive::Name## "
        "##Infinitive::stab## ##InitiatorPossessive## "
        "##InitiatorWeapon## from an overhew into ##TargetName##.");
    addSpecification("use combination message", "##Infinitive::stab## "
        "from an overhew");
}
