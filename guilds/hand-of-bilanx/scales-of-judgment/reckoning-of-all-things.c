//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Reckoning of All Things");
    addSpecification("source", "Hand of Bilanx");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the reckoning of all things. The priest delivers "
        "a sweeping area judgment, the full weight of the scales "
        "crashing down on all enemies with extraordinary force.");

    addPrerequisite("level",
        (["type": "level",
          "guild": "Hand of Bilanx",
          "value": 45 ]));

    addPrerequisite("/guilds/hand-of-bilanx/scales-of-judgment/verdict-of-the-scales.c",
        (["type": "research"]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 80);

    addSpecification("damage hit points", ({ ([
            "probability": 65,
            "base damage": 50,
            "range": 28
        ]),
        ([
            "probability": 35,
            "base damage": 78,
            "range": 36
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
            "rate": 0.24
        ]),
        ([
            "type": "skill",
            "name": "magical essence",
            "formula": "logarithmic",
            "rate": 1.34
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
            "rate": 1.30
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.22
        ]),
        ([
            "type": "level",
            "name": "Hand of Bilanx",
            "formula": "logarithmic",
            "rate": 1.11
        ])
    }));

    addSpecification("cooldown", 30);
    addSpecification("event handler", "reckoningOfAllThingsEvent");
    addSpecification("command template", "reckoning of all things");
    addSpecification("use ability message", "##InitiatorName## calls "
        "the reckoning of all things - the weight of the scales "
        "descending upon the entire area.");
}
