//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Earth Shield");
    addSpecification("source", "geomancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the earth shield spell. The geomancer surrounds "
        "themselves with orbiting chunks of stone that deflect incoming attacks.");

    addPrerequisite("/guilds/geomancer/earth/quake.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "geomancer",
            "value": 13
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 75);

    addSpecification("bonus defense", 10);
    addSpecification("bonus damage reduction", 5);
    addSpecification("duration", 120);

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

    addSpecification("cooldown", 180);
    addSpecification("event handler", "earthShieldEvent");
    addSpecification("command template", "earth shield");
    addSpecification("use ability message", "Chunks of stone rise from the "
        "ground and begin orbiting around ##InitiatorName##, forming a "
        "protective shield.");
}
