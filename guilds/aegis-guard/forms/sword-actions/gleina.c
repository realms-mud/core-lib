//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        instantaneousActiveResearchItem::reset(arg);
        addSpecification("name", "Gleina");
        addSpecification("source", "Aegis Guard");
        addSpecification("description", "This research provides the user with the "
            "knowledge of a hewing technique moving from a high guard to "
            "a quick stab known to the Aegis Guard as gleina. It is a form that "
            "can only be done as part of a combination attack.");
        addSpecification("usage summary", "A feint designed to box an opponent "
            "in, limiting future movement.");

        addPrerequisite("guilds/aegis-guard/forms/sword-actions/lanc.c",
            (["type":"research"]));

        addSpecification("limited by", (["equipment":({ "dagger", "short sword",
            "long sword", "hand and a half sword", "two-handed sword" })]));

        addPrerequisite("level",
            (["type":"level",
                "guild": "Aegis Guard",
                "value": 13
            ]));

        addSpecification("scope", "targeted");
        addSpecification("research type", "points");
        addSpecification("research cost", 1);
        addSpecification("stamina point cost", 25);

        addSpecification("damage hit points", ({ ([
                "probability": 80,
                "base damage": 50,
                "range": 50
            ]),
            ([
                "probability": 20,
                "base damage": 75,
                "range": 100
            ])
        }));
        addSpecification("damage type", "thrust");

        addSpecification("modifiers", ({ 
            ([
                "type": "research",
                "research item": "guilds/aegis-guard/forms/sword-attacks/lelyan-isilme.c",
                "name": "lelyan-isilme",
                "formula": "multiplicative",
                "base value": 1,
                "rate": 1.25
            ]),
            ([
                "type":"research",
                "research item" : "guilds/aegis-guard/forms/sword-attacks/ruth-dravn.c",
                "name" : "raud-angannon",
                "formula" : "multiplicative",
                "base value" : 1,
                "rate" : 1.15
            ]),            
            ([
                "type": "research",
                "research item" : "guilds/aegis-guard/forms/sword-combinations/tur-godref.c",
                "name" : "mithrannon",
                "formula" : "multiplicative",
                "base value" : 1,
                "rate" : 1.50
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
        addSpecification("event handler", "gleinaEvent");

        addSpecification("use combination message", "quickly ##Infinitive::slash## "
            "##InitiatorPossessive## ##InitiatorWeapon## from high guard into a stab");
    }
}
