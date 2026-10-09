//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Final Harmony");
    addSpecification("source", "Hand of Bilanx");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the final harmony. The capstone ability of the "
        "perfect-harmony path, it expresses Bilanx's eighth truth in its "
        "most complete form - a wave of living balance that affects the "
        "entire area.");

    addPrerequisite("level",
        (["type": "level",
          "guild": "Hand of Bilanx",
          "value": 1 ]));

    addPrerequisite("guild rank",
        (["type": "guild rank",
          "guild": "Hand of Bilanx",
          "value": "hand of bilanx" ]));

    addPrerequisite("/guilds/hand-of-bilanx/perfect-harmony/unity-of-truths.c",
        (["type": "research"]));

    addPrerequisite("/guilds/hand-of-bilanx/perfect-harmony/absolute-harmony.c",
        (["type": "research"]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 85);
    addSpecification("cooldown", 45);

    addSpecification("damage hit points", ({ ([
            "probability": 60,
            "base damage": 50,
            "range": 26
        ]),
        ([
            "probability": 40,
            "base damage": 74,
            "range": 30
        ])
    }));
    addSpecification("damage type", "energy");
    addSpecification("siphon hit points", ({ ([
            "probability": 100,
            "base damage": 16,
            "range": 10
        ])
    }));

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/hand-of-bilanx/perfect-harmony/harmony-theory.c",
            "name": "Harmony Theory",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.14
        ]),
        ([
            "type": "research",
            "research item": "/guilds/hand-of-bilanx/perfect-harmony/harmonic-resonance.c",
            "name": "Harmonic Resonance",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.12
        ]),
        ([
            "type": "research",
            "research item": "/guilds/hand-of-bilanx/perfect-harmony/all-truths-mastery.c",
            "name": "All Truths Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.12
        ]),
        ([
            "type": "research",
            "research item": "/guilds/hand-of-bilanx/perfect-harmony/all-truths-perfected.c",
            "name": "All Truths Perfected",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.10
        ]),
        ([
            "type": "research",
            "research item": "/guilds/hand-of-bilanx/perfect-harmony/unity-of-truths.c",
            "name": "Unity of Truths",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.10
        ]),
        ([
            "type": "skill",
            "name": "evocation",
            "formula": "additive",
            "rate": 0.16
        ]),
        ([
            "type": "skill",
            "name": "insight",
            "formula": "additive",
            "rate": 0.14
        ]),
        ([
            "type": "skill",
            "name": "magical essence",
            "formula": "logarithmic",
            "rate": 1.18
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.16
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
            "rate": 1.10
        ])
    }));

    addSpecification("event handler", "finalHarmonyEvent");
    addSpecification("command template", "final harmony");
    addSpecification("use ability message", "##InitiatorName## releases "
        "the final harmony - the living expression of Bilanx's eighth "
        "truth washing across the entire area.");
}