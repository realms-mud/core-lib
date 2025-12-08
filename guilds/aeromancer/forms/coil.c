//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/constructedResearchComponent.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Coil Form");
    addSpecification("source", "aeromancer");

    addSpecification("description", "This research provides the user with the "
        "knowledge of creating spells that form spiraling coils of energy "
        "that wrap around and repeatedly strike a foe.");

    addPrerequisite("/guilds/aeromancer/forms/root.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Constructed Spell Multiplier": 28,
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("additional cooldown", 18);
    addSpecification("additional spell point cost", 30);

    addSpecification("use combination message", 
        "##Infinitive::ensnare## ##TargetName## in coiling tendrils of ##Function##");
}
