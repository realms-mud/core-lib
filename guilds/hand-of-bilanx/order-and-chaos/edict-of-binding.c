//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Edict of Binding");
    addSpecification("source", "Hand of Bilanx");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the edict of binding. A harsher expression of "
        "structured order, it locks an enemy into a rigid framework "
        "that impairs their ability to act freely.");

    addPrerequisite("level",
        (["type": "level",
          "guild": "Hand of Bilanx",
          "value": 13 ]));

    addPrerequisite("/guilds/hand-of-bilanx/order-and-chaos/iron-edict.c",
        (["type": "research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 30);

    addSpecification("damage hit points", ({ ([
            "probability": 100,
            "base damage": 15,
            "range": 10
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
            "rate": 0.08
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
            "base value": 1,
            "rate": 1.05
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

    addSpecification("cooldown", 10);
    addSpecification("event handler", "edictOfBindingEvent");
    addSpecification("command template", "edict of binding [##Target##]");
    addSpecification("use ability message", "##InitiatorName## pronounces "
        "the edict of binding over ##TargetName##. Rigid lines of law "
        "settle around ##TargetSubjective## like chains.");
}
