//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/constructedResearchComponent.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Eruption Form");
    addSpecification("source", "aeromancer");

    addSpecification("description", "This research provides the user with the "
        "knowledge of creating spells that cause a violent eruption of energy beneath a foe.");

    addPrerequisite("/guilds/aeromancer/forms/orb.c",
        (["type":"research"]));
    addPrerequisite("level",
        ([
            "type":"level",
            "guild":"aeromancer",
            "value":15
        ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Constructed Spell Multiplier":28,
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("additional cooldown", 18);
    addSpecification("additional spell point cost", 28);

    addSpecification("use combination message", 
        "##InitiatorName## ##Infinitive::cause## an eruption of ##Function## beneath ##TargetName##.");
}
