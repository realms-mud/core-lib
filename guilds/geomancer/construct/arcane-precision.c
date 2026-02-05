//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Arcane Precision");
    addSpecification("source", "geomancer");
    addSpecification("description", "This research teaches the geomancer arcane "
        "precision in spell construction, resulting in devastatingly potent effects.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "geomancer",
            "value": 41
        ]));
    addPrerequisite("/guilds/geomancer/construct/spell-mastery.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Constructed Geomancer Spells": 15,
    ]));
    addSpecification("affected research type", "percentage");
}
