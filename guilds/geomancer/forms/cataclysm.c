//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/constructedResearchComponent.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Cataclysm Form");
    addSpecification("source", "geomancer");

    addSpecification("description", "This research provides the user with the "
        "knowledge of creating spells that unleash catastrophic destruction.");

    addPrerequisite("/guilds/geomancer/forms/quake.c",
        (["type":"research"]));
    addPrerequisite("level",
        ([
            "type": "level",
            "guild": "geomancer",
            "value": 23
        ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Constructed Spell Multiplier": 50,
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("additional cooldown", 35);
    addSpecification("additional spell point cost", 60);

    addSpecification("use combination message", 
        "##InitiatorName## ##Infinitive::unleash## a cataclysm of "
        "##Function## upon ##TargetName##.");
}
