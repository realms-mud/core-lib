//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
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
    addPrerequisite("/lib/instances/research/crafting/materials/craftPreciousMetal.c", (["type":"research"]));
}
