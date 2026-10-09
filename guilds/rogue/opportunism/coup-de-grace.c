//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Coup de Grace");
    addSpecification("source", "rogue");
    addSpecification("description", "This research provides the rogue with "
        "the Coup de Grace opportunistic technique.");

    addPrerequisite("/guilds/rogue/opportunism/seize-the-moment.c",
        (["type": "research"]));

    addPrerequisite("level",
        (["type": "level",
            "guild": "rogue",
            "value": 21
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("stamina point cost", 70);
    addSpecification("cooldown", 16);
    addSpecification("command template", "coup de grace [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::exploit## an opening and "
        "##Infinitive::strike## ##TargetName## with a "
        "coup de grace.");

    addSpecification("damage hit points", ({
        ([
            "probability": 80,
            "base damage": 58,
            "range": 38
        ]),
        ([
            "probability": 20,
            "base damage": 87,
            "range": 53
        ])
    }));

    addSpecification("damage type", "physical");

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/rogue/opportunism/opportunistic-insight-iii.c",
            "name": "Opportunistic Insight III",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/rogue/opportunism/opportunistic-insight-iv.c",
            "name": "Opportunistic Insight IV",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/rogue/opportunism/opportunistic-insight-v.c",
            "name": "Opportunistic Insight V",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "skill",
            "name": "perception",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "skill",
            "name": "combat tactics",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "skill",
            "name": "tactics",
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
            "name": "insight",
            "formula": "additive",
            "rate": 0.05
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
            "rate": 0.20
        ]),
        ([
            "type": "attribute",
            "name": "strength",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "level",
            "name": "rogue",
            "formula": "logarithmic",
            "rate": 1.05
        ])
    }));
}
