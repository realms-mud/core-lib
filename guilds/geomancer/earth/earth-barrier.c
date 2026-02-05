//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Earth Barrier");
    addSpecification("source", "geomancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the earth barrier spell. The geomancer raises a massive "
        "wall of stone that provides superior protection.");

    addPrerequisite("/guilds/geomancer/earth/earth-shield.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "geomancer",
            "value": 21
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 125);

    addSpecification("bonus defense", 20);
    addSpecification("bonus damage reduction", 10);
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
    addSpecification("event handler", "earthBarrierEvent");
    addSpecification("command template", "earth barrier");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::raise## ##InitiatorPossessive## arms and a massive "
        "barrier of stone rises to protect ##InitiatorObjective##.");
}
