//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        instantaneousActiveResearchItem::reset(arg);
        addSpecification("name", "Ercho");
        addSpecification("source", "Aegis Guard");
        addSpecification("description", "This research provides the user with the "
            "knowledge of a stabbing technique known to the Aegis Guard as ercho. "
            "It is a form that can either be done by itself or as part of a "
            "combination attack.");

        addPrerequisite("guilds/aegis-guard/forms/sword-attacks/eithagos.c",
            (["type":"research"]));

        addSpecification("limited by", (["equipment":({ "dagger", "short sword",
            "long sword", "hand and a half sword", "two-handed sword" })]));

        addPrerequisite("level",
            (["type":"level",
                "guild": "Aegis Guard",
                "value": 2
            ]));

        addSpecification("scope", "targeted");
        addSpecification("research type", "points");
        addSpecification("research cost", 1);
        addSpecification("stamina point cost", 15);

        addSpecification("damage hit points", ({ ([
                "probability": 80,
                "base damage": 5,
                "range": 5
            ]),
            ([
                "probability": 20,
                "base damage": 10,
                "range": 10
            ])
        }));
        addSpecification("damage type", "thrust");

        addSpecification("modifiers", ({ 
            ([
                "type": "research",
                "research item": "guilds/aegis-guard/forms/sword-guarding/alagos-tir-angannon.c",
                "name": "Alagos Tir Angannon",
                "formula": "multiplicative",
                "base value": 1,
                "rate": 1.25
            ]),
            ([
                "type":"research",
                "research item": "guilds/aegis-guard/forms/sword-guarding/raud-angannon.c",
                "name" : "Raud Angannon",
                "formula" : "multiplicative",
                "base value" : 1,
                "rate": 1.25
            ]),
            ([
                "type": "research",
                "research item" : "guilds/aegis-guard/forms/sword-attacks/gwistamacil.c",
                "name" : "gwistamacil",
                "formula" : "multiplicative",
                "base value" : 1,
                "rate" : 1.15
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

        addSpecification("cooldown", 6);
        addSpecification("event handler", "erchoEvent");
        addSpecification("command template", "ercho [at ##Target##]");
        addSpecification("use ability message",  "##InitiatorPossessive::Name## "
            "##Infinitive::feint##, ##Infinitive::double## back, and "
            "##Infinitive::stab## ##InitiatorPossessive## "
            "##InitiatorWeapon## at ##TargetName##.");
        addSpecification("use combination message", "##Infinitive::stab## "
            "viciously");
    }
}
