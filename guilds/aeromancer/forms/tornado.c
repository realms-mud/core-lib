//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/constructedResearchComponent.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Tornado Form");
    addSpecification("source", "aeromancer");

    addSpecification("description", "This research provides the user with the "
        "knowledge of creating spells that unleash a massive, spiraling tornado "
        "of devastating energy.");

    addPrerequisite("/guilds/aeromancer/forms/root.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Constructed Spell Multiplier": 45,
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("additional cooldown", 30);
    addSpecification("additional spell point cost", 50);

    addSpecification("use combination message", 
        "##Infinitive::unleash## a devastating tornado of ##Function## upon ##TargetName##");
}
