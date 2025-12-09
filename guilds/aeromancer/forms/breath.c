//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/constructedResearchComponent.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Breath Form");
    addSpecification("source", "aeromancer");

    addSpecification("description", "This research provides the user with the "
        "knowledge of creating spells that exhale a cone-shaped burst of "
        "energy at nearby foes.");

    addPrerequisite("/guilds/aeromancer/forms/root.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Constructed Spell Multiplier": 17,
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("additional cooldown", 8);
    addSpecification("additional spell point cost", 12);

    addSpecification("use combination message", 
        "##InitiatorName## ##Infinitive::exhale## a cone of ##Function## at ##TargetName##.");
}
