//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Gut Punch");
    addSpecification("source", "rogue");
    addSpecification("description", "This research provides the rogue with "
        "the Gut Punch dirty fighting technique.");

    addPrerequisite("/guilds/rogue/dirty-fighting/brawlers-instinct.c",
        (["type": "research"]));

    addPrerequisite("level",
        (["type": "level",
            "guild": "rogue",
            "value": 19
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("stamina point cost", 62);
    addSpecification("cooldown", 16);
    addSpecification("command template", "gut punch [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::deliver## a brutal gut punch "
        "to ##TargetName##.");

    addSpecification("damage hit points", ({
        ([
            "probability": 80,
            "base damage": 50,
            "range": 33
        ]),
        ([
            "probability": 20,
            "base damage": 75,
            "range": 46
        ])
    }));

    addSpecification("damage type", "unarmed");

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/rogue/dirty-fighting/dirty-insight-iii.c",
            "name": "Dirty Insight III",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/rogue/dirty-fighting/dirty-insight-iv.c",
            "name": "Dirty Insight IV",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/rogue/dirty-fighting/dirty-insight-v.c",
            "name": "Dirty Insight V",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "skill",
            "name": "unarmed",
            "formula": "logarithmic",
            "rate": 1.05
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
            "name": "physics",
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
            "name": "strength",
            "formula": "additive",
            "rate": 0.25
        ]),
        ([
            "type": "attribute",
            "name": "dexterity",
            "formula": "additive",
            "rate": 0.20
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
