//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/constructedResearchComponent.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Orb Form");
    addSpecification("source", "aeromancer");

    addSpecification("description", "This research provides the user with the "
        "knowledge of creating spells that conjure an orb of energy and launch it at a foe.");

    addPrerequisite("/guilds/aeromancer/forms/blast.c",
        (["type":"research"]));
    addPrerequisite("level",
        ([
            "type":"level",
            "guild":"aeromancer",
            "value":11
        ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Constructed Spell Multiplier":24,
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("additional cooldown", 16);
    addSpecification("additional spell point cost", 22);

    addSpecification("use combination message", 
        "##InitiatorName## ##Infinitive::hurl## an orb of ##Function## at ##TargetName##.");
}
