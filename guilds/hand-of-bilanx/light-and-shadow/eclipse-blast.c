//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Eclipse Blast");
    addSpecification("source", "Hand of Bilanx");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the eclipse blast spell. At the height of their mastery "
        "of the third truth, the priest may call forth a moment of total "
        "eclipse - radiance and shadow annihilating each other in the same "
        "instant, releasing the energy of their collision in a searing blast.");

    addPrerequisite("level",
        (["type": "level",
          "guild": "Hand of Bilanx",
          "value": 35 ]));

    addPrerequisite("/guilds/hand-of-bilanx/light-and-shadow/twilight-lance.c",
        (["type": "research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 38);

    addSpecification("damage hit points", ({ ([
            "probability": 80,
            "base damage": 28,
            "range": 20
        ]),
        ([
            "probability": 20,
            "base damage": 46,
            "range": 22
        ])
    }));
    addSpecification("damage type", "energy");

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
            "name": "spirit",
            "formula": "additive",
            "rate": 0.12
        ]),
        ([
            "type": "skill",
            "name": "evocation",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.16
        ]),
        ([
            "type": "skill",
            "name": "magical essence",
            "formula": "logarithmic",
            "rate": 1.14
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
            "rate": 1.06
        ])
    }));

    addSpecification("cooldown", 15);
    addSpecification("event handler", "eclipseBlastEvent");
    addSpecification("command template", "eclipse blast [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::call## a moment of perfect eclipse and drives both "
        "hands forward - radiance and shadow detonate together and the "
        "shockwave of their annihilation engulfs ##TargetName##.");
}
