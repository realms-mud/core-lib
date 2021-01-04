//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/shopInventories/baseShop.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    name("The Mage Emporium");
    welcomeMessage("Welcome to the Mage Emporium");
    shopType("weapons");

    setRandomItemsToGenerate(40);
    addInventoryItem("weapons", "staffs", ({ "rod", "staff", "wand", 
        "ornate staff" }));
    addInventoryItem("weapons", "daggers", ({ "athame", "dagger" }));

    addInventoryItem("armor", "accessories", ({ "bracers", "amulet", "hat",
        "ring", "circlet" }));
    addInventoryItem("armor", "clothing", ({ "robes", "ornate robes" }));
}
