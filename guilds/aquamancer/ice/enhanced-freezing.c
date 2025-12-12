//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Enhanced Freezing");
    addSpecification("source", "aquamancer");
    addSpecification("description", "This skill provides the user with "
        "superior knowledge of freezing techniques that further enhances the "
        "aquamancer's ice-based abilities.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "aquamancer",
            "value": 39
        ]));

    addPrerequisite("/guilds/aquamancer/ice/cryogenic-induction.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Chill": 25,
        "Freezing Mist": 25,
        "Freezing Wave": 25,
        "Frost Blades": 25,
        "Frost Discharge": 25,
        "Frost Snap": 25,
        "Frozen Swarm": 25,
        "Hailstorm": 25,
        "Ice Bolt": 25,
        "Ice Lash": 25,
        "Ice Shards": 25,
        "Ice Whip": 25,
        "Raging Blizzard": 25,
    ]));
    addSpecification("affected research type", "percentage");
}
