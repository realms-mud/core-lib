//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Unified Nova");
    addSpecification("source", "Hand of Bilanx");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the unified nova. The priest releases the full "
        "integrated force of body and spirit as a catastrophic area blast, "
        "both natures acting as one.");

    addPrerequisite("level",
        (["type": "level",
          "guild": "Hand of Bilanx",
          "value": 55 ]));

    addPrerequisite("/guilds/hand-of-bilanx/equilibrium-form/sixth-truth-ascendant.c",
        (["type": "research"]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 88);

    addSpecification("damage hit points", ({ ([
            "probability": 60,
            "base damage": 66,
            "range": 38
        ]),
        ([
            "probability": 40,
            "base damage": 100,
            "range": 46
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
            "rate": 1.36
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
            "rate": 1.32
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.22
        ]),
        ([
            "type": "attribute",
            "name": "constitution",
            "formula": "additive",
            "rate": 0.18
        ]),
        ([
            "type": "level",
            "name": "Hand of Bilanx",
            "formula": "logarithmic",
            "rate": 1.12
        ])
    }));

    addSpecification("cooldown", 35);
    addSpecification("event handler", "unifiedNovaEvent");
    addSpecification("command template", "unified nova");
    addSpecification("use ability message", "##InitiatorName## releases "
        "a unified nova - the full force of body and spirit erupting "
        "across the area as one.");
}
