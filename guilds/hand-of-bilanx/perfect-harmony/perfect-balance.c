//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Perfect Balance");
    addSpecification("source", "Hand of Bilanx");
    addSpecification("description", "This research provides the user with the knowledge of perfect balance. The Hand achieves the eighth truth in a single working, simultaneously restoring and balancing an ally's complete being.");

    addPrerequisite("level",
        (["type": "level",
          "guild": "Hand of Bilanx",
          "value": 1 ]));

    addPrerequisite("guild rank",
        (["type": "guild rank",
          "guild": "Hand of Bilanx",
          "value": "hand of bilanx" ]));

    addPrerequisite("/guilds/hand-of-bilanx/perfect-harmony/perfect-restoration.c",
        (["type": "research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 65);
    addSpecification("cooldown", 22);

    addSpecification("increase hit points", ({ ([
            "probability": 65,
            "base damage": 48,
            "range": 26
        ]),
        ([
            "probability": 35,
            "base damage": 70,
            "range": 30
        ])
    }));

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
            "name": "anatomy and physiology",
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

    addSpecification("event handler", "perfectBalanceEvent");
    addSpecification("command template", "perfect balance [##Target##]");
    addSpecification("use ability message", "##InitiatorName## achieves perfect balance for ##TargetName##.");
}