//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Frost Veil");
    addSpecification("source", "aeromancer");
    addSpecification("description", "This research teaches the aeromancer to "
        "shroud their cold magic in a veil of supercooled air that preserves "
        "and intensifies the freezing effect. Cold attacks wrapped in this veil "
        "maintain their lethal temperatures longer and penetrate magical and "
        "physical defenses more effectively.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "aeromancer",
            "value": 47
        ]));

    addPrerequisite("/guilds/aeromancer/air/freezing-tide.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Arctic Blast": 25,
        "Hurricane": 25,
    ]));
    addSpecification("affected research type", "percentage");
}
