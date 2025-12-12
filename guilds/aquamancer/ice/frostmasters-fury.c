//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Frostmaster's Fury");
    addSpecification("source", "aquamancer");
    addSpecification("description", "This skill provides the user with the "
        "knowledge to further decrease the spell point cost for which they "
        "can use their ice attack abilities.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "aquamancer",
            "value": 41
        ]));
    addPrerequisite("/guilds/aquamancer/ice/frostmasters-might.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Freezing Mist": 10,
        "Freezing Wave": 10,
        "Frost Discharge": 10,
        "Hailstorm": 10,
        "Ice Bolt": 10,
        "Ice Whip": 10,
        "Raging Blizzard": 10,
        "Frozen Swarm": 10,
    ]));
    addSpecification("affected research type", "decrease cost");
}
