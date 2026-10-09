//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Absolute Judgment");
    addSpecification("source", "Hand of Bilanx");
    addSpecification("description", "This research provides the user with the "
        "knowledge of absolute judgment. The priest channels the full "
        "weight of the middle path into a single devastating strike of "
        "neutral force against one target.");

    addPrerequisite("level",
        (["type": "level",
          "guild": "Hand of Bilanx",
          "value": 40 ]));

    addPrerequisite("/guilds/hand-of-bilanx/middle-path/fourth-truth-perfected.c",
        (["type": "research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 60);

    addSpecification("damage hit points", ({ ([
            "probability": 60,
            "base damage": 55,
            "range": 30
        ]),
        ([
            "probability": 40,
            "base damage": 82,
            "range": 36
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
            "rate": 1.32
        ]),
        ([
            "type": "skill",
            "name": "evocation",
            "formula": "additive",
            "rate": 0.22
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.28
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.18
        ]),
        ([
            "type": "level",
            "name": "Hand of Bilanx",
            "formula": "logarithmic",
            "rate": 1.10
        ])
    }));

    addSpecification("cooldown", 25);
    addSpecification("event handler", "absoluteJudgmentEvent");
    addSpecification("command template", "absolute judgment [##Target##]");
    addSpecification("use ability message", "##InitiatorName## channels "
        "absolute judgment - the full weight of the middle path "
        "crashing down upon ##TargetName##.");
}
