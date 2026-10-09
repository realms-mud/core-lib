//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Touch of Chaos");
    addSpecification("source", "Hand of Bilanx");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the touch of chaos spell. The priest looses a measure "
        "of unmaking disorder into a foe, fraying their discipline so that "
        "their movements falter and their strength turns against itself.");

    addPrerequisite("/guilds/hand-of-bilanx/order-and-chaos/root.c",
        (["type": "research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 25);

    addSpecification("apply slow", 1);
    addSpecification("apply enfeebled", 2);
    addSpecification("duration", 45);
    addSpecification("supercede targets", 1);

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/hand-of-bilanx/order-and-chaos/discipline-of-law.c",
            "name": "Discipline of Law",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.10
        ]),
        ([
            "type": "research",
            "research item": "/guilds/hand-of-bilanx/order-and-chaos/balanced-dominion.c",
            "name": "Balanced Dominion",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.10
        ]),
        ([
            "type": "research",
            "research item": "/guilds/hand-of-bilanx/order-and-chaos/sovereign-equilibrium.c",
            "name": "Sovereign Equilibrium",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.10
        ]),
        ([
            "type": "skill",
            "name": "philosophy",
            "formula": "additive",
            "rate": 0.08
        ]),
        ([
            "type": "skill",
            "name": "manipulation",
            "formula": "additive",
            "rate": 0.08
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "base value": 1,
            "rate": 1.05
        ]),
        ([
            "type": "skill",
            "name": "magical essence",
            "formula": "logarithmic",
            "base value": 1,
            "rate": 1.05
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.05
        ]),
        ([
            "type": "level",
            "name": "Hand of Bilanx",
            "formula": "logarithmic",
            "base value": 1,
            "rate": 1.05
        ])
    }));

    addSpecification("cooldown", 12);
    addSpecification("event handler", "touchOfChaosEvent");
    addSpecification("command template", "touch of chaos [at ##Target##]");
    addSpecification("use ability message", "Jagged grey static crawls over "
        "##TargetName## as ##InitiatorName## ##Infinitive::loose## a thread "
        "of raw disorder into them.");
}
