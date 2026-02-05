//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Disrupt Seismic");
    addSpecification("source", "geomancer");
    addSpecification("description", "This research provides the user with "
        "the ability to disrupt seismic patterns more efficiently, reducing "
        "the cooldown of powerful area attacks.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "geomancer",
            "value": 33
        ]));

    addPrerequisite("/guilds/geomancer/earth/great-quake.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Quake": 15,
        "Landslide": 15,
        "Great Quake": 15,
        "Eruption": 15,
        "Cataclysm": 15,
    ]));
    addSpecification("affected research type", "decrease cooldown");
}
