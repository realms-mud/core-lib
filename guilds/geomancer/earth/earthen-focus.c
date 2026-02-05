//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Earthen Focus");
    addSpecification("source", "geomancer");
    addSpecification("description", "This research provides the user with "
        "knowledge of how to focus earthen energy more effectively, "
        "enhancing the power of mud and debris-based attacks.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "geomancer",
            "value": 7
        ]));

    addPrerequisite("/guilds/geomancer/earth/mudslide.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Mudslide": 25,
        "Landslide": 25,
        "Stalagmite": 25,
        "Eruption": 25,
    ]));
    addSpecification("affected research type", "percentage");
}
