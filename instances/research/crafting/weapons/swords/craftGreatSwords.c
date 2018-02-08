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
        addSpecification("name", "Craft Great Swords");
        addSpecification("source", "crafting");
        addSpecification("description", "This skill provides the user with the "
            "knowledge required to craft great swords, claymores, and other large swords out of "
            "typical bladed weapon materials such as iron, bronze, and steel.");
        addSpecification("research type", "granted");
        addPrerequisite("lib/instances/research/crafting/weapons/swords/craftLongSwords.c", (["type":"research"]));
    }
}

