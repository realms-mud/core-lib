//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Wave of the Seventh Truth");
    addSpecification("source", "Hand of Bilanx");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the wave of the seventh truth. The capstone of the "
        "hand-of-the-scales path, this working releases a tidal force of "
        "cosmic correction that strikes all enemies and partially restores "
        "all allies simultaneously.");

    addPrerequisite("level",
        (["type": "level",
          "guild": "Hand of Bilanx",
          "value": 1 ]));

    addPrerequisite("guild rank",
        (["type": "guild rank",
          "guild": "Hand of Bilanx",
          "value": "hand of bilanx" ]));

    addPrerequisite("/guilds/hand-of-bilanx/hand-of-the-scales/absolute-fracture.c",
        (["type": "research"]));

    addPrerequisite("/guilds/hand-of-bilanx/hand-of-the-scales/cosmic-correction.c",
        (["type": "research"]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 80);
    addSpecification("cooldown", 45);

    addSpecification("damage hit points", ({ ([
            "probability": 60,
            "base damage": 44,
            "range": 24
        ]),
        ([
            "probability": 40,
            "base damage": 66,
            "range": 28
        ])
    }));
    addSpecification("damage type", "magical");
    addSpecification("siphon hit points", ({ ([
            "probability": 100,
            "base damage": 14,
            "range": 8
        ])
    }));

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/hand-of-bilanx/hand-of-the-scales/scales-attunement.c",
            "name": "Scales Attunement",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.14
        ]),
        ([
            "type": "research",
            "research item": "/guilds/hand-of-bilanx/hand-of-the-scales/arbiters-insight.c",
            "name": "Arbiter's Insight",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.12
        ]),
        ([
            "type": "research",
            "research item": "/guilds/hand-of-bilanx/hand-of-the-scales/scales-mastery.c",
            "name": "Scales Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.12
        ]),
        ([
            "type": "research",
            "research item": "/guilds/hand-of-bilanx/hand-of-the-scales/cosmic-correction.c",
            "name": "Cosmic Correction",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.10
        ]),
        ([
            "type": "research",
            "research item": "/guilds/hand-of-bilanx/hand-of-the-scales/seventh-truth-mastery.c",
            "name": "Seventh Truth Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.10
        ]),
        ([
            "type": "skill",
            "name": "insight",
            "formula": "additive",
            "rate": 0.16
        ]),
        ([
            "type": "skill",
            "name": "evocation",
            "formula": "additive",
            "rate": 0.14
        ]),
        ([
            "type": "skill",
            "name": "theology",
            "formula": "additive",
            "rate": 0.10
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

    addSpecification("event handler", "waveOfSeventhTruthEvent");
    addSpecification("command template", "wave of the seventh truth");
    addSpecification("use ability message", "##InitiatorName## releases "
        "a wave of the seventh truth - cosmic correction crashing "
        "across the entire area.");
}
