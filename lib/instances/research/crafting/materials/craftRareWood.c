//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Craft Rare Wood");
    addSpecification("source", "crafting");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to craft items using uncommon wood such as "
        "purple heart or koa.");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addPrerequisite("/lib/instances/research/crafting/materials/craftUncommonWood.c", (["type":"research"]));
}
