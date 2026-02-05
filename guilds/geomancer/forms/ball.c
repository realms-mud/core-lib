//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/constructedResearchComponent.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Ball Form");
    addSpecification("source", "geomancer");

    addSpecification("description", "This research provides the user with the "
        "knowledge of creating spells that form a ball of stone energy.");

    addPrerequisite("/guilds/geomancer/forms/bolt.c",
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
        "Constructed Spell Multiplier": 20,
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("additional cooldown", 8);
    addSpecification("additional spell point cost", 14);

    addSpecification("use combination message", 
        "##InitiatorName## ##Infinitive::hurl## a ball of ##Function## at ##TargetName##.");
}
