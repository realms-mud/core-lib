//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Low Blow");
    addSpecification("source", "rogue");
    addSpecification("description", "This research provides the rogue with "
        "the Low Blow thievery technique.");

    addPrerequisite("/guilds/rogue/thievery/master-thief.c",
        (["type": "research"]));

    addPrerequisite("level",
        (["type": "level",
            "guild": "rogue",
            "value": 25
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("stamina point cost", 82);
    addSpecification("cooldown", 18);
    addSpecification("command template", "low blow [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::strike## ##TargetName## with a "
        "low blow.");

    addSpecification("damage hit points", ({
        ([
            "probability": 80,
            "base damage": 70,
            "range": 45
        ]),
        ([
            "probability": 20,
            "base damage": 105,
            "range": 62
        ])
    }));

    addSpecification("damage type", "physical");

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/rogue/thievery/thieves-insight-iv.c",
            "name": "Thieves' Insight IV",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/rogue/thievery/thieves-insight-v.c",
            "name": "Thieves' Insight V",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/rogue/thievery/thieves-insight-vi.c",
            "name": "Thieves' Insight VI",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "skill",
            "name": "search",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "skill",
            "name": "bluff",
            "formula": "additive",
            "rate": 0.08
        ]),
        ([
            "type": "skill",
            "name": "hide",
            "formula": "additive",
            "rate": 0.08
        ]),
        ([
            "type": "skill",
            "name": "anatomy and physiology",
            "formula": "additive",
            "rate": 0.08
        ]),
        ([
            "type": "skill",
            "name": "combat tactics",
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
