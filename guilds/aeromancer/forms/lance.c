//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/constructedResearchComponent.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Lance Form");
    addSpecification("source", "aeromancer");

    addSpecification("description", "This research provides the user with the "
        "knowledge of creating spells that form a piercing, concentrated stream "
        "of energy to impale a foe.");

    addPrerequisite("/guilds/aeromancer/forms/root.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Constructed Spell Multiplier": 25,
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("additional cooldown", 14);
    addSpecification("additional spell point cost", 22);

    addSpecification("use combination message", 
        "##InitiatorName## ##Infinitive::drive## a lance of ##Function## through ##TargetName##.");
}
