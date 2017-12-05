//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#include "/lib/include/itemFormatters.h"

/////////////////////////////////////////////////////////////////////////////
public nomask mapping getTopLevelCraftingMenu(object user)
{
    return ([
        "1":([
            "name":"Craft Armor and Clothing",
                "description" : "This option lets you create armors, provided that you have\n"
                "the proper materials and equipment on hand.\n",
                "selector" : "craftArmorSelector.c",
                "canShow" : user->canApplyResearchBonus(
                    "lib/instances/research/crafting/craftArmor.c", "armorer")                  
        ]),
        "2":([
            "name":"Craft Jewelry and Artwork",
                "description" : "This option lets you create jewelry and artwork, provided that you have\n"
                "the proper materials and equipment on hand.\n",
                "selector" : "craftJewelrySelector.c",
                "canShow" : user->canApplyResearchBonus(
                    "lib/instances/research/crafting/craftArtwork.c", "gem crafting")                  
        ]),
        "3":([
            "name":"Craft Musical Instrument",
                "description" : "This option lets you create musical instruments, provided that you have\n"
                "the proper materials and equipment on hand.\n",
                "selector" : "craftInstrumentSelector.c",
                "canShow" : user->canApplyResearchBonus(
                    "lib/instances/research/crafting/craftInstrument.c", "luthiery")                  
        ]),
        "4":([
            "name":"Craft Weapons",
                "description" : "This option lets you create weapons, provided that you have\n"
                "the proper materials and equipment on hand.\n",
                "selector" : "craftWeaponSelector.c",
                "canShow" : user->canApplyResearchBonus(
                    "lib/instances/research/crafting/craftWeapons.c", "weapon smithing")                  
        ]),
        "5":([
            "name":"Brew Potions",
                "description" : "This option lets you brew potions, provided that you have\n"
                "the proper materials and equipment on hand.\n",
                "selector" : "brewPotionSelector.c",
                "canShow" : user->canApplyResearchBonus(
                    "lib/instances/research/crafting/brewPotions.c", "brewing")                  
        ]),
        "6":([
            "name":"Brew Beverages and Prepare Food",
                "description" : "This option lets you brew beverages and prepare food, provided that you have\n"
                "the proper materials and equipment on hand.\n",
                "selector" : "brewBeverageSelector.c",
                "canShow" : user->canApplyResearchBonus(
                    "lib/instances/research/crafting/brewBeveragesAndCookFood.c", "cooking")                  
        ]),
        "7":([
            "name":"Refine Materials",
                "description" : "This option lets you refine/repurpose materials, provided that you have\n"
                "the proper equipment on hand.\n",
                "selector" : "refineMaterialsSelector.c",
                "canShow" : 1                 
        ]),
        "8":([
            "name":"Imbue Materials with Magical Effects",
                "description" : "This option lets you imbue crafting materials with magical effect,\n"
                "provided that you have the proper materials and knowledge on hand.\n",
                "selector" : "imbueMagicSelector.c",
                "canShow" : user->getSkill("spellcraft")
        ]),
    ]);
}
