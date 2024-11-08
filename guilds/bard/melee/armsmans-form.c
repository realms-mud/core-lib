//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Armsman's Form");
    addSpecification("source", "bard");
    addSpecification("description", "This skill provides the user with the "
        "knowledge to decrease the cost for which they can use their "
        "`Melee's Melody' and `Minstrel's Attack' abilities.");

    addPrerequisite("level",
        (["type":"level",
            "guild": "bard",
            "value": 16
        ]));
    addPrerequisite("/guilds/bard/melee/rhythmic-riposte.c",
        (["type":"research"]));

    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("affected research", ([
        "Melee's Melody": 5,
        "Minstrel's Attack": 10,
        "Dirge of Destruction": 10,
    ]));
    addSpecification("affected research type", "decrease cost");
}
