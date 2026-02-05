//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/constructedResearchComponent.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Lance Form");
    addSpecification("source", "geomancer");

    addSpecification("description", "This research provides the user with the "
        "knowledge of creating spells that form a devastating lance of stone.");

    addPrerequisite("/guilds/geomancer/forms/spear.c",
        (["type":"research"]));
    addPrerequisite("level",
        ([
            "type": "level",
            "guild": "geomancer",
            "value": 13
        ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Constructed Spell Multiplier": 32,
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("additional cooldown", 18);
    addSpecification("additional spell point cost", 30);

    addSpecification("use combination message", 
        "##InitiatorName## ##Infinitive::pierce## ##TargetName## with a lance of ##Function##.");
}
