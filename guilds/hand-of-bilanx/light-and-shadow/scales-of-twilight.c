//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Scales of Twilight");
    addSpecification("source", "Hand of Bilanx");
    addSpecification("description", "This research provides the user with the "
        "knowledge of scales of twilight. The priest achieves perfect "
        "interplay between radiance and shadow, launching twin bolts - "
        "one of each - at a target simultaneously.");

    addPrerequisite("level",
        (["type": "level",
          "guild": "Hand of Bilanx",
          "value": 55 ]));

    addPrerequisite("/guilds/hand-of-bilanx/light-and-shadow/absolute-radiance.c",
        (["type": "research"]));

    addPrerequisite("/guilds/hand-of-bilanx/light-and-shadow/absolute-shadow.c",
        (["type": "research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 60);

    addSpecification("damage hit points", ({ ([
            "probability": 100,
            "base damage": 48,
            "range": 26
        ])
    }));
    addSpecification("damage type", "energy");
    addSpecification("siphon hit points", ({ ([
            "probability": 100,
            "base damage": 10,
            "range": 6
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
            "rate": 0.16
        ]),
        ([
            "type": "skill",
            "name": "spirit",
            "formula": "additive",
            "rate": 0.16
        ]),
        ([
            "type": "skill",
            "name": "evocation",
            "formula": "additive",
            "rate": 0.12
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
            "rate": 1.08
        ])
    }));

    addSpecification("cooldown", 30);
    addSpecification("event handler", "scalesOfTwilightEvent");
    addSpecification("command template", "scales of twilight [##Target##]");
    addSpecification("use ability message", "##InitiatorName## launches "
        "twin strikes of radiance and shadow in perfect balance "
        "at ##TargetName##.");
}
