//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/constructedResearchComponent.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Strike Form");
    addSpecification("source", "geomancer");

    addSpecification("description", "This research provides the user with the "
        "knowledge of creating spells that deliver devastating strikes of stone.");

    addPrerequisite("/guilds/geomancer/forms/lance.c",
        (["type":"research"]));
    addPrerequisite("level",
        ([
            "type": "level",
            "guild": "geomancer",
            "value": 15
        ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Constructed Spell Multiplier": 36,
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("additional cooldown", 22);
    addSpecification("additional spell point cost", 38);

    addSpecification("use combination message", 
        "##InitiatorName## ##Infinitive::strike## ##TargetName## with ##Function##.");
}
