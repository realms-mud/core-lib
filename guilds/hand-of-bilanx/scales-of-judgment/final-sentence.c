//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Final Sentence");
    addSpecification("source", "Hand of Bilanx");
    addSpecification("description", "This research provides the user with "
        "the knowledge of the final sentence. The capstone of the scales "
        "of judgment path, it delivers Bilanx's irreversible judgment "
        "upon a single target with the full force of the fifth truth.");

    addPrerequisite("level",
        (["type": "level",
          "guild": "Hand of Bilanx",
          "value": 55 ]));

    addPrerequisite("/guilds/hand-of-bilanx/scales-of-judgment/fifth-truth-ascendant.c",
        (["type": "research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 100);

    addSpecification("damage hit points", ({ ([
            "probability": 55,
            "base damage": 88,
            "range": 48
        ]),
        ([
            "probability": 45,
            "base damage": 130,
            "range": 58
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
            "rate": 0.26
        ]),
        ([
            "type": "skill",
            "name": "magical essence",
            "formula": "logarithmic",
            "rate": 1.38
        ]),
        ([
            "type": "skill",
            "name": "evocation",
            "formula": "additive",
            "rate": 0.24
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.34
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.24
        ]),
        ([
            "type": "level",
            "name": "Hand of Bilanx",
            "formula": "logarithmic",
            "rate": 1.13
        ])
    }));

    addSpecification("cooldown", 35);
    addSpecification("event handler", "finalSentenceEvent");
    addSpecification("command template", "final sentence [##Target##]");
    addSpecification("use ability message", "##InitiatorName## speaks "
        "the final sentence of the scales - Bilanx's irreversible "
        "judgment descending upon ##TargetName##.");
}
