//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Spell Mastery");
    addSpecification("source", "geomancer");
    addSpecification("description", "This research teaches the geomancer true "
        "mastery of spell construction, resulting in tremendously potent effects.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "geomancer",
            "value": 33
        ]));
    addPrerequisite("/guilds/geomancer/construct/spell-amplification.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Constructed Geomancer Spells": 15,
    ]));
    addSpecification("affected research type", "percentage");
}
