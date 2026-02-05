//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Dust Shroud");
    addSpecification("source", "geomancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the dust shroud spell. The geomancer conjures a "
        "swirling cloud of fine dust that clings to a target's face and eyes. "
        "The particles constantly shift and reform, making it nearly impossible "
        "to see clearly and significantly hampering the target's ability to "
        "fight effectively.");

    addPrerequisite("/guilds/geomancer/earth/root.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "geomancer",
            "value": 5
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 30);

    addSpecification("penalty to attack", 5);
    addSpecification("penalty to defense", 3);
    addSpecification("duration", 45);

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

    addSpecification("cooldown", 30);
    addSpecification("event handler", "dustShroudEvent");
    addSpecification("command template", "dust shroud [at ##Target##]");
    addSpecification("use ability message", "A swirling cloud of fine dust "
        "engulfs ##TargetName##, obscuring ##TargetPossessive## vision.");
}
