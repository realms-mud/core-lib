//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/constructedResearchComponent.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Vortex Form");
    addSpecification("source", "geomancer");

    addSpecification("description", "This research provides the user with the "
        "knowledge of creating spells that form a vortex of stone and debris.");

    addPrerequisite("/guilds/geomancer/forms/eruption.c",
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
        "Constructed Spell Multiplier": 38,
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("additional cooldown", 24);
    addSpecification("additional spell point cost", 42);

    addSpecification("use combination message", 
        "##InitiatorName## ##Infinitive::summon## a vortex of ##Function## that engulfs ##TargetName##.");
}
