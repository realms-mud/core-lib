//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        knowledgeResearchItem::reset(arg);
        addSpecification("name", "Craft Scale Armor");
        addSpecification("source", "crafting");
        addSpecification("description", "This skill provides the user with the "
            "knowledge required to craft scale armor.");
        addSpecification("research type", "granted");
        addPrerequisite("lib/instances/research/crafting/armor/craftHeavyArmor.c", (["type":"research"]));
        addPrerequisite("armorer", (["type":"skill", "value" : 9]));
    }
}
