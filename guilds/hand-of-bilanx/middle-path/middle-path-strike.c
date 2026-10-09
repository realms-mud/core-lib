//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Middle Path Strike");
    addSpecification("source", "Hand of Bilanx");
    addSpecification("description", "This research provides the user with the knowledge of the middle path strike. The priest channels the fourth truth's centering power into a balanced attack.");

    addPrerequisite("level",
        (["type": "level",
          "guild": "Hand of Bilanx",
          "value": 8 ]));

    addPrerequisite("/guilds/hand-of-bilanx/middle-path/poise-of-the-scales.c",
        (["type": "research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 28);
    addSpecification("cooldown", 10);

    addSpecification("damage hit points", ({ ([
            "probability": 70,
            "base damage": 20,
            "range": 12
        ]),
        ([
            "probability": 30,
            "base damage": 32,
            "range": 16
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

    addSpecification("event handler", "middlePathStrikeEvent");
    addSpecification("command template", "middle path strike [##Target##]");
    addSpecification("use ability message", "##InitiatorName## delivers a middle path strike at ##TargetName##.");
}