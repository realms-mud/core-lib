//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Air Enchantments");
    addSpecification("source", "enchanting");
    addSpecification("description", "This skill provides the user with the "
        "knowledge required to imbue items with air enchantments.");
    addSpecification("research type", "granted");
    addPrerequisite("lib/instances/research/crafting/enchantments/craftEnchantments.c", 
        (["type":"research"]));
}
