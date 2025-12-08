//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/constructedResearchComponent.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Chill Damage");
    addSpecification("source", "aeromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of creating spells that damage targets with freezing cold "
        "generated through rapid air expansion.");

    addPrerequisite("/guilds/aeromancer/functions/root.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("damage type", "cold");

    addSpecification("affected research", ([
        "Constructed Spell Multiplier": 22,
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("additional cooldown", 6);
    addSpecification("additional spell point cost", 13);

    addSpecification("combination descriptor", "freezing air");
}
