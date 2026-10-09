//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Mote of Light");
    addSpecification("source", "Hand of Bilanx");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the mote of light. A small focused fragment of "
        "balanced radiance, it burns a foe without the full weight of "
        "the radiant bolt.");

    addPrerequisite("level",
        (["type": "level",
          "guild": "Hand of Bilanx",
          "value": 3 ]));

    addPrerequisite("/guilds/hand-of-bilanx/light-and-shadow/radiant-bolt.c",
        (["type": "research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 10);

    addSpecification("damage hit points", ({ ([
            "probability": 100,
            "base damage": 8,
            "range": 6
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
            "rate": 0.12
        ]),
        ([
            "type": "skill",
            "name": "evocation",
            "formula": "additive",
            "rate": 0.08
        ]),
        ([
            "type": "skill",
            "name": "magical essence",
            "formula": "logarithmic",
            "rate": 1.15
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.08
        ]),
        ([
            "type": "level",
            "name": "Hand of Bilanx",
            "formula": "logarithmic",
            "rate": 1.03
        ])
    }));

    addSpecification("cooldown", 4);
    addSpecification("event handler", "moteOfLightEvent");
    addSpecification("command template", "mote of light [##Target##]");
    addSpecification("use ability message", "##InitiatorName## flicks a "
        "mote of balanced radiance at ##TargetName##.");
}
