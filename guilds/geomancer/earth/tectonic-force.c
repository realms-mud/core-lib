//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Tectonic Force");
    addSpecification("source", "geomancer");
    addSpecification("description", "This research provides the user with "
        "deeper understanding of tectonic forces, enhancing the power of "
        "area-based earth attacks.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "geomancer",
            "value": 11
        ]));

    addPrerequisite("/guilds/geomancer/earth/quake.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Quake": 25,
        "Landslide": 25,
        "Great Quake": 25,
        "Cataclysm": 25,
    ]));
    addSpecification("affected research type", "percentage");
}
