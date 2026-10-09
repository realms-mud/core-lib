//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Restore Balance");
    addSpecification("source", "Hand of Bilanx");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the restore balance spell. The arbiter reads the "
        "distortions in the fabric of the world around an ally and "
        "corrects them, restoring vitality and removing the weight of "
        "accumulated imbalance.");

    addPrerequisite("/guilds/hand-of-bilanx/hand-of-the-scales/root.c",
        (["type": "research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 30);

    addSpecification("increase hit points", ({ ([
            "probability": 80,
            "base damage": 22,
            "range": 14
        ]),
        ([
            "probability": 20,
            "base damage": 38,
            "range": 18
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
            "rate": 0.15
        ]),
        ([
            "type": "skill",
            "name": "body",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "skill",
            "name": "insight",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.14
        ]),
        ([
            "type": "skill",
            "name": "magical essence",
            "formula": "logarithmic",
            "rate": 1.16
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
            "rate": 1.05
        ])
    }));

    addSpecification("cooldown", 6);
    addSpecification("event handler", "restoreBalanceEvent");
    addSpecification("command template", "restore balance [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## reads the "
        "distortions around ##TargetName## and ##InitiatorSubjective## "
        "##Infinitive::press## both hands forward, correcting each "
        "imbalance with a surge of the arbiter's will.");
}
