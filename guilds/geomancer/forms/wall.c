//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/constructedResearchComponent.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Wall Form");
    addSpecification("source", "geomancer");

    addSpecification("description", "This research provides the user with the "
        "knowledge of creating spells that form a crushing wall of stone "
        "that slams into foes.");

    addPrerequisite("/guilds/geomancer/forms/wave.c",
        (["type":"research"]));
    addPrerequisite("level",
        ([
            "type": "level",
            "guild": "geomancer",
            "value": 13
        ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Constructed Spell Multiplier": 30,
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("additional cooldown", 16);
    addSpecification("additional spell point cost", 28);

    addSpecification("use combination message", 
        "##InitiatorName## ##Infinitive::summon## a wall of ##Function## that crashes into ##TargetName##.");
}
