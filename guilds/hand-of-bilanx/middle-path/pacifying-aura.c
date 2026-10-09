//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Pacifying Aura");
    addSpecification("source", "Hand of Bilanx");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the pacifying aura spell. The priest projects a field "
        "of enforced equilibrium outward, dulling the will to escalate and "
        "reducing the combat effectiveness of all nearby foes.");

    addPrerequisite("/guilds/hand-of-bilanx/middle-path/root.c",
        (["type": "research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 25);

    addSpecification("penalty to attack", 4);
    addSpecification("penalty to damage", 3);
    addSpecification("apply enfeebled", 2);
    addSpecification("duration", 30);
    addSpecification("supercede targets", 1);

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/hand-of-bilanx/middle-path/steadfast-center.c",
            "name": "Steadfast Center",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item": "/guilds/hand-of-bilanx/middle-path/unshakeable-poise.c",
            "name": "Unshakeable Poise",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "research",
            "research item": "/guilds/hand-of-bilanx/middle-path/bastion-of-balance.c",
            "name": "Bastion of Balance",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "skill",
            "name": "philosophy",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "skill",
            "name": "diplomacy",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.25
        ]),
        ([
            "type": "skill",
            "name": "magical essence",
            "formula": "logarithmic",
            "rate": 1.25
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
            "rate": 1.05
        ])
    }));

    addSpecification("cooldown", 15);
    addSpecification("event handler", "pacifyingAuraEvent");
    addSpecification("command template", "pacifying aura [at ##Target##]");
    addSpecification("use ability message", "A grey stillness settles over "
        "##TargetName## as ##InitiatorName## ##Infinitive::project## an "
        "aura of enforced equilibrium, dulling their will to violence.");
}
