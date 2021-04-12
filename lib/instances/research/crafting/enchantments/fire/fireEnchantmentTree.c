//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Fire Enchantment Tree");
    Description("This research tree tracks the knowledge required to enchant items with fire enchantments");
    Source("enchanting");
    addPrerequisite("spellcraft", (["type":"skill", "value" : 5]));
    addPrerequisite("elemental fire", (["type":"skill", "value" : 5]));
    addPrerequisite("/lib/instances/research/crafting/enchantments/craftEnchantments.c", (["type":"research"]));
    addResearchElement("/lib/instances/research/crafting/enchantments/fire/craftFireEnchantment.c");
    TreeRoot("/lib/instances/research/crafting/enchantments/fire/craftFireEnchantment.c");
}
