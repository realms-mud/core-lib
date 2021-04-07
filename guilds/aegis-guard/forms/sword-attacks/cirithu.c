//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    addSpecification("name", "Cirithu");
    addSpecification("source", "Aegis Guard");
    addSpecification("description", "This research provides the user with the "
        "knowledge of a cleaving technique known to the Aegis Guard as cirithu. "
        "It is a form that can either be done by itself or as part of a "
        "combination attack.");
    addSpecification("usage summary", "A cleave well-suited against "
        "lightly-armored opponents.");

    addPrerequisite("guilds/aegis-guard/forms/sword-attacks/diyacuth.c",
        (["type":"research"]));

    addSpecification("limited by", (["equipment":({ "dagger", "short sword",
        "long sword", "hand and a half sword", "two-handed sword" })]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Aegis Guard",
            "value": 6
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("stamina point cost", 25);

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
            "research item": "guilds/aegis-guard/forms/sword-attacks/dravnu.c",
            "name": "dravnu",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item": "guilds/aegis-guard/forms/sword-attacks/enaidravn.c",
            "name": "enaidravn",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type":"research",
            "research item" : "guilds/aegis-guard/forms/sword-attacks/edaid-lhewig.c",
            "name" : "edaid-lhewig",
            "formula" : "multiplicative",
            "base value" : 1,
            "rate" : 1.25
        ]),            
        ([
            "type": "research",
            "research item" : "guilds/aegis-guard/forms/sword-attacks/raica-dravn.c",
            "name" : "raica-dravn",
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
    addSpecification("event handler", "cirithuEvent");
    addSpecification("command template", "cirithu [at ##Target##]");
    addSpecification("use ability message",  "##InitiatorPossessive::Name## "
        "##Infinitive::sweep## ##InitiatorPossessive## "
        "##InitiatorWeapon## at ##TargetName## in a powerful cleaving motion.");
    addSpecification("use combination message", "##Infinitive::cleave## "
        "brutally");
}
