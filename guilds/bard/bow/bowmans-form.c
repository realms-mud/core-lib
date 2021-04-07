//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Bowman's Form");
    addSpecification("source", "bard");
    addSpecification("description", "This skill provides the user with the "
        "knowledge to decrease the cost for which they can use their "
        "offensive abilities.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "bard",
            "value": 16
        ]));
    addPrerequisite("guilds/bard/bow/rhythmic-release.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "The Archer's Song": 10,
        "The Arrow's Anthem": 10,
        "Sonic Volley": 10,
    ]));
    addSpecification("affected research type", "decrease cost");
}
