//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Grandmaster Efficiency");
    addSpecification("source", "geomancer");
    addSpecification("description", "This skill provides the user with grandmaster "
        "knowledge to increase the speed with which they can cast their "
        "constructed spells.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "geomancer",
            "value": 37
        ]));
    addPrerequisite("/guilds/geomancer/construct/master-efficiency.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Constructed Geomancer Spells": 5,
    ]));
    addSpecification("affected research type", "decrease cooldown");
}
