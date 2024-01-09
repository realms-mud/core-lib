//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Craft Using Mythic Metals");
    addSpecification("source", "crafting");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to craft items using extremely rare metals such as admantite or mithril.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addPrerequisite("/lib/instances/research/crafting/materials/craftMythicMetal.c", (["type":"research"]));
    addPrerequisite("/lib/instances/research/crafting/materials/craftMythicGems.c", (["type":"research"]));
}
