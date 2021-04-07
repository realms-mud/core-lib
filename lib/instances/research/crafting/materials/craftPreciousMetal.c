//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Craft Using Precious Metals");
    addSpecification("source", "crafting");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to craft items using precious metals such as gold or silver.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addPrerequisite("lib/instances/research/crafting/materials/craftRareMetal.c", (["type":"research"]));
}
