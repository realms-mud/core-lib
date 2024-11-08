//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Lay of the Archer");
    addSpecification("source", "bard");
    addSpecification("description", "This skill provides the user with "
        "bardic knowledge that enhances the bard's offensive abilities.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "bard",
            "value": 37
        ]));
    addPrerequisite("/guilds/bard/bow/bowmans-tale.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "The Archer's Song": 50,
        "The Arrow's Anthem": 50,
        "Sonic Volley": 25,
    ]));
    addSpecification("affected research type", "percentage");
}
