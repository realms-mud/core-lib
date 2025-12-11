//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/constructedResearchComponent.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Thunder Damage");
    addSpecification("source", "aeromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of creating spells that damage targets with concussive "
        "sonic blasts created by rapid air compression.");

    addPrerequisite("/guilds/aeromancer/functions/air.c",
        (["type":"research"]));
    addPrerequisite("level",
        ([
            "type":"level",
            "guild":"aeromancer",
            "value":7
        ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("damage type", "sonic");

    addSpecification("affected research", ([
        "Constructed Spell Multiplier": 18,
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("additional cooldown", 5);
    addSpecification("additional spell point cost", 11);

    addSpecification("combination descriptor", "thunder");
}
