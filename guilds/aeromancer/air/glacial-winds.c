//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Glacial Winds");
    addSpecification("source", "aeromancer");
    addSpecification("description", "This research allows the aeromancer to "
        "tap into winds from the most frigid reaches of the world - the peaks "
        "of frozen mountains and the hearts of glaciers. These glacial winds "
        "carry cold so intense that it can freeze flesh solid, dramatically "
        "enhancing cold-based attacks.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "aeromancer",
            "value": 27
        ]));

    addPrerequisite("/guilds/aeromancer/air/icy-convergence.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Arctic Blast": 25,
        "Hurricane": 25,
    ]));
    addSpecification("affected research type", "percentage");
}
