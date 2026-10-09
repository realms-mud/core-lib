//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Inevitable End");
    addSpecification("source", "Disciple of Argloth");
    addSpecification("description", "This research teaches the Disciple to "
        "shape death magic toward an unavoidable conclusion, strengthening "
        "the Killing Word.");

    addPrerequisite(
        "/guilds/disciple-of-argloth/death/scythe-of-argloth.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level",
            "guild": "Disciple of Argloth",
            "value": 50
        ]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research type", "percentage");
    addSpecification("affected research", ([
        "Killing Word": 10
    ]));
}
