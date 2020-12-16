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
        addSpecification("name", "Esgeri");
        addSpecification("source", "Aegis Guard");
        addSpecification("description", "This research provides the user with the "
            "knowledge of a cutting technique known to the Aegis Guard as esgeri. "
            "It is a form that can either be done by itself or as part of a "
            "combination attack.");

        addPrerequisite("guilds/aegis-guard/forms/sword/tharcuth.c",
            (["type":"research"]));

        addSpecification("limited by", (["equipment":({ "dagger", "short sword",
            "long sword", "hand and a half sword", "two-handed sword" })]));

        addPrerequisite("level",
            (["type":"level",
                "guild": "Aegis Guard",
                "value": 4
            ]));

        addSpecification("scope", "targeted");
        addSpecification("research type", "points");
        addSpecification("research cost", 1);
        addSpecification("stamina point cost", 20);

        addSpecification("damage hit points", ({ ([
                "probability": 80,
                "base damage": 8,
                "range": 8
            ]),
            ([
                "probability": 20,
                "base damage": 16,
                "range": 16
            ])
        }));
        addSpecification("damage type", "slash");

        addSpecification("modifiers", ({ 
            ([
                "type": "research",
                "research item": "guilds/aegis-guard/forms/sword/diyacuth.c",
                "name": "diyacuth",
                "formula": "multiplicative",
                "base value": 1,
                "rate": 1.5
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
        addSpecification("event handler", "esgeriEvent");
        addSpecification("command template", "esgeri [at ##Target##]");
        addSpecification("use ability message",  "##InitiatorPossessive::Name## "
            "##Infinitive::sweep## ##InitiatorPossessive## "
            "##InitiatorWeapon## at ##TargetName## in a graceful cutting motion.");
        addSpecification("use combination message", "##Infinitive::cut## "
            "viciously");
    }
}
