//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/shopInventories/baseShop.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    name("The Dagger Smith");
    welcomeMessage("Welcome to the dagger smith's shop");
    shopType("weapons");
    shopSubType("daggers");
}
