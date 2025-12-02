//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/shopInventories/baseShop.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    name("The Jeweler");
    welcomeMessage("Welcome to the jeweler's shop");
    shopType("armor");
    shopSubType("accessories");
    setRandomItemsToGenerate(20);
}
