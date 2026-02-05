//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Encircling Stones");
    addSpecification("source", "geomancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the encircling stones spell. The geomancer surrounds "
        "themselves with a ring of massive orbiting boulders that provide "
        "exceptional protection and can strike nearby foes.");

    addPrerequisite("/guilds/geomancer/earth/earth-walk.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "geomancer",
            "value": 37
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 150);

    addSpecification("bonus defense", 5);
    addSpecification("bonus attack", 5);
    addSpecification("bonus soak", 5);
    addSpecification("bonus earth attack", 20);
    addSpecification("duration", 180);

    addSpecification("modifiers", ({ 
        ([
            "type": "skill",
            "name": "elemental earth",
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
    addSpecification("event handler", "encirclingStonesEvent");
    addSpecification("command template", "encircling stones");
    addSpecification("use ability message", "Massive boulders rise from the "
        "ground and begin orbiting around ##InitiatorName##, forming a "
        "formidable ring of protection.");
}
