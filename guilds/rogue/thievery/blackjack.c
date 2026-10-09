//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Blackjack");
    addSpecification("source", "rogue");
    addSpecification("description", "This research provides the rogue with "
        "the Blackjack thievery technique.");

    addPrerequisite("/guilds/rogue/thievery/sleight-of-hand.c",
        (["type": "research"]));

    addPrerequisite("level",
        (["type": "level",
            "guild": "rogue",
            "value": 17
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("stamina point cost", 52);
    addSpecification("cooldown", 14);
    addSpecification("command template", "blackjack [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::strike## ##TargetName## with a "
        "blackjack.");

    addSpecification("damage hit points", ({
        ([
            "probability": 80,
            "base damage": 42,
            "range": 28
        ]),
        ([
            "probability": 20,
            "base damage": 63,
            "range": 39
        ])
    }));

    addSpecification("damage type", "physical");

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/rogue/thievery/thieves-insight-ii.c",
            "name": "Thieves' Insight II",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/rogue/thievery/thieves-insight-iii.c",
            "name": "Thieves' Insight III",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/rogue/thievery/thieves-insight-iv.c",
            "name": "Thieves' Insight IV",
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
