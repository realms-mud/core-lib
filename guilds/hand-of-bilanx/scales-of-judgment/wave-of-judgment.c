//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Wave of Judgment");
    addSpecification("source", "Hand of Bilanx");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the wave of judgment. The priest releases a tide "
        "of the scales' displeasure across the entire area, striking "
        "all enemies with its weight.");

    addPrerequisite("level",
        (["type": "level",
          "guild": "Hand of Bilanx",
          "value": 18 ]));

    addPrerequisite("/guilds/hand-of-bilanx/scales-of-judgment/scales-reckoning.c",
        (["type": "research"]));

    addPrerequisite("/guilds/hand-of-bilanx/scales-of-judgment/fifth-truth-mastery.c",
        (["type": "research"]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 36);

    addSpecification("damage hit points", ({ ([
            "probability": 75,
            "base damage": 22,
            "range": 14
        ]),
        ([
            "probability": 25,
            "base damage": 36,
            "range": 18
        ])
    }));
    addSpecification("damage type", "neutral");

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/hand-of-bilanx/scales-of-judgment/judgment-theory.c",
            "name": "Judgment Theory",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.14
        ]),
        ([
            "type": "research",
            "research item": "/guilds/hand-of-bilanx/scales-of-judgment/true-sight.c",
            "name": "True Sight",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.12
        ]),
        ([
            "type": "research",
            "research item": "/guilds/hand-of-bilanx/scales-of-judgment/fifth-truth-mastery.c",
            "name": "Fifth Truth Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.12
        ]),
        ([
            "type": "research",
            "research item": "/guilds/hand-of-bilanx/scales-of-judgment/fifth-truth-perfected.c",
            "name": "Fifth Truth Perfected",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.10
        ]),
        ([
            "type": "research",
            "research item": "/guilds/hand-of-bilanx/scales-of-judgment/fifth-truth-ascendant.c",
            "name": "Fifth Truth Ascendant",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.10
        ]),
        ([
            "type": "skill",
            "name": "perception",
            "formula": "additive",
            "rate": 0.14
        ]),
        ([
            "type": "skill",
            "name": "magical essence",
            "formula": "logarithmic",
            "rate": 1.24
        ]),
        ([
            "type": "skill",
            "name": "evocation",
            "formula": "additive",
            "rate": 0.14
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.20
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.14
        ]),
        ([
            "type": "level",
            "name": "Hand of Bilanx",
            "formula": "logarithmic",
            "rate": 1.06
        ])
    }));

    addSpecification("cooldown", 18);
    addSpecification("event handler", "waveOfJudgmentEvent");
    addSpecification("command template", "wave of judgment");
    addSpecification("use ability message", "##InitiatorName## releases "
        "a wave of judgment from the scales across the entire area.");
}
