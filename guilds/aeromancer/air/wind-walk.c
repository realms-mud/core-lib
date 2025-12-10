//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Wind Walk");
    addSpecification("source", "aeromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the wind walk spell. The aeromancer partially merges "
        "their essence with the wind, becoming lighter than air and able to "
        "move with supernatural grace. Their feet barely touch the ground as "
        "air currents carry and guide their movements, making them incredibly "
        "difficult to hit.");

    addPrerequisite("/guilds/aeromancer/air/air-shield.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "aeromancer",
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
            "name": "elemental air",
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
    addSpecification("event handler", "windWalkEvent");
    addSpecification("command template", "wind walk");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::become## one with the wind, ##InitiatorPossessive## "
        "form shimmering with swift currents of air.");
}
