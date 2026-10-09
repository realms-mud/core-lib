//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Searing Ray");
    addSpecification("source", "Hand of Bilanx");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the searing ray. A focused beam of balanced radiant "
        "energy is directed at a single target with concentrated force.");

    addPrerequisite("level",
        (["type": "level",
          "guild": "Hand of Bilanx",
          "value": 6 ]));

    addPrerequisite("/guilds/hand-of-bilanx/light-and-shadow/twilight-mastery.c",
        (["type": "research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 18);

    addSpecification("damage hit points", ({ ([
            "probability": 80,
            "base damage": 14,
            "range": 10
        ]),
        ([
            "probability": 20,
            "base damage": 24,
            "range": 12
        ])
    }));
    addSpecification("damage type", "radiant");

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
            "rate": 0.15
        ]),
        ([
            "type": "skill",
            "name": "evocation",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "skill",
            "name": "magical essence",
            "formula": "logarithmic",
            "rate": 1.20
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.18
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "level",
            "name": "Hand of Bilanx",
            "formula": "logarithmic",
            "rate": 1.04
        ])
    }));

    addSpecification("cooldown", 6);
    addSpecification("event handler", "searingRayEvent");
    addSpecification("command template", "searing ray [##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::channel## a focused beam of balanced radiance "
        "at ##TargetName##.");
}
