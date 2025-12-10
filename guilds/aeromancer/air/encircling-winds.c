//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Encircling Winds");
    addSpecification("source", "aeromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the encircling winds spell. The aeromancer creates a "
        "personal storm system that orbits their body - multiple layers of "
        "spinning wind that both protect and empower. The winds anticipate "
        "attacks and guide the aeromancer's own strikes with preternatural "
        "accuracy.");

    addPrerequisite("/guilds/aeromancer/air/wind-walk.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "aeromancer",
            "value": 37
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 110);

    addSpecification("bonus defense", 12);
    addSpecification("bonus dodge", 8);
    addSpecification("bonus parry", 8);
    addSpecification("bonus attack", 5);
    addSpecification("apply haste", 1);
    addSpecification("duration", 180);

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

    addSpecification("cooldown", 300);
    addSpecification("event handler", "encirclingWindsEvent");
    addSpecification("command template", "encircling winds");
    addSpecification("use ability message", "Powerful winds begin to swirl "
        "around ##InitiatorName##, forming a protective barrier that "
        "enhances ##InitiatorPossessive## combat prowess.");
}
