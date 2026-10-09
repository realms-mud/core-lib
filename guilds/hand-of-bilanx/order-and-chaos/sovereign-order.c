//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Sovereign Order");
    addSpecification("source", "Hand of Bilanx");
    addSpecification("description", "This research provides the user with the "
        "knowledge of sovereign order. The priest sustains a state of "
        "supreme structured order around all allies, granting a powerful "
        "ongoing combat bonus.");

    addPrerequisite("level",
        (["type": "level",
          "guild": "Hand of Bilanx",
          "value": 45 ]));

    addPrerequisite("/guilds/hand-of-bilanx/order-and-chaos/second-truth-perfected.c",
        (["type": "research"]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 40);

    addSpecification("bonus attack", 4);
    addSpecification("bonus defense", 4);
    addSpecification("bonus armor class", 3);
    addSpecification("bonus soak", 3);
    addSpecification("apply fortified", 3);

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/hand-of-bilanx/order-and-chaos/second-truth-perfected.c",
            "name": "Second Truth Perfected",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.10
        ]),
        ([
            "type": "skill",
            "name": "philosophy",
            "formula": "additive",
            "rate": 0.08
        ]),
        ([
            "type": "skill",
            "name": "insight",
            "formula": "additive",
            "rate": 0.08
        ]),
        ([
            "type": "skill",
            "name": "magical essence",
            "formula": "logarithmic",
            "base value": 1,
            "rate": 1.07
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "base value": 1,
            "rate": 1.05
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.05
        ]),
        ([
            "type": "level",
            "name": "Hand of Bilanx",
            "formula": "logarithmic",
            "base value": 1,
            "rate": 1.05
        ])
    }));

    addSpecification("cooldown", 45);
    addSpecification("event handler", "sovereignOrderEvent");
    addSpecification("command template", "sovereign order");
    addSpecification("use ability activate message", "##InitiatorName## "
        "raises both hands and sovereign order descends over all allies. "
        "Structure pervades everything.");
    addSpecification("use ability deactivate message", "##InitiatorName## "
        "##Infinitive::release## sovereign order.");
}
