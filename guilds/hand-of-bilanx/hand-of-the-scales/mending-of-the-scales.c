//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Mending of the Scales");
    addSpecification("source", "Hand of Bilanx");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the mending of the scales. The hierophant channels "
        "a larger restoration of balance to an ally.");

    addPrerequisite("level",
        (["type": "level",
          "guild": "Hand of Bilanx",
          "value": 1 ]));

    addPrerequisite("guild rank",
        (["type": "guild rank",
          "guild": "Hand of Bilanx",
          "value": "hierophant" ]));

    addPrerequisite("/guilds/hand-of-bilanx/hand-of-the-scales/rebalancing-touch.c",
        (["type": "research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 38);
    addSpecification("cooldown", 14);

    addSpecification("increase hit points", ({ ([
            "probability": 65,
            "base damage": 28,
            "range": 16
        ]),
        ([
            "probability": 35,
            "base damage": 44,
            "range": 20
        ])
    }));
    addSpecification("increase spell points", ({ ([
            "probability": 100,
            "base damage": 12,
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
            "name": "anatomy and physiology",
            "formula": "additive",
            "rate": 0.14
        ]),
        ([
            "type": "skill",
            "name": "insight",
            "formula": "additive",
            "rate": 0.10
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
            "rate": 1.06
        ])
    }));

    addSpecification("event handler", "mendingOfTheScalesEvent");
    addSpecification("command template",
        "mending of the scales [##Target##]");
    addSpecification("use ability message", "##InitiatorName## channels "
        "a deeper restoration of balance into ##TargetName##.");
}
