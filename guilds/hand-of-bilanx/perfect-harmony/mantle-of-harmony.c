//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Mantle of Harmony");
    addSpecification("source", "Hand of Bilanx");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the mantle of harmony. The Hand cloaks themselves "
        "in the living aura of perfect balance, protecting allies nearby "
        "from harm and emanating a field that dampens the worst excesses "
        "of both extreme violence and extreme entropy.");

    addPrerequisite("/guilds/hand-of-bilanx/perfect-harmony/root.c",
        (["type": "research"]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 55);
    addSpecification("stamina point cost", 25);

    addSpecification("bonus defense", 3);
    addSpecification("bonus armor class", 2);
    addSpecification("bonus soak", 2);
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

    addSpecification("cooldown", 60);
    addSpecification("event handler", "mantleOfHarmonyEvent");
    addSpecification("command template", "mantle of harmony");
    addSpecification("use ability activate message", "##InitiatorName##'s "
        "body radiates a corona of light and shadow in equal measure. "
        "The mantle of harmony expands outward, settling over all nearby "
        "allies like a second skin of balanced force.");
    addSpecification("use ability deactivate message", "##InitiatorName## "
        "##Infinitive::release## the mantle of harmony and the aura fades.");
}
