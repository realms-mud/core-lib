//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Mental Vigor");
    addSpecification("source", "background");
    addSpecification("description",
        "Your mental stamina allows you to recover more energy when using "
        "Mental Refresh.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addPrerequisite("/guilds/background/paths/learning/clarifying-thought.c",
        (["type":"research"]));

    addSpecification("affected research", ([
        "Mental Refresh":5
    ]));
    addSpecification("affected research type", "bonus");
}
