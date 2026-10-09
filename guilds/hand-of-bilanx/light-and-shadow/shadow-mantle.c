//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Shadow Mantle");
    addSpecification("source", "Hand of Bilanx");
    addSpecification("description", "This research provides the user with the "
        "knowledge of shadow mantle. The priest wraps themselves in a "
        "veil of balanced darkness, becoming harder to see and harder "
        "to strike.");

    addPrerequisite("level",
        (["type": "level",
          "guild": "Hand of Bilanx",
          "value": 5 ]));

    addPrerequisite("/guilds/hand-of-bilanx/light-and-shadow/wisp-of-shadow.c",
        (["type": "research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 16);

    addSpecification("bonus defense", 2);
    addSpecification("bonus armor class", 1);
    addSpecification("bonus resist radiant", 3);

    addSpecification("modifiers", ({
        ([
            "type": "skill",
            "name": "spirit",
            "formula": "additive",
            "rate": 0.12
        ]),
        ([
            "type": "skill",
            "name": "magical essence",
            "formula": "logarithmic",
            "rate": 1.18
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.15
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
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

    addSpecification("cooldown", 18);
    addSpecification("event handler", "shadowMantleEvent");
    addSpecification("command template", "shadow mantle");
    addSpecification("use ability activate message", "##InitiatorName## "
        "opens the shadow half of the third truth. A veil of balanced "
        "darkness settles around ##InitiatorObjective##.");
    addSpecification("use ability deactivate message", "##InitiatorName## "
        "##Infinitive::release## the shadow mantle.");
}
