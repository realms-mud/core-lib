//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Air Barrier");
    addSpecification("source", "aeromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the air barrier spell. Building upon the basic air shield, "
        "the aeromancer compresses multiple layers of spinning air into a dense "
        "barrier that can absorb significant punishment. The barrier actively "
        "pushes back against incoming attacks, providing superior protection.");

    addPrerequisite("/guilds/aeromancer/air/air-shield.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "aeromancer",
            "value": 21
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 75);

    addSpecification("bonus defense", 8);
    addSpecification("bonus soak", 3);
    addSpecification("bonus parry", 5);
    addSpecification("bonus dodge", 5);
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
    addSpecification("event handler", "airBarrierEvent");
    addSpecification("command template", "air barrier");
    addSpecification("use ability message", "A dense barrier of compressed "
        "air forms around ##InitiatorName##, shimmering with protective energy.");
}
