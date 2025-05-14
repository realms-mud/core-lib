//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/constructedResearchComponent.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Ball Form");
    addSpecification("source", "aeromancer");

    addSpecification("description", "This research provides the user with the "
        "knowledge of creating spells that form a ball of energy and hurl it "
        "at a foe.");

    addPrerequisite("/guilds/aeromancer/forms/root.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Constructed Spell Multiplier":20,
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("additional cooldown", 12);
    addSpecification("additional spell point cost", 20);

    addSpecification("use combination message", "##Infinitive::hurl## a ball of "
        "energy at ##TargetName##");
}
