//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Water Walk");
    addSpecification("source", "aquamancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the water walk spell. The aquamancer attunes their body "
        "to water so completely that they can walk upon its surface and move "
        "with fluid grace. Their movements become incredibly smooth and "
        "difficult to predict, enhancing their defensive capabilities.");

    addPrerequisite("/guilds/aquamancer/water/water-shield.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "aquamancer",
            "value": 23
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 70);

    addSpecification("apply haste", 1);
    addSpecification("bonus dodge", 8);
    addSpecification("bonus defense", 5);
    addSpecification("duration", 120);

    addSpecification("modifiers", ({ 
        ([
            "type": "skill",
            "name": "elemental water",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "level",
            "name": "level",
            "formula": "logarithmic",
            "rate": 1.05
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
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.05
        ]), 
    }));

    addSpecification("cooldown", 180);
    addSpecification("event handler", "waterWalkEvent");
    addSpecification("command template", "water walk");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::become## one with water, ##InitiatorPossessive## "
        "movements flowing with liquid grace.");
}
