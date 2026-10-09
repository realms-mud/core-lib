//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Balanced Form");
    addSpecification("source", "Hand of Bilanx");
    addSpecification("description", "This research provides the user with the "
        "knowledge of balanced form. The priest assumes an equilibrium "
        "stance that simultaneously improves both their physical defense "
        "and their spell casting resilience.");

    addPrerequisite("level",
        (["type": "level",
          "guild": "Hand of Bilanx",
          "value": 3 ]));

    addPrerequisite("/guilds/hand-of-bilanx/equilibrium-form/equilibrium-awakening.c",
        (["type": "research"]));

    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 10);

    addSpecification("bonus armor class", 4);
    addSpecification("bonus defense class", 4);
    addSpecification("bonus resist magical", 8);

    addSpecification("modifiers", ({
        ([
            "type": "skill",
            "name": "magical essence",
            "formula": "logarithmic",
            "rate": 1.15
        ]),
        ([
            "type": "skill",
            "name": "parry",
            "formula": "additive",
            "rate": 0.08
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.08
        ]),
        ([
            "type": "attribute",
            "name": "constitution",
            "formula": "additive",
            "rate": 0.08
        ]),
        ([
            "type": "level",
            "name": "Hand of Bilanx",
            "formula": "logarithmic",
            "rate": 1.04
        ])
    }));

    addSpecification("duration", 150);
    addSpecification("cooldown", 10);
    addSpecification("event handler", "balancedFormEvent");
    addSpecification("command template", "balanced form");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::assume## balanced form, physical and magical "
        "resilience aligning in equilibrium.");
    addSpecification("use ability fail message", "##InitiatorName## cannot "
        "assume balanced form right now.");
}
