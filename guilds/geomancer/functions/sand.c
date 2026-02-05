//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/constructedResearchComponent.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Sand Damage");
    addSpecification("source", "geomancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of creating spells that damage targets with abrasive, "
        "scouring sand.");

    addPrerequisite("/guilds/geomancer/functions/gravel.c",
        (["type":"research"]));
    addPrerequisite("level",
        ([
            "type": "level",
            "guild": "geomancer",
            "value": 11
        ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("damage type", "earth");

    addSpecification("affected research", ([
        "Constructed Spell Multiplier": 45,
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("additional cooldown", 10);
    addSpecification("additional spell point cost", 20);

    addSpecification("combination descriptor", "scouring sand");
}
