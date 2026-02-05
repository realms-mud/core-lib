//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Gather the Stones");
    addSpecification("source", "geomancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the gather the stones spell. The geomancer draws upon "
        "the power of all nearby stone, creating an aura of incredible "
        "defensive might and offensive potential.");

    addPrerequisite("/guilds/geomancer/earth/encircling-stones.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "geomancer",
            "value": 51
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 250);

    addSpecification("bonus defense", 35);
    addSpecification("bonus damage reduction", 20);
    addSpecification("bonus earth attack", 25);
    addSpecification("bonus attack", 15);
    addSpecification("duration", 240);

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

    addSpecification("cooldown", 480);
    addSpecification("event handler", "gatherTheStonesEvent");
    addSpecification("command template", "gather the stones");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::draw## upon the power of all nearby stone, creating "
        "an aura of tremendous earthen might.");
}
