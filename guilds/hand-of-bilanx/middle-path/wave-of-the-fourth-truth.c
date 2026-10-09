//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Wave of the Fourth Truth");
    addSpecification("source", "Hand of Bilanx");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the wave of the fourth truth. The capstone of the "
        "middle path, it releases a devastating wave of pure balanced "
        "force that engulfs all enemies, each struck with the full "
        "weight of the priest's mastery of the center.");

    addPrerequisite("level",
        (["type": "level",
          "guild": "Hand of Bilanx",
          "value": 65 ]));

    addPrerequisite("/guilds/hand-of-bilanx/middle-path/edict-of-the-center.c",
        (["type": "research"]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 115);

    addSpecification("damage hit points", ({ ([
            "probability": 60,
            "base damage": 72,
            "range": 40
        ]),
        ([
            "probability": 40,
            "base damage": 110,
            "range": 52
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
            "rate": 1.38
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
            "rate": 1.35
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.25
        ]),
        ([
            "type": "level",
            "name": "Hand of Bilanx",
            "formula": "logarithmic",
            "rate": 1.14
        ])
    }));

    addSpecification("cooldown", 45);
    addSpecification("event handler", "waveOfFourthTruthEvent");
    addSpecification("command template", "wave of the fourth truth");
    addSpecification("use ability message", "##InitiatorName## releases "
        "the wave of the fourth truth - the full force of the middle "
        "path sweeping across the entire area.");
}
