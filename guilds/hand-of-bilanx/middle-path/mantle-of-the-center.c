//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Mantle of the Center");
    addSpecification("source", "Hand of Bilanx");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the mantle of the center. The priest wraps "
        "themselves in a protective field of pure balanced energy that "
        "softens all incoming harm from extremes.");

    addPrerequisite("level",
        (["type": "level",
          "guild": "Hand of Bilanx",
          "value": 18 ]));

    addPrerequisite("/guilds/hand-of-bilanx/middle-path/aura-of-tranquility.c",
        (["type": "research"]));

    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 22);

    addSpecification("bonus armor class", 8);
    addSpecification("bonus defense class", 8);
    addSpecification("bonus soak", 4);
    addSpecification("bonus resist magical", 12);

    addSpecification("modifiers", ({
        ([
            "type": "skill",
            "name": "magical essence",
            "formula": "logarithmic",
            "rate": 1.22
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.18
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.12
        ]),
        ([
            "type": "attribute",
            "name": "constitution",
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

    addSpecification("duration", 200);
    addSpecification("cooldown", 16);
    addSpecification("event handler", "mantleOfTheCenterEvent");
    addSpecification("command template", "mantle of the center");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::draw## the mantle of the center around "
        "##InitiatorObjective##self.");
    addSpecification("use ability fail message", "##InitiatorName## cannot "
        "draw the mantle of the center right now.");
}
