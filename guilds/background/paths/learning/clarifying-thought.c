//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Clarifying Thought");
    addSpecification("source", "background");
    addSpecification("description",
        "Your mind is quick to clear confusion, enhancing your ability to "
        "restore mental energy.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addPrerequisite("/guilds/background/paths/learning/mental-refresh.c",
        (["type":"research"]));

    addSpecification("affected research", ([
        "Mental Refresh":5
    ]));
    addSpecification("affected research type", "bonus");
}
