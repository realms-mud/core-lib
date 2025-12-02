//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/constructedResearchComponent.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Spear Form");
    addSpecification("source", "aeromancer");

    addSpecification("description", "This research provides the user with the "
        "knowledge of creating spells that conjure a spear of energy and launch it at a foe.");

    addPrerequisite("/guilds/aeromancer/forms/root.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Constructed Spell Multiplier":20,
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("additional cooldown", 10);
    addSpecification("additional spell point cost", 16);

    addSpecification("use combination message", "##Infinitive::thrust## a spear of "
        "energy at ##TargetName##");
}
