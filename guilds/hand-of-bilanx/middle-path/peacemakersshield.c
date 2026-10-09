//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Peacemaker's Shield");
    addSpecification("source", "Hand of Bilanx");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the peacemaker's shield spell. The priest extends a "
        "measure of the middle path's protection to an ally, raising a "
        "balanced ward around them that turns aside blows without "
        "escalating the conflict.");

    addPrerequisite("level",
        (["type": "level",
          "guild": "Hand of Bilanx",
          "value": 9 ]));

    addPrerequisite("/guilds/hand-of-bilanx/middle-path/pacifying-aura.c",
        (["type": "research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 35);

    addSpecification("bonus defense", 8);
    addSpecification("bonus armor class", 3);
    addSpecification("bonus soak", 5);
    addSpecification("duration", 90);

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
            "name": "concentration",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "skill",
            "name": "diplomacy",
            "formula": "additive",
            "rate": 0.10
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

    addSpecification("cooldown", 45);
    addSpecification("event handler", "peacemakersShieldEvent");
    addSpecification("command template", "peacemaker's shield [at ##Target##]");
    addSpecification("use ability message", "An even grey ward settles over "
        "##TargetName## as ##InitiatorName## ##Infinitive::extend## the "
        "middle path's protection around them.");
}
