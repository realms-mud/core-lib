//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/constructedResearchComponent.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Vacuum Damage");
    addSpecification("source", "aeromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of creating spells that damage targets by creating a vacuum.");

    addPrerequisite("/guilds/aeromancer/functions/root.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("damage type", "air");

    addSpecification("affected research", ([
        "Constructed Spell Multiplier":30,
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("additional cooldown", 8);
    addSpecification("additional spell point cost", 14);

    addSpecification("use combination message", "##Infinitive::create## a vacuum");
}
