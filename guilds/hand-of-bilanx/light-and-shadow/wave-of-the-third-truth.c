//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Wave of the Third Truth");
    addSpecification("source", "Hand of Bilanx");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the wave of the third truth. The capstone ability "
        "of the light-and-shadow path, it releases a devastating tidal "
        "wave of perfectly balanced radiance and shadow that engulfs all "
        "enemies.");

    addPrerequisite("level",
        (["type": "level",
          "guild": "Hand of Bilanx",
          "value": 65 ]));

    addPrerequisite("/guilds/hand-of-bilanx/light-and-shadow/dawn-and-dusk.c",
        (["type": "research"]));

    addPrerequisite("/guilds/hand-of-bilanx/light-and-shadow/aura-of-penumbra.c",
        (["type": "research"]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 80);

    addSpecification("damage hit points", ({ ([
            "probability": 60,
            "base damage": 48,
            "range": 26
        ]),
        ([
            "probability": 40,
            "base damage": 72,
            "range": 32
        ])
    }));
    addSpecification("damage type", "energy");
    addSpecification("siphon hit points", ({ ([
            "probability": 100,
            "base damage": 14,
            "range": 8
        ])
    }));

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/hand-of-bilanx/light-and-shadow/light-shadow-theory.c",
            "name": "Light Shadow Theory",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.14
        ]),
        ([
            "type": "research",
            "research item": "/guilds/hand-of-bilanx/light-and-shadow/twilight-mastery.c",
            "name": "Twilight Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.12
        ]),
        ([
            "type": "research",
            "research item": "/guilds/hand-of-bilanx/light-and-shadow/penumbral-arts.c",
            "name": "Penumbral Arts",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.12
        ]),
        ([
            "type": "research",
            "research item": "/guilds/hand-of-bilanx/light-and-shadow/third-truth-perfected.c",
            "name": "Third Truth Perfected",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.10
        ]),
        ([
            "type": "research",
            "research item": "/guilds/hand-of-bilanx/light-and-shadow/third-truth-ascendant.c",
            "name": "Third Truth Ascendant",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.10
        ]),
        ([
            "type": "skill",
            "name": "body",
            "formula": "additive",
            "rate": 0.18
        ]),
        ([
            "type": "skill",
            "name": "spirit",
            "formula": "additive",
            "rate": 0.18
        ]),
        ([
            "type": "skill",
            "name": "evocation",
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
            "rate": 0.12
        ]),
        ([
            "type": "level",
            "name": "Hand of Bilanx",
            "formula": "logarithmic",
            "rate": 1.10
        ])
    }));

    addSpecification("cooldown", 45);
    addSpecification("event handler", "waveOfThirdTruthEvent");
    addSpecification("command template", "wave of the third truth");
    addSpecification("use ability message", "##InitiatorName## releases "
        "the wave of the third truth - radiance and shadow crashing "
        "together in perfect balance across the entire area.");
}
