//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/constructedResearchComponent.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Pulse Form");
    addSpecification("source", "aeromancer");

    addSpecification("description", "This research provides the user with the "
        "knowledge of creating spells that emit radiating pulses of energy "
        "that strike foes in rapid succession.");

    addPrerequisite("/guilds/aeromancer/forms/root.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Constructed Spell Multiplier": 32,
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("additional cooldown", 22);
    addSpecification("additional spell point cost", 38);
    addSpecification("additional repeat effect", 3);

    addSpecification("use combination message", 
        "##InitiatorName## ##Infinitive::emit## pulsing waves of ##Function## that hammer ##TargetName##.");
    addSpecification("repeated combination message",
        "Another pulse of ##Function## slams into ##TargetName##.");
}
