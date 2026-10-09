//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Toxic Strike");
    addSpecification("source", "rogue");
    addSpecification("description", "This research provides the rogue with "
        "the Toxic Strike poison technique.");

    addPrerequisite("/guilds/rogue/poison-lore/concentrated-toxins.c",
        (["type": "research"]));

    addPrerequisite("level",
        (["type": "level",
            "guild": "rogue",
            "value": 9
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("stamina point cost", 28);
    addSpecification("cooldown", 10);
    addSpecification("command template", "toxic strike [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::administer## toxic strike "
        "to ##TargetName##.");

    addSpecification("damage hit points", ({
        ([
            "probability": 80,
            "base damage": 20,
            "range": 13
        ]),
        ([
            "probability": 20,
            "base damage": 30,
            "range": 18
        ])
    }));

    addSpecification("damage type", "poison");

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/rogue/poison-lore/venomous-insight.c",
            "name": "Venomous Insight",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/rogue/poison-lore/venomous-insight-ii.c",
            "name": "Venomous Insight II",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "skill",
            "name": "herbalism",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "skill",
            "name": "chemistry",
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
            "name": "zoology",
            "formula": "additive",
            "rate": 0.05
        ]),
        ([
            "type": "skill",
            "name": "perception",
            "formula": "additive",
            "rate": 0.05
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.20
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "attribute",
            "name": "dexterity",
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
