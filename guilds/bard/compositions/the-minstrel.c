//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "The Minstrel");
    addSpecification("source", "bard");
    addSpecification("description", "This provides the user with "
        "a keen knowledge of their performing prowess, providing an "
        "increase to the speed at which they can begin their next "
        "performance.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "bard",
            "value": 13
        ]));
    addPrerequisite("/guilds/bard/compositions/the-inner-muse.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Musical Compositions": 10
    ]));
    addSpecification("affected research type", "decrease cooldown");
}
