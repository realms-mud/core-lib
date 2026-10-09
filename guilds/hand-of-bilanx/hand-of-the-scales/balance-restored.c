//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Balance Restored");
    addSpecification("source", "Hand of Bilanx");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the balance restored working. The arbiter applies "
        "a full correction to an ally at the level of cosmic truth - both "
        "body and spirit are restored to wholeness simultaneously.");

    addPrerequisite("level",
        (["type": "level",
          "guild": "Hand of Bilanx",
          "value": 1 ]));

    addPrerequisite("guild rank",
        (["type": "guild rank",
          "guild": "Hand of Bilanx",
          "value": "hierophant" ]));

    addPrerequisite("/guilds/hand-of-bilanx/hand-of-the-scales/equilibrium-anchor.c",
        (["type": "research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 55);

    addSpecification("increase hit points", ({ ([
            "probability": 70,
            "base damage": 40,
            "range": 22
        ]),
        ([
            "probability": 30,
            "base damage": 60,
            "range": 28
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
            "rate": 0.10
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
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
    addSpecification("event handler", "balanceRestoredEvent");
    addSpecification("command template", "balance restored [##Target##]");
    addSpecification("use ability message", "##InitiatorName## raises both "
        "hands over ##TargetName##. Light and shadow flow in equal streams "
        "from ##InitiatorSubjective## into ##TargetSubjective## as body "
        "and spirit are corrected together.");
}
