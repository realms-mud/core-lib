//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Sucker Punch");
    addSpecification("source", "rogue");
    addSpecification("description", "This research provides the rogue with "
        "the Sucker Punch subterfuge technique.");

    addPrerequisite("/guilds/rogue/subterfuge/improved-feint.c",
        (["type": "research"]));

    addPrerequisite("level",
        (["type": "level",
            "guild": "rogue",
            "value": 13
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("stamina point cost", 40);
    addSpecification("cooldown", 12);
    addSpecification("command template", "sucker punch [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::employ## sucker punch "
        "against ##TargetName##.");

    addSpecification("damage hit points", ({
        ([
            "probability": 80,
            "base damage": 28,
            "range": 18
        ]),
        ([
            "probability": 20,
            "base damage": 42,
            "range": 25
        ])
    }));

    addSpecification("damage type", "physical");

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/rogue/subterfuge/deceptive-insight.c",
            "name": "Deceptive Insight",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/rogue/subterfuge/deceptive-insight-ii.c",
            "name": "Deceptive Insight II",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/rogue/subterfuge/deceptive-insight-iii.c",
            "name": "Deceptive Insight III",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "skill",
            "name": "hide",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "skill",
            "name": "bluff",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "skill",
            "name": "move silently",
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
            "name": "charisma",
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
