//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Foundation of Practice");
    addSpecification("source", "monk");
    addSpecification("description",
        "The monastic path begins with patient repetition "
        "and an honest regard for one's limits. Each "
        "day's practice offers another chance to meet them without pride.");


    addSpecification("research type", "tree root");
}
