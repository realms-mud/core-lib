//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Requiem of the Quick Draw");
    addSpecification("source", "bard");
    addSpecification("description", "This skill provides the user with the "
        "knowledge to increase the speed with which they can use their "
        "offensive abilities.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "bard",
            "value": 19
        ]));
    addPrerequisite("/guilds/bard/bow/song-of-the-swift.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "The Archer's Song": 10,
        "The Arrow's Anthem": 10,
        "Sonic Volley": 10,
    ]));
    addSpecification("affected research type", "decrease cooldown");
}
