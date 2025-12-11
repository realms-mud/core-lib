//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/constructedResearchComponent.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Cage Form");
    addSpecification("source", "aeromancer");

    addSpecification("description", "This research provides the user with the "
        "knowledge of creating spells that form encircling bands of energy "
        "to entrap and harm a foe.");

    addPrerequisite("/guilds/aeromancer/forms/ring.c",
        (["type":"research"]));
    addPrerequisite("level",
        ([
            "type": "level",
            "guild": "aeromancer",
            "value": 13
        ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Constructed Spell Multiplier": 22,
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("additional cooldown", 14);
    addSpecification("additional spell point cost", 20);

    addSpecification("use combination message", 
        "##InitiatorName## ##Infinitive::trap## ##TargetName## within a cage of ##Function##.");
}
