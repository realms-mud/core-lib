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
        addSpecification("name", "Bregol Adleg");
        addSpecification("source", "Aegis Guard");
        addSpecification("description", "This research provides the user with the "
            "knowledge to set an arrow to magical stone as it flies from a bow.");

        addPrerequisite("guilds/aegis-guard/forms/bow/root.c",
            (["type":"research"]));

        addSpecification("limited by", (["equipment":({ "bow" })]));

        addPrerequisite("level",
            (["type":"level",
                "guild": "Aegis Guard",
                "value": 3
            ]));

        addSpecification("scope", "targeted");
        addSpecification("research type", "points");
        addSpecification("research cost", 1);

        addSpecification("damage hit points", ({ ([
                "probability": 80,
                "base damage": 10,
                "range": 20
            ]),
            ([
                "probability": 20,
                "base damage": 25,
                "range": 50
            ])
        }));

        addSpecification("damage type", "physical");

        addSpecification("modifiers", ({ 
            ([
                "type": "research",
                "research item": "guilds/aegis-guard/forms/bow/bregol-pilin.c",
                "name": "bregol-pilin",
                "formula": "multiplicative",
                "base value": 1,
                "rate": 1.15
            ]),
            ([
                "type": "research",
                "research item": "guilds/aegis-guard/forms/bow/alag-pilin.c",
                "name": "alag-pilin",
                "formula": "multiplicative",
                "base value": 1,
                "rate": 1.15
            ]),
            ([
                "type": "research",
                "research item": "guilds/aegis-guard/forms/bow/megor-pilin.c",
                "name": "megor-pilin",
                "formula": "multiplicative",
                "base value": 1,
                "rate": 1.15
            ]),
            ([
                "type": "research",
                "research item": "guilds/aegis-guard/forms/bow/lhegren-pilin.c",
                "name": "lhegren-pilin",
                "formula": "multiplicative",
                "base value": 1,
                "rate": 1.15
            ]),
            ([
                "type": "research",
                "research item": "guilds/aegis-guard/forms/bow/goeol-pilin.c",
                "name": "goeol-pilin",
                "formula": "multiplicative",
                "base value": 1,
                "rate": 1.15
            ]),
            ([
                "type": "research",
                "research item": "guilds/aegis-guard/forms/bow/dagnir-pilin.c",
                "name": "dagnir-pilin",
                "formula": "multiplicative",
                "base value": 1,
                "rate": 1.15
            ]),
            ([
                "type": "research",
                "research item": "guilds/aegis-guard/forms/bow/maethor-pilin.c",
                "name": "maethor-pilin",
                "formula": "multiplicative",
                "base value": 1,
                "rate": 1.25
            ]),
            ([
                "type": "weapon damage",
                "name" : "bow",
                "types" : ({ "bow" }),
                "formula" : "additive",
                "rate" : 1.75
            ]),
            ([
                "type": "skill",
                "name": "bow",
                "formula": "logarithmic",
                "rate": 1.25
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
        }));

        addSpecification("consumables", (["arrow": 1]));

        addSpecification("stamina point cost", 50);
        addSpecification("stamina point cost modifiers", ([
            "guilds/aegis-guard/forms/bow/bregol-gwaelphilin.c": 10,
            "guilds/aegis-guard/forms/bow/lhegren-gwaelphilin.c": 10,
            "guilds/aegis-guard/forms/bow/dagnir-gwaelphilin.c": 10,
            "guilds/aegis-guard/forms/bow/maethor-gwaelphilin.c": 10
        ]));

        addSpecification("cooldown", 60);
/*        addSpecification("cooldown modifiers", ([
            "guilds/aegis-guard/forms/bow/cu-ai-celair.c": 10,
            "guilds/aegis-guard/forms/bow/cu-ai-edlothia.c": 10,
            "guilds/aegis-guard/forms/bow/cu-ai-manadh.c": 10,
            "guilds/aegis-guard/forms/bow/cu-ai-dagnir.c": 10,
        ]));
*/
        addSpecification("event handler", "bregolAdlegEvent");
        addSpecification("command template", "bregol adleg [at ##Target##]");
        addSpecification("use ability message",  "##InitiatorPossessive::Name## "
            "##Infinitive::aim## ##InitiatorPossessive## "
            "##InitiatorWeapon## at ##TargetName##. The arrow "
            "hisses as it breaks through the air on its way toward ##TargetName##.");
    }
}
