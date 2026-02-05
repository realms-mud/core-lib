//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/constructedResearchComponent.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Spray Form");
    addSpecification("source", "geomancer");

    addSpecification("description", "This research provides the user with the "
        "knowledge of creating spells that spray debris at foes.");

    addPrerequisite("/guilds/geomancer/forms/cloud.c",
        (["type":"research"]));
    addPrerequisite("level",
        ([
            "type": "level",
            "guild": "geomancer",
            "value": 7
        ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Constructed Spell Multiplier": 16,
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("additional cooldown", 7);
    addSpecification("additional spell point cost", 12);

    addSpecification("use combination message", 
        "##InitiatorName## ##Infinitive::spray## ##Function## at ##TargetName##.");
}
