//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/constructedResearchComponent.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Spear Form");
    addSpecification("source", "geomancer");

    addSpecification("description", "This research provides the user with the "
        "knowledge of creating spells that form a piercing spear of stone.");

    addPrerequisite("/guilds/geomancer/forms/blade.c",
        (["type":"research"]));
    addPrerequisite("level",
        ([
            "type": "level",
            "guild": "geomancer",
            "value": 7
        ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Constructed Spell Multiplier": 22,
    ]));
    addSpecification("affected research type", "percentage");

    addSpecification("additional cooldown", 9);
    addSpecification("additional spell point cost", 16);

    addSpecification("use combination message", 
        "##InitiatorName## ##Infinitive::impale## ##TargetName## with a spear of ##Function##.");
}
