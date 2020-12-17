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
        addSpecification("name", "Maetha");
        addSpecification("source", "Aegis Guard");
        addSpecification("description", "This research provides the user with the "
            "knowledge of a swordplay technique known to the Aegis Guard as maetha. "
            "It is a form that can either be done by itself or as part of a "
            "combination attack.");
        addSpecification("usage summary", "An advanced slashing attack used to "
            "throw enemies off balance.");

        addPrerequisite("guilds/aegis-guard/forms/sword-attacks/lanna-dravn.c",
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
        addSpecification("stamina point cost", 75);

        addSpecification("damage hit points", ({ ([
                "probability": 80,
                "base damage": 100,
                "range": 150
            ]),
            ([
                "probability": 20,
                "base damage": 200,
                "range": 150
            ])
        }));
        addSpecification("damage type", "slash");

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
                "research item": "guilds/aegis-guard/forms/sword-attacks/centhlein-dravn.c",
                "name": "Centhlein Dravn",
                "formula": "multiplicative",
                "base value": 1,
                "rate": 1.15
            ]),
            ([
                "type": "research",
                "research item": "guilds/aegis-guard/forms/sword-attacks/asta-dravn.c",
                "name": "Asta Dravn",
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
                "type":"highest skill",
                "name": "sword skills",
                "skills": ({ "dagger", "short sword", "long sword", 
                    "hand and a half sword", "two-handed sword" }),
                "formula": "additive",
                "rate": 0.5
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
                "rate": 0.35
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

        addSpecification("cooldown", 10);
        addSpecification("event handler", "maethaEvent");
        addSpecification("command template", "maetha [at ##Target##]");
        addSpecification("use ability message",  "##InitiatorPossessive::Name## "
            "##Infinitive::swing## ##InitiatorPossessive## "
            "##InitiatorWeapon## from a high guard at ##TargetName##.");
        addSpecification("use combination message", "##Infinitive::swing## "
            "in a graceful arc from a high guard");
    }
}
