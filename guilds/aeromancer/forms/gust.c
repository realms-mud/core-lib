//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/constructedResearchComponent.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Gust Form");
    addSpecification("source", "aeromancer");

    addSpecification("description", "This research provides the user with the "
        "knowledge of creating spells that release a quick, sudden burst of "
        "force at a foe.");

    addPrerequisite("/guilds/aeromancer/forms/root.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Constructed Spell Multiplier": 8,
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("additional cooldown", 3);
    addSpecification("additional spell point cost", 5);

    addSpecification("use combination message", 
        "##InitiatorName## ##Infinitive::release## a sudden gust of ##Function## at ##TargetName##.");
}
