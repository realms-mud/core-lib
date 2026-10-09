//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Wave of the Sixth Truth");
    addSpecification("source", "Hand of Bilanx");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the wave of the sixth truth. The capstone of the "
        "equilibrium form path - the priest channels the full remade "
        "self into a devastating wave that engulfs all enemies with the "
        "absolute unity of body and spirit.");

    addPrerequisite("level",
        (["type": "level",
          "guild": "Hand of Bilanx",
          "value": 65 ]));

    addPrerequisite("/guilds/hand-of-bilanx/equilibrium-form/unified-nova.c",
        (["type": "research"]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 120);

    addSpecification("damage hit points", ({ ([
            "probability": 60,
            "base damage": 82,
            "range": 46
        ]),
        ([
            "probability": 40,
            "base damage": 124,
            "range": 56
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
            "rate": 1.40
        ]),
        ([
            "type": "skill",
            "name": "evocation",
            "formula": "additive",
            "rate": 0.28
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.36
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.25
        ]),
        ([
            "type": "attribute",
            "name": "constitution",
            "formula": "additive",
            "rate": 0.20
        ]),
        ([
            "type": "level",
            "name": "Hand of Bilanx",
            "formula": "logarithmic",
            "rate": 1.14
        ])
    }));

    addSpecification("cooldown", 45);
    addSpecification("event handler", "waveOfSixthTruthEvent");
    addSpecification("command template", "wave of the sixth truth");
    addSpecification("use ability message", "##InitiatorName## releases "
        "the wave of the sixth truth - the fully remade self unleashed "
        "across the entire area.");
}
