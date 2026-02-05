//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Earthen Convergence");
    addSpecification("source", "geomancer");
    addSpecification("description", "This research provides the user with "
        "advanced knowledge of how earth energies converge, enhancing the "
        "power of sand and debris-based attacks.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "geomancer",
            "value": 17
        ]));

    addPrerequisite("/guilds/geomancer/earth/sandweaving.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Mudslide": 25,
        "Landslide": 25,
        "Dust Storm": 25,
        "Corrosive Grit": 25,
    ]));
    addSpecification("affected research type", "percentage");
}
