//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Genius");
    addSpecification("source", "background");
    addSpecification("description",
        "Your intellect is legendary, allowing you to restore even more "
        "mental energy.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);

    addPrerequisite("/guilds/background/paths/learning/total-recall.c",
        (["type":"research"]));

    addSpecification("affected research", ([
        "Mental Refresh":10
    ]));
    addSpecification("affected research type", "bonus");
}
