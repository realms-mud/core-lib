//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Second Truth Wave");
    addSpecification("source", "Hand of Bilanx");
    addSpecification("description", "This research provides the user with the knowledge of the second truth wave. A devastating area working that channels both order and entropy in equal measure.");

    addPrerequisite("level",
        (["type": "level",
          "guild": "Hand of Bilanx",
          "value": 44 ]));

    addPrerequisite("/guilds/hand-of-bilanx/order-and-chaos/second-truth-perfected.c",
        (["type": "research"]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 56);
    addSpecification("cooldown", 22);

    addSpecification("damage hit points", ({ ([
            "probability": 70,
            "base damage": 24,
            "range": 14
        ]),
        ([
            "probability": 30,
            "base damage": 38,
            "range": 18
        ])
    }));
    addSpecification("damage type", "neutral");

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
            "rate": 0.13
        ]),
        ([
            "type": "skill",
            "name": "theology",
            "formula": "additive",
            "rate": 0.11
        ]),
        ([
            "type": "skill",
            "name": "magical essence",
            "formula": "logarithmic",
            "rate": 1.16
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.14
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.12
        ]),
        ([
            "type": "level",
            "name": "Hand of Bilanx",
            "formula": "logarithmic",
            "rate": 1.08
        ])
    }));

    addSpecification("event handler", "secondTruthWaveEvent");
    addSpecification("command template", "second truth wave");
    addSpecification("use ability message", "##InitiatorName## releases a wave of the second truth across the area.");
}