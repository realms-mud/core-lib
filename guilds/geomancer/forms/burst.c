//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/constructedResearchComponent.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Burst Form");
    addSpecification("source", "geomancer");

    addSpecification("description", "This research provides the user with the "
        "knowledge of creating spells that burst stone energy at a foe.");

    addPrerequisite("/guilds/geomancer/forms/root.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Constructed Spell Multiplier": 8,
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("additional cooldown", 3);
    addSpecification("additional spell point cost", 6);

    addSpecification("use combination message", 
        "##InitiatorName## ##Infinitive::burst## ##Function## at ##TargetName##.");
}
