//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Spell Amplification");
    addSpecification("source", "aeromancer");
    addSpecification("description", "This research teaches advanced techniques "
        "for amplifying the raw magical output of constructed spells, greatly "
        "enhancing their overall effectiveness.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "aeromancer",
            "value": 25
        ]));
    addPrerequisite("/guilds/aeromancer/construct/enhanced-focus.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Constructed Aeromancer Spells": 15,
    ]));
    addSpecification("affected research type", "percentage");
}
