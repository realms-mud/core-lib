//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/constructedResearchComponent.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Wall Form");
    addSpecification("source", "aeromancer");

    addSpecification("description", "This research provides the user with the "
        "knowledge of creating spells that conjure a wall of energy to block or impede foes.");

    addPrerequisite("/guilds/aeromancer/forms/root.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Constructed Spell Multiplier":26,
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("additional cooldown", 20);
    addSpecification("additional spell point cost", 30);

    addSpecification("use combination message", 
        "##InitiatorName## ##Infinitive::conjure## a wall of ##Function## before ##TargetName##.");
}
