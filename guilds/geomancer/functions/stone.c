//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/constructedResearchComponent.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Stone Damage");
    addSpecification("source", "geomancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of creating spells that damage targets with solid stone.");

    addPrerequisite("/guilds/geomancer/functions/root.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("damage type", "physical");

    addSpecification("affected research", ([
        "Constructed Spell Multiplier": 5,
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("additional cooldown", 2);
    addSpecification("additional spell point cost", 5);

    addSpecification("combination descriptor", "solid stone");
}
