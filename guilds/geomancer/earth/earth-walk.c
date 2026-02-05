//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Earth Walk");
    addSpecification("source", "geomancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the earth walk spell. The geomancer becomes one with "
        "the earth, gaining increased movement and stability.");

    addPrerequisite("/guilds/geomancer/earth/earth-shield.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "geomancer",
            "value": 23
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 50);

    addSpecification("bonus defense", 5);
    addSpecification("bonus constitution", 2);
    addSpecification("duration", 300);

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
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.05
        ]), 
    }));

    addSpecification("cooldown", 120);
    addSpecification("event handler", "earthWalkEvent");
    addSpecification("command template", "earth walk");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::become## one with the earth, moving with newfound "
        "stability and grace.");
}
