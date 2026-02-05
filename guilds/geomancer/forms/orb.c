//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/constructedResearchComponent.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Orb Form");
    addSpecification("source", "geomancer");

    addSpecification("description", "This research provides the user with the "
        "knowledge of creating spells that form a massive orb of stone.");

    addPrerequisite("/guilds/geomancer/forms/blast.c",
        (["type":"research"]));
    addPrerequisite("level",
        ([
            "type": "level",
            "guild": "geomancer",
            "value": 11
        ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Constructed Spell Multiplier": 26,
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("additional cooldown", 12);
    addSpecification("additional spell point cost", 22);

    addSpecification("use combination message", 
        "##InitiatorName## ##Infinitive::hurl## an orb of ##Function## at ##TargetName##.");
}
