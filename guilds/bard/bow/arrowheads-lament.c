//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Arrowhead's Lament");
    addSpecification("source", "bard");
    addSpecification("description", "This skill provides the user with "
        "bardic knowledge that enhances the bard's offensive abilities.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "bard",
            "value": 25
        ]));
    addPrerequisite("/guilds/bard/bow/archers-elegy.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "The Archer's Song": 25,
        "The Arrow's Anthem": 25,
        "Sonic Volley": 25,
    ]));
    addSpecification("affected research type", "percentage");
}
