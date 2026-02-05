//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/constructedResearchComponent.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Quake Form");
    addSpecification("source", "geomancer");

    addSpecification("description", "This research provides the user with the "
        "knowledge of creating spells that cause localized earthquakes.");

    addPrerequisite("/guilds/geomancer/forms/vortex.c",
        (["type":"research"]));
    addPrerequisite("level",
        ([
            "type": "level",
            "guild": "geomancer",
            "value": 19
        ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Constructed Spell Multiplier": 42,
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("additional cooldown", 28);
    addSpecification("additional spell point cost", 48);

    addSpecification("use combination message", 
        "##InitiatorName## ##Infinitive::shake## the earth with ##Function##, devastating ##TargetName##.");
}
