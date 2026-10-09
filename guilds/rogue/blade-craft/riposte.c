//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Riposte");
    addSpecification("source", "rogue");
    addSpecification("description", "This research provides the rogue with "
        "the Riposte blade combat technique.");

    addPrerequisite("/guilds/rogue/blade-craft/honed-reflexes.c",
        (["type": "research"]));

    addPrerequisite("level",
        (["type": "level",
            "guild": "rogue",
            "value": 15
        ]));

    addSpecification("limited by", (["equipment":({ "dagger", "short sword" })]));
    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("stamina point cost", 50);
    addSpecification("cooldown", 14);
    addSpecification("command template", "riposte [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::deliver## a precise riposte "
        "at ##TargetName##.");

    addSpecification("damage hit points", ({
        ([
            "probability": 80,
            "base damage": 38,
            "range": 24
        ]),
        ([
            "probability": 20,
            "base damage": 57,
            "range": 33
        ])
    }));

    addSpecification("damage type", "slash");

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/rogue/blade-craft/blade-honing-iii.c",
            "name": "Blade Honing III",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/rogue/blade-craft/surgical-precision.c",
            "name": "Surgical Precision",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "weapon damage",
            "name": "blade weapons",
            "types": ({ "dagger", "short sword" }),
            "formula": "additive",
            "rate": 0.75
        ]),
        ([
            "type": "highest skill",
            "name": "blade skills",
            "skills": ({ "dagger", "short sword" }),
            "formula": "additive",
            "rate": 0.5
        ]),
        ([
            "type": "skill",
            "name": "anatomy and physiology",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "skill",
            "name": "combat tactics",
            "formula": "additive",
            "rate": 0.08
        ]),
        ([
            "type": "skill",
            "name": "perception",
            "formula": "additive",
            "rate": 0.05
        ]),
        ([
            "type": "skill",
            "name": "tactics",
            "formula": "additive",
            "rate": 0.05
        ]),
        ([
            "type": "attribute",
            "name": "dexterity",
            "formula": "additive",
            "rate": 0.25
        ]),
        ([
            "type": "attribute",
            "name": "strength",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "level",
            "name": "rogue",
            "formula": "logarithmic",
            "rate": 1.05
        ])
    }));
}
