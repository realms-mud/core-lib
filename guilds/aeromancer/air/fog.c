//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Fog");
    addSpecification("source", "aeromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the fog spell. The aeromancer rapidly cools the "
        "surrounding air, causing moisture to condense into a thick, "
        "impenetrable fog that blankets the entire area. All enemies caught "
        "within struggle to see, severely hampering their ability to land "
        "accurate strikes.");

    addPrerequisite("/guilds/aeromancer/air/blinding-mist.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "aeromancer",
            "value": 11
        ]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 50);

    addSpecification("penalty to attack", 8);
    addSpecification("duration", 60);

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

    addSpecification("cooldown", 60);
    addSpecification("event handler", "fogEvent");
    addSpecification("command template", "fog");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::conjure## a dense, swirling fog that blankets the area.");
}
