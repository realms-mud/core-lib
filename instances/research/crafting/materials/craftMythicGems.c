//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        knowledgeResearchItem::reset(arg);
        addSpecification("name", "Craft Mythic Gems");
        addSpecification("description", "This skill provides the user with the "
            "knowledge required to craft items using mythic gems such as kirluin and rhudluin.");
        addSpecification("research type", "points");
        addSpecification("research cost", 1);
        addPrerequisite("lib/instances/research/crafting/materials/craftRareGems.c", (["type":"research"]));
    }
}

