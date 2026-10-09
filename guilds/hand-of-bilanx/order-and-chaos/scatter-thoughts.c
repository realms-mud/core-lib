//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Scatter Thoughts");
    addSpecification("source", "Hand of Bilanx");
    addSpecification("description", "This research provides the user with the "
        "knowledge of scatter thoughts. A flick of entropic energy breaks "
        "the target's focus, causing their next several actions to be "
        "disrupted by the chaos seeded in their mind.");

    addPrerequisite("level",
        (["type": "level",
          "guild": "Hand of Bilanx",
          "value": 3 ]));

    addPrerequisite("/guilds/hand-of-bilanx/order-and-chaos/touch-of-chaos.c",
        (["type": "research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 14);

    addSpecification("damage hit points", ({ ([
            "probability": 100,
            "base damage": 8,
            "range": 6
        ])
    }));
    addSpecification("damage type", "chaos");

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/hand-of-bilanx/order-and-chaos/second-truth-mastery.c",
            "name": "Second Truth Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.14
        ]),
        ([
            "type": "research",
            "research item": "/guilds/hand-of-bilanx/order-and-chaos/law-and-entropy.c",
            "name": "Law and Entropy",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.12
        ]),
        ([
            "type": "research",
            "research item": "/guilds/hand-of-bilanx/order-and-chaos/balanced-dominion.c",
            "name": "Balanced Dominion",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.12
        ]),
        ([
            "type": "research",
            "research item": "/guilds/hand-of-bilanx/order-and-chaos/second-truth-perfected.c",
            "name": "Second Truth Perfected",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.10
        ]),
        ([
            "type": "research",
            "research item": "/guilds/hand-of-bilanx/order-and-chaos/the-balance-point.c",
            "name": "The Balance Point",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.10
        ]),
        ([
            "type": "skill",
            "name": "insight",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "skill",
            "name": "philosophy",
            "formula": "additive",
            "rate": 0.08
        ]),
        ([
            "type": "skill",
            "name": "magical essence",
            "formula": "logarithmic",
            "rate": 1.15
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.15
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.08
        ]),
        ([
            "type": "level",
            "name": "Hand of Bilanx",
            "formula": "logarithmic",
            "rate": 1.03
        ])
    }));

    addSpecification("cooldown", 6);
    addSpecification("event handler", "scatterThoughtsEvent");
    addSpecification("command template", "scatter thoughts [##Target##]");
    addSpecification("use ability message", "##InitiatorName## flicks a "
        "seed of entropy into ##TargetName##'s mind. For a moment "
        "##TargetSubjective## ##Infinitive::look## utterly lost.");
}
