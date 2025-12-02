//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/constructedResearchComponent.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Air Damage");
    addSpecification("source", "aeromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of creating spells that damage targets with cutting or buffeting air.");

    addPrerequisite("/guilds/aeromancer/functions/root.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("damage type", "air");

    addSpecification("affected research", ([
        "Constructed Spell Multiplier":10,
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("additional cooldown", 3);
    addSpecification("additional spell point cost", 6);

    addSpecification("use combination message", "##Infinitive::blast## air");
}
