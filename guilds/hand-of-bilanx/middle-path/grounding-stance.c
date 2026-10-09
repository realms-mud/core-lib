//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Grounding Stance");
    addSpecification("source", "Hand of Bilanx");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the grounding stance. The priest plants themselves "
        "at the center, becoming harder to move or damage for a time.");

    addPrerequisite("level",
        (["type": "level",
          "guild": "Hand of Bilanx",
          "value": 3 ]));

    addPrerequisite("/guilds/hand-of-bilanx/middle-path/middle-path-awakening.c",
        (["type": "research"]));

    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 10);

    addSpecification("bonus armor class", 5);
    addSpecification("bonus defense class", 5);
    addSpecification("apply fortified", 1);

    addSpecification("modifiers", ({
        ([
            "type": "skill",
            "name": "parry",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "skill",
            "name": "dodge",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "skill",
            "name": "magical essence",
            "formula": "logarithmic",
            "rate": 1.15
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
            "rate": 1.04
        ])
    }));

    addSpecification("duration", 120);
    addSpecification("cooldown", 10);
    addSpecification("event handler", "groundingStanceEvent");
    addSpecification("command template", "grounding stance");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::plant## ##InitiatorObjective##self firmly at "
        "the center and ##Infinitive::take## a grounding stance.");
    addSpecification("use ability fail message", "##InitiatorName## cannot "
        "take a grounding stance right now.");
}
