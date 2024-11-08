//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Weapon Master's Tale");
    addSpecification("source", "bard");
    addSpecification("description", "This skill provides the user with "
        "bardic knowledge that enhances the bard's `Melee's Melody' and "
        "`Minstrel's Attack' abilities.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "bard",
            "value": 33
        ]));
    addPrerequisite("/guilds/bard/melee/footmans-ballad.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Melee's Melody": 25,
        "Minstrel's Attack": 25,
        "Dirge of Destruction": 25,
    ]));
    addSpecification("affected research type", "percentage");
}
