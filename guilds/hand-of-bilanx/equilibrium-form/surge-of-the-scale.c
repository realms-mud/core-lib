//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Surge of the Scale");
    addSpecification("source", "Hand of Bilanx");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the surge of the scale. The priest releases a "
        "surging burst of perfectly integrated force across the area, "
        "the full power of body and spirit unleashed at once.");

    addPrerequisite("level",
        (["type": "level",
          "guild": "Hand of Bilanx",
          "value": 33 ]));

    addPrerequisite("/guilds/hand-of-bilanx/equilibrium-form/sixth-truth-perfected.c",
        (["type": "research"]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 56);

    addSpecification("damage hit points", ({ ([
            "probability": 70,
            "base damage": 38,
            "range": 22
        ]),
        ([
            "probability": 30,
            "base damage": 60,
            "range": 28
        ])
    }));
    addSpecification("damage type", "neutral");

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/hand-of-bilanx/equilibrium-form/sixth-truth-mastery.c",
            "name": "Sixth Truth Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.14
        ]),
        ([
            "type": "research",
            "research item": "/guilds/hand-of-bilanx/equilibrium-form/harmonious-body.c",
            "name": "Harmonious Body",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.12
        ]),
        ([
            "type": "research",
            "research item": "/guilds/hand-of-bilanx/equilibrium-form/sixth-truth-revelation.c",
            "name": "Sixth Truth Revelation",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.12
        ]),
        ([
            "type": "research",
            "research item": "/guilds/hand-of-bilanx/equilibrium-form/sixth-truth-perfected.c",
            "name": "Sixth Truth Perfected",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.10
        ]),
        ([
            "type": "research",
            "research item": "/guilds/hand-of-bilanx/equilibrium-form/avatar-of-the-scale.c",
            "name": "Avatar of the Scale",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.10
        ]),
        ([
            "type": "skill",
            "name": "magical essence",
            "formula": "logarithmic",
            "rate": 1.30
        ]),
        ([
            "type": "skill",
            "name": "evocation",
            "formula": "additive",
            "rate": 0.20
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.26
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.18
        ]),
        ([
            "type": "attribute",
            "name": "constitution",
            "formula": "additive",
            "rate": 0.14
        ]),
        ([
            "type": "level",
            "name": "Hand of Bilanx",
            "formula": "logarithmic",
            "rate": 1.09
        ])
    }));

    addSpecification("cooldown", 22);
    addSpecification("event handler", "surgeOfTheScaleEvent");
    addSpecification("command template", "surge of the scale");
    addSpecification("use ability message", "##InitiatorName## releases "
        "a surge of the scale - integrated body and spirit exploding "
        "across the area.");
}
