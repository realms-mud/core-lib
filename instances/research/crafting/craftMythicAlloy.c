//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        knowledgeResearchItem::reset(arg);
        addSpecification("name", "Craft Using Mythic Metals");
        addSpecification("description", "This skill provides the user with the "
            "knowledge required to craft items using extremely rare metals such as admantite or mithril.");
        addSpecification("research type", "points");
        addSpecification("research cost", 1);
        addPrerequisite("lib/instances/research/crafting/craftMythicMetal.c", (["type":"research"]));
        addPrerequisite("lib/instances/research/crafting/craftMythicGems.c", (["type":"research"]));
    }
}

