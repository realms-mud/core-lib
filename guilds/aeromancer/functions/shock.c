//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/constructedResearchComponent.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Shock Damage");
    addSpecification("source", "aeromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of creating spells that damage targets by discharging "
        "an electrical shock.");

    addPrerequisite("/guilds/aeromancer/functions/root.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("damage type", "electricity");

    addSpecification("affected research", ([
        "Constructed Spell Multiplier": 5,
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("additional cooldown", 2);
    addSpecification("additional spell point cost", 5);

    addSpecification("use combination message", "##Infinitive::discharge## "
        "static electricity");
}
