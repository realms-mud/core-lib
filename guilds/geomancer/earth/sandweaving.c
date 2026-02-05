//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Sandweaving");
    addSpecification("source", "geomancer");
    addSpecification("description", "This research provides the user with "
        "knowledge of how to weave sand and fine particles into more potent "
        "attacks, enhancing the power of mud and debris-based spells.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "geomancer",
            "value": 9
        ]));

    addPrerequisite("/guilds/geomancer/earth/mudslide.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Mudslide": 25,
        "Landslide": 25,
        "Dust Shroud": 25,
        "Dust Storm": 25,
    ]));
    addSpecification("affected research type", "percentage");
}
