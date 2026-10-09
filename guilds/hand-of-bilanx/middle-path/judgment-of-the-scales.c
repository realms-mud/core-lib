//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Judgment of the Scales");
    addSpecification("source", "Hand of Bilanx");
    addSpecification("description", "This research provides the user with the "
        "knowledge of judgment of the scales. A focused beam of pure "
        "neutral force is leveled at a single target - the priest's will "
        "as the living scales of balance.");

    addPrerequisite("level",
        (["type": "level",
          "guild": "Hand of Bilanx",
          "value": 24 ]));

    addPrerequisite("/guilds/hand-of-bilanx/middle-path/fourth-truth-revelation.c",
        (["type": "research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 38);

    addSpecification("damage hit points", ({ ([
            "probability": 70,
            "base damage": 36,
            "range": 20
        ]),
        ([
            "probability": 30,
            "base damage": 56,
            "range": 24
        ])
    }));
    addSpecification("damage type", "neutral");

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/hand-of-bilanx/middle-path/middle-path-theory.c",
            "name": "Middle Path Theory",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.14
        ]),
        ([
            "type": "research",
            "research item": "/guilds/hand-of-bilanx/middle-path/fourth-truth-mastery.c",
            "name": "Fourth Truth Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.12
        ]),
        ([
            "type": "research",
            "research item": "/guilds/hand-of-bilanx/middle-path/resilience-of-the-center.c",
            "name": "Resilience of the Center",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.12
        ]),
        ([
            "type": "research",
            "research item": "/guilds/hand-of-bilanx/middle-path/fourth-truth-perfected.c",
            "name": "Fourth Truth Perfected",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.10
        ]),
        ([
            "type": "research",
            "research item": "/guilds/hand-of-bilanx/middle-path/fourth-truth-ascendant.c",
            "name": "Fourth Truth Ascendant",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.10
        ]),
        ([
            "type": "skill",
            "name": "magical essence",
            "formula": "logarithmic",
            "rate": 1.28
        ]),
        ([
            "type": "skill",
            "name": "evocation",
            "formula": "additive",
            "rate": 0.18
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.22
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "level",
            "name": "Hand of Bilanx",
            "formula": "logarithmic",
            "rate": 1.07
        ])
    }));

    addSpecification("cooldown", 18);
    addSpecification("event handler", "judgmentOfTheScalesEvent");
    addSpecification("command template", "judgment of the scales [##Target##]");
    addSpecification("use ability message", "##InitiatorName## levels "
        "the judgment of the scales upon ##TargetName##.");
}
