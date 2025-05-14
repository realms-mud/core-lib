//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/constructedResearchComponent.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Blade Form");
    addSpecification("source", "aeromancer");

    addSpecification("description", "This research provides the user with the "
        "knowledge of creating spells that form a blade of energy to strike a foe.");

    addPrerequisite("/guilds/aeromancer/forms/root.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Constructed Spell Multiplier":18,
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("additional cooldown", 8);
    addSpecification("additional spell point cost", 12);

    addSpecification("use combination message", "##Infinitive::slash## a blade of "
        "energy at ##TargetName##");
}
