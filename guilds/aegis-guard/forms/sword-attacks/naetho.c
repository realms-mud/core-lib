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
        addSpecification("name", "Naetho");
        addSpecification("source", "Aegis Guard");
        addSpecification("description", "This research provides the user with the "
            "knowledge of a stabbing technique known to the Aegis Guard as naetho. "
            "It is a form that can either be done by itself or as part of a "
            "combination attack.");
        addSpecification("usage summary", "An advanced thrusting technique "
            "well-suited to circumventing shields.");

        addPrerequisite("guilds/aegis-guard/forms/sword-attacks/gwistamacil.c",
            (["type":"research"]));

        addSpecification("limited by", (["equipment":({ "dagger", "short sword",
            "long sword", "hand and a half sword", "two-handed sword" })]));

        addPrerequisite("level",
            (["type":"level",
                "guild": "Aegis Guard",
                "value": 15
            ]));

        addSpecification("scope", "targeted");
        addSpecification("research type", "points");
        addSpecification("research cost", 1);
        addSpecification("stamina point cost", 50);

        addSpecification("damage hit points", ({ ([
                "probability": 80,
                "base damage": 50,
                "range": 100
            ]),
            ([
                "probability": 20,
                "base damage": 150,
                "range": 100
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
                "rate": 1.25
            ]),
            ([
                "type":"research",
                "research item": "guilds/aegis-guard/forms/sword-attacks/ruth-dravn.c",
                "name" : "Ruth Dravn",
                "formula" : "multiplicative",
                "base value" : 1,
                "rate": 1.15
            ]),
            ([
                "type":"research",
                "research item": "guilds/aegis-guard/forms/sword-attacks/lanna-dravn.c",
                "name" : "Lanna Dravn",
                "formula" : "multiplicative",
                "base value" : 1,
                "rate": 1.15
            ]),
            ([
                "type": "research",
                "research item" : "guilds/aegis-guard/forms/sword-attacks/centhlein-dravn.c",
                "name" : "Centhlein Dravn",
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
                "rate": 0.25
            ]),
            ([
                "type": "skill",
                "name": "acrobatics",
                "formula": "additive",
                "rate": 0.25
            ]),
            ([
                "type": "skill",
                "name": "anatomy and physiology",
                "formula": "additive",
                "rate": 0.25
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
                "rate": 0.25
            ]),
            ([
                "type": "attribute",
                "name": "intelligence",
                "formula": "additive",
                "rate": 0.25
            ]),
        }));

        addSpecification("cooldown", 6);
        addSpecification("event handler", "naethoEvent");
        addSpecification("command template", "naetho [at ##Target##]");
        addSpecification("use ability message",  "##InitiatorPossessive::Name## "
            "##Infinitive::stab## ##InitiatorPossessive## "
            "##InitiatorWeapon## at ##TargetName## with an artful thrusting motion.");
        addSpecification("use combination message", "##Infinitive::stab## "
            "artfully");
    }
}
