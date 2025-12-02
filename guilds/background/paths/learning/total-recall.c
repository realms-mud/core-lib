//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Total Recall");
    addSpecification("source", "background");
    addSpecification("description",
        "You can recall information with perfect clarity, further enhancing "
        "your mental restoration.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addPrerequisite("/guilds/background/paths/learning/mental-vigor.c",
        (["type":"research"]));

    addSpecification("affected research", ([
        "Mental Refresh":5
    ]));
    addSpecification("affected research type", "bonus");
}
