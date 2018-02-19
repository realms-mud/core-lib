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
        addSpecification("name", "Dexterity Enchantments");
        addSpecification("source", "enchanting");
        addSpecification("description", "This skill provides the user with the "
            "knowledge required to imbue items with dexterity enchantments.");
        addSpecification("research type", "granted");
        addPrerequisite("lib/instances/research/crafting/enchantments/craftEnchantments.c", (["type":"research"]));
    }
}

