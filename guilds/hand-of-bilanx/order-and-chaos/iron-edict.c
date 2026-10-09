//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Iron Edict");
    addSpecification("source", "Hand of Bilanx");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the iron edict spell. The priest speaks with the "
        "authority of absolute law, enforcing order upon an ally's body and "
        "mind with such force that their combat effectiveness rises sharply.");

    addPrerequisite("level",
        (["type": "level",
          "guild": "Hand of Bilanx",
          "value": 9 ]));

    addPrerequisite("/guilds/hand-of-bilanx/order-and-chaos/mantle-of-order.c",
        (["type": "research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 20);

    addSpecification("bonus attack", 3);
    addSpecification("bonus defense", 3);
    addSpecification("bonus damage", 2);
    addSpecification("apply fortified", 2);
    addSpecification("duration", 90);

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
            "name": "leadership",
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

    addSpecification("cooldown", 45);
    addSpecification("event handler", "ironEdictEvent");
    addSpecification("command template", "iron edict [at ##Target##]");
    addSpecification("use ability message", "A lattice of silver law settles "
        "over ##TargetName## as ##InitiatorName## ##Infinitive::utter## the "
        "iron edict of Bilanx, forging their will into an instrument of "
        "perfect order.");
}
