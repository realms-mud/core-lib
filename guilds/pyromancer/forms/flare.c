//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/constructedResearchComponent.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Flare Form");
    addSpecification("source", "pyromancer");

    addSpecification("description", "This research provides the user with the "
        "knowledge of creating spells that flare fire toward a foe.");

    addPrerequisite("/guilds/pyromancer/forms/root.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Constructed Spell Multiplier": 10,
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("additional cooldown", 4);
    addSpecification("additional spell point cost", 6);

    addSpecification("use combination message", 
        "##InitiatorName## ##Infinitive::flare## ##Function## at ##TargetName##.");
}
