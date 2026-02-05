//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Molten Depths");
    addSpecification("source", "geomancer");
    addSpecification("description", "This research provides the user with "
        "knowledge of the molten depths beneath the earth, enhancing the "
        "power of debris and heat-based attacks.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "geomancer",
            "value": 27
        ]));

    addPrerequisite("/guilds/geomancer/earth/earthen-convergence.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Mudslide": 25,
        "Landslide": 25,
        "Corrosive Grit": 25,
        "Eruption": 25,
    ]));
    addSpecification("affected research type", "percentage");
}
