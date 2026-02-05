//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Spell Perfection");
    addSpecification("source", "geomancer");
    addSpecification("description", "This research teaches the geomancer the "
        "pinnacle of spell construction, resulting in perfectly optimized effects.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "geomancer",
            "value": 49
        ]));
    addPrerequisite("/guilds/geomancer/construct/arcane-precision.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Constructed Geomancer Spells": 20,
    ]));
    addSpecification("affected research type", "percentage");
}
