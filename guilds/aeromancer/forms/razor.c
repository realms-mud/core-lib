//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/constructedResearchComponent.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Razor Form");
    addSpecification("source", "aeromancer");

    addSpecification("description", "This research provides the user with the "
        "knowledge of creating spells that form thin, cutting slices of "
        "compressed energy to strike a foe with precision.");

    addPrerequisite("/guilds/aeromancer/forms/root.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Constructed Spell Multiplier": 19,
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("additional cooldown", 9);
    addSpecification("additional spell point cost", 14);

    addSpecification("use combination message", 
        "##Infinitive::slash## razor-thin blades of ##Function## through ##TargetName##");
}
