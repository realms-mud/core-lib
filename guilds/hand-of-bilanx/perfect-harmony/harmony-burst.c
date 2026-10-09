//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Harmony Burst");
    addSpecification("source", "Hand of Bilanx");
    addSpecification("description", "This research provides the user with the knowledge of the harmony burst. A burst of the eighth truth strikes all nearby enemies at once.");

    addPrerequisite("level",
        (["type": "level",
          "guild": "Hand of Bilanx",
          "value": 1 ]));

    addPrerequisite("guild rank",
        (["type": "guild rank",
          "guild": "Hand of Bilanx",
          "value": "hand of bilanx" ]));

    addPrerequisite("/guilds/hand-of-bilanx/perfect-harmony/harmony-attunement.c",
        (["type": "research"]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 42);
    addSpecification("cooldown", 18);

    addSpecification("damage hit points", ({ ([
            "probability": 65,
            "base damage": 16,
            "range": 10
        ]),
        ([
            "probability": 35,
            "base damage": 28,
            "range": 14
        ])
    }));
    addSpecification("damage type", "energy");

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
            "rate": 0.14
        ]),
        ([
            "type": "skill",
            "name": "insight",
            "formula": "additive",
            "rate": 0.12
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

    addSpecification("event handler", "harmonyBurstEvent");
    addSpecification("command template", "harmony burst");
    addSpecification("use ability message", "##InitiatorName## releases a burst of the eighth truth.");
}