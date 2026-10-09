//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Perfect Harmony");
    addSpecification("source", "Hand of Bilanx");
    addSpecification("description", "This research provides the user with the "
        "knowledge of perfect harmony. The Hand achieves Bilanx's eighth "
        "truth as an ongoing state - their very existence becomes a point "
        "of perfect balance that all extremes flow around. No single force "
        "may gain dominance against them.");

    addPrerequisite("level",
        (["type": "level",
          "guild": "Hand of Bilanx",
          "value": 1 ]));

    addPrerequisite("guild rank",
        (["type": "guild rank",
          "guild": "Hand of Bilanx",
          "value": "hand of bilanx" ]));

    addPrerequisite("/guilds/hand-of-bilanx/perfect-harmony/harmony-nova.c",
        (["type": "research"]));

    addPrerequisite("/guilds/hand-of-bilanx/perfect-harmony/absolute-balance.c",
        (["type": "research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 60);
    addSpecification("stamina point cost", 30);

    addSpecification("bonus strength", 1);
    addSpecification("bonus intelligence", 1);
    addSpecification("bonus wisdom", 2);
    addSpecification("bonus constitution", 1);
    addSpecification("bonus defense", 3);
    addSpecification("bonus armor class", 2);
    addSpecification("bonus soak", 2);
    addSpecification("apply fortified", 1);
    addSpecification("apply damage reflection", 1);
    addSpecification("bonus heal hit points rate", 1);
    addSpecification("bonus heal spell points rate", 1);
    addSpecification("bonus resist magical", 3);
    addSpecification("bonus resist physical", 3);

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/hand-of-bilanx/perfect-harmony/absolute-balance.c",
            "name": "Absolute Balance",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.10
        ]),
        ([
            "type": "research",
            "research item": "/guilds/hand-of-bilanx/perfect-harmony/perfect-equilibrium.c",
            "name": "Perfect Equilibrium",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.12
        ]),
        ([
            "type": "skill",
            "name": "magical essence",
            "formula": "logarithmic",
            "rate": 1.16
        ]),
        ([
            "type": "skill",
            "name": "insight",
            "formula": "additive",
            "rate": 0.12
        ]),
        ([
            "type": "skill",
            "name": "theology",
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
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "attribute",
            "name": "charisma",
            "formula": "additive",
            "rate": 0.05
        ]),
        ([
            "type": "level",
            "name": "Hand of Bilanx",
            "formula": "logarithmic",
            "rate": 1.08
        ])
    }));

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/hand-of-bilanx/perfect-harmony/absolute-balance.c",
            "name": "Absolute Balance",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "research",
            "research item": "/guilds/hand-of-bilanx/perfect-harmony/perfect-equilibrium.c",
            "name": "Perfect Equilibrium",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.30
        ]),
        ([
            "type": "skill",
            "name": "magical essence",
            "formula": "logarithmic",
            "rate": 1.30
        ]),
        ([
            "type": "skill",
            "name": "insight",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "skill",
            "name": "theology",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.30
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "attribute",
            "name": "charisma",
            "formula": "additive",
            "rate": 0.05
        ]),
        ([
            "type": "level",
            "name": "Hand of Bilanx",
            "formula": "logarithmic",
            "rate": 1.10
        ])
    }));

    addSpecification("cooldown", 120);
    addSpecification("event handler", "perfectHarmonyEvent");
    addSpecification("command template", "perfect harmony");
    addSpecification("use ability activate message", "##InitiatorName##'s "
        "eyes close. When they open, light and shadow move in perfect "
        "spirals outward from ##InitiatorSubjective##. The state of "
        "perfect harmony has been achieved.");
    addSpecification("use ability deactivate message", "##InitiatorName## "
        "exhales and the state of perfect harmony quietly withdraws.");
}
