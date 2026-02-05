//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/constructedResearchComponent.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Coil Form");
    addSpecification("source", "geomancer");

    addSpecification("description", "This research provides the user with the "
        "knowledge of creating spells that coil around and crush foes.");

    addPrerequisite("/guilds/geomancer/forms/cage.c",
        (["type":"research"]));
    addPrerequisite("level",
        ([
            "type": "level",
            "guild": "geomancer",
            "value": 17
        ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Constructed Spell Multiplier": 36,
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("additional cooldown", 22);
    addSpecification("additional spell point cost", 38);

    addSpecification("use combination message", 
        "##InitiatorName## ##Infinitive::coil## ##Function## around ##TargetName##, crushing ##TargetObjective##.");
}
