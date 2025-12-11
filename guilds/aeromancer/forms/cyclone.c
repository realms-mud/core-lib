//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/constructedResearchComponent.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Cyclone Form");
    addSpecification("source", "aeromancer");

    addSpecification("description", "This research provides the user with the "
        "knowledge of creating spells that conjure a rotating column of energy "
        "that strikes a foe multiple times.");

    addPrerequisite("/guilds/aeromancer/forms/vortex.c",
        (["type":"research"]));
    addPrerequisite("level",
        ([
            "type":"level",
            "guild":"aeromancer",
            "value":19
        ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Constructed Spell Multiplier": 35,
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("additional cooldown", 24);
    addSpecification("additional spell point cost", 40);
    addSpecification("additional repeat effect", 4);

    addSpecification("use combination message", 
        "##InitiatorName## ##Infinitive::conjure## a rotating cyclone of ##Function## that batters ##TargetName##.");
    addSpecification("repeated combination message",
        "The cyclone of ##Function## continues to batter ##TargetName##.");
}
