//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/constructedResearchComponent.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Blast Form");
    addSpecification("source", "aeromancer");

    addSpecification("description", "This research provides the user with the "
        "knowledge of creating spells that unleash a concentrated blast of energy at a foe.");

    addPrerequisite("/guilds/aeromancer/forms/root.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Constructed Spell Multiplier":22,
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("additional cooldown", 14);
    addSpecification("additional spell point cost", 18);

    addSpecification("use combination message", "##Infinitive::unleash## a blast of "
        "energy at ##TargetName##");
}
