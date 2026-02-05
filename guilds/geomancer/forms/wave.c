//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/constructedResearchComponent.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Wave Form");
    addSpecification("source", "geomancer");

    addSpecification("description", "This research provides the user with the "
        "knowledge of creating spells that send a wave of earth at foes.");

    addPrerequisite("/guilds/geomancer/forms/cloud.c",
        (["type":"research"]));
    addPrerequisite("level",
        ([
            "type": "level",
            "guild": "geomancer",
            "value": 9
        ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Constructed Spell Multiplier": 22,
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("additional cooldown", 10);
    addSpecification("additional spell point cost", 16);

    addSpecification("use combination message", 
        "##InitiatorName## ##Infinitive::send## a wave of ##Function## at ##TargetName##.");
}
