//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Geomantic Insight");
    addSpecification("source", "geomancer");
    addSpecification("description", "This research provides the user with "
        "profound geomantic insight, dramatically enhancing the power of "
        "all earth-based attacks.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "geomancer",
            "value": 57
        ]));

    addPrerequisite("/guilds/geomancer/earth/mountain-mastery.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Tremor": 25,
        "Quake": 25,
        "Fissure": 25,
        "Talons of Earth": 25,
        "Grasping Earth": 25,
        "Battering Stones": 25,
        "Earthmaw": 25,
        "Stalagmite": 25,
        "Upheaval": 25,
        "Daggers of Earth": 25,
        "Eruption": 25,
        "Great Quake": 25,
        "Whirling Stones": 25,
        "Cataclysm": 25,
    ]));
    addSpecification("affected research type", "percentage");
}
