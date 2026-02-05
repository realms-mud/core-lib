//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/constructedResearchComponent.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Avalanche Form");
    addSpecification("source", "geomancer");

    addSpecification("description", "This research provides the user with the "
        "knowledge of creating spells that unleash a devastating avalanche "
        "of stone and debris.");

    addPrerequisite("/guilds/geomancer/forms/strike.c",
        (["type":"research"]));
    addPrerequisite("level",
        ([
            "type": "level",
            "guild": "geomancer",
            "value": 21
        ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Constructed Spell Multiplier": 44,
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("additional cooldown", 30);
    addSpecification("additional spell point cost", 50);

    addSpecification("use combination message", 
        "##InitiatorName## ##Infinitive::unleash## an avalanche of "
        "##Function## upon ##TargetName##.");
}
