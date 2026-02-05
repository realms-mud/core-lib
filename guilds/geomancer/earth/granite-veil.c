//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Granite Veil");
    addSpecification("source", "geomancer");
    addSpecification("description", "This research provides the user with "
        "knowledge of the granite veil, further enhancing debris and "
        "pressure-based attacks.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "geomancer",
            "value": 47
        ]));

    addPrerequisite("/guilds/geomancer/earth/crushing-weight.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Mudslide": 25,
        "Landslide": 25,
        "Corrosive Grit": 25,
        "Eruption": 25,
        "Entombing Depths": 25,
        "Entombing Embrace": 25,
        "Abyssal Stone": 25,
    ]));
    addSpecification("affected research type", "percentage");
}
